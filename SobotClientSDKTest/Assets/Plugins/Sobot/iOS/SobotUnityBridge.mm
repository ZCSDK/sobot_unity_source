// SobotUnityBridge.mm
// 智齿 SDK iOS 原生桥接层

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <UserNotifications/UserNotifications.h>
#import <SobotKit/SobotKit.h>

extern "C" void UnitySendMessage(const char* obj, const char* method, const char* msg);

typedef BOOL (*SobotUnityLinkClickCallback)(const char* url);
static SobotUnityLinkClickCallback s_linkClickCallback = nullptr;
typedef void (*SobotUnityFunctionClickCallback)(int type);
static SobotUnityFunctionClickCallback s_functionClickCallback = nullptr;

static NSString* toNSString(const char* str) {
    return str ? [NSString stringWithUTF8String:str] : @"";
}

static void sendUnitySendResultWithNames(NSString *obj, NSString *method, NSString *requestId, NSString *msg, int code) {
    if (obj.length == 0 || method.length == 0) return;

    NSString *safeRequestId = requestId ?: @"";
    NSString *safeMsg = msg ?: @"";
    NSString *payload = [NSString stringWithFormat:@"%@|%d|%@", safeRequestId, code, safeMsg];
    UnitySendMessage([obj UTF8String], [method UTF8String], [payload UTF8String]);
}

static NSDictionary* parseJson(const char* json) {
    NSString *jsonString = toNSString(json);
    if (jsonString.length == 0) return @{};

    NSData *data = [jsonString dataUsingEncoding:NSUTF8StringEncoding];
    if (data == nil) return @{};

    id object = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
    if ([object isKindOfClass:[NSDictionary class]]) {
        return (NSDictionary *)object;
    }
    return @{};
}

static NSString* stringValue(NSDictionary *dict, NSString *key) {
    id value = dict[key];
    if (value == nil || value == [NSNull null]) return @"";
    if ([value isKindOfClass:[NSString class]]) return (NSString *)value;
    if ([value respondsToSelector:@selector(stringValue)]) return [value stringValue];
    return [NSString stringWithFormat:@"%@", value];
}

static int intValue(NSDictionary *dict, NSString *key) {
    id value = dict[key];
    if (value == nil || value == [NSNull null]) return 0;
    if ([value respondsToSelector:@selector(intValue)]) return [value intValue];
    return 0;
}

static BOOL boolValue(NSDictionary *dict, NSString *key) {
    id value = dict[key];
    if (value == nil || value == [NSNull null]) return NO;
    if ([value respondsToSelector:@selector(boolValue)]) return [value boolValue];
    return NO;
}

static BOOL hasValue(NSDictionary *dict, NSString *key) {
    id value = dict[key];
    return value != nil && value != [NSNull null];
}

static NSDictionary* jsonDictValue(NSDictionary *dict, NSString *key) {
    id value = dict[key];
    if ([value isKindOfClass:[NSDictionary class]]) return (NSDictionary *)value;
    if (![value isKindOfClass:[NSString class]]) return nil;

    NSData *data = [(NSString *)value dataUsingEncoding:NSUTF8StringEncoding];
    if (data == nil) return nil;

    id object = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
    return [object isKindOfClass:[NSDictionary class]] ? (NSDictionary *)object : nil;
}

static NSArray* jsonArrayValue(NSDictionary *dict, NSString *key) {
    id value = dict[key];
    if ([value isKindOfClass:[NSArray class]]) return (NSArray *)value;
    if (![value isKindOfClass:[NSString class]]) return nil;

    NSData *data = [(NSString *)value dataUsingEncoding:NSUTF8StringEncoding];
    if (data == nil) return nil;

    id object = [NSJSONSerialization JSONObjectWithData:data options:0 error:nil];
    return [object isKindOfClass:[NSArray class]] ? (NSArray *)object : nil;
}

static UIViewController* topViewController() {
    UIViewController *vc = [UIApplication sharedApplication].keyWindow.rootViewController;
    while (vc.presentedViewController) {
        vc = vc.presentedViewController;
    }
    return vc;
}

static void setStringIfPresent(void (^setter)(NSString *), NSDictionary *params, NSString *key) {
    NSString *value = stringValue(params, key);
    if (value.length > 0) setter(value);
}

static SobotChatCustomCardMenu* buildCustomCardMenu(NSDictionary *dict) {
    SobotChatCustomCardMenu *menu = [SobotChatCustomCardMenu new];
    menu.menuType = intValue(dict, @"menuType");
    menu.menuName = stringValue(dict, @"menuName");
    menu.menuLink = stringValue(dict, @"menuLink");
    menu.menuLinkType = intValue(dict, @"menuLinkType");
    menu.menuTip = stringValue(dict, @"menuTip");
    menu.isUnEnabled = boolValue(dict, @"isDisable");
    setStringIfPresent(^(NSString *v) { menu.menuMiniProgramUrl = v; }, dict, @"menuMiniProgramUrl");
    return menu;
}

static NSMutableArray* buildCustomCardMenus(NSArray *array) {
    NSMutableArray *menus = [NSMutableArray array];
    for (id item in array) {
        if (![item isKindOfClass:[NSDictionary class]]) continue;
        [menus addObject:buildCustomCardMenu((NSDictionary *)item)];
    }
    return menus;
}

static SobotChatCustomCardInfo* buildCustomCardInfo(NSDictionary *dict) {
    SobotChatCustomCardInfo *info = [SobotChatCustomCardInfo new];
    info.sourceDict = dict;
    setStringIfPresent(^(NSString *v) { info.customCardType = v; }, dict, @"customCardType");
    setStringIfPresent(^(NSString *v) { info.customCardStatus = v; }, dict, @"customCardStatus");
    setStringIfPresent(^(NSString *v) { info.customCardCount = v; }, dict, @"customCardCount");
    setStringIfPresent(^(NSString *v) { info.customCardCode = v; }, dict, @"customCardCode");
    setStringIfPresent(^(NSString *v) { info.customCardTime = v; }, dict, @"customCardTime");
    setStringIfPresent(^(NSString *v) { info.customCardId = v; }, dict, @"customCardId");
    setStringIfPresent(^(NSString *v) { info.customCardQuestion = v; }, dict, @"customCardQuestion");
    setStringIfPresent(^(NSString *v) { info.customCardName = v; }, dict, @"customCardName");
    setStringIfPresent(^(NSString *v) { info.customCardThumbnail = v; }, dict, @"customCardThumbnail");
    setStringIfPresent(^(NSString *v) { info.customCardAmount = v; }, dict, @"customCardAmount");
    setStringIfPresent(^(NSString *v) { info.customCardAmountSymbol = v; }, dict, @"customCardAmountSymbol");
    setStringIfPresent(^(NSString *v) { info.customCardLink = v; }, dict, @"customCardLink");
    setStringIfPresent(^(NSString *v) { info.customCardDesc = v; }, dict, @"customCardDesc");
    setStringIfPresent(^(NSString *v) { info.customCardHeader = v; }, dict, @"customCardHeader");

    NSArray *customMenus = dict[@"customMenus"];
    if ([customMenus isKindOfClass:[NSArray class]]) {
        info.customMenus = buildCustomCardMenus(customMenus);
    }

    id customField = dict[@"customField"];
    if ([customField isKindOfClass:[NSArray class]]) {
        info.customField = [(NSArray *)customField mutableCopy];
    } else if ([customField isKindOfClass:[NSDictionary class]]) {
        info.customField = [@[(NSDictionary *)customField] mutableCopy];
    }

    id paramInfos = dict[@"paramInfos"];
    if ([paramInfos isKindOfClass:[NSArray class]]) {
        info.paramInfos = [(NSArray *)paramInfos mutableCopy];
    }

    return info;
}

static SobotChatCustomCard* buildCustomCard(NSDictionary *dict) {
    SobotChatCustomCard *card = [SobotChatCustomCard new];
    card.sourceDict = dict;
    card.cardForm = stringValue(dict, @"cardForm");
    card.cardStyle = intValue(dict, @"cardStyle");
    card.cardType = intValue(dict, @"cardType");
    card.cardId = stringValue(dict, @"cardId");
    card.isCustomerIdentity = intValue(dict, @"isCustomerIdentity");
    card.cardGuide = stringValue(dict, @"cardGuide");
    card.cardImg = stringValue(dict, @"cardImg");
    card.cardDesc = stringValue(dict, @"cardDesc");
    card.cardLink = stringValue(dict, @"cardLink");

    id customField = dict[@"customField"];
    if ([customField isKindOfClass:[NSDictionary class]]) {
        card.customField = (NSDictionary *)customField;
    }

    id ticketPartnerField = dict[@"ticketPartnerField"];
    if ([ticketPartnerField isKindOfClass:[NSDictionary class]]) {
        card.ticketPartnerField = (NSDictionary *)ticketPartnerField;
    }

    NSArray *customCards = dict[@"customCards"];
    if ([customCards isKindOfClass:[NSArray class]]) {
        NSMutableArray *cards = [NSMutableArray array];
        for (id item in customCards) {
            if (![item isKindOfClass:[NSDictionary class]]) continue;
            [cards addObject:buildCustomCardInfo((NSDictionary *)item)];
        }
        card.customCards = cards;
    }

    NSArray *cardMenus = dict[@"cardMenus"];
    if ([cardMenus isKindOfClass:[NSArray class]]) {
        card.cardMenus = buildCustomCardMenus(cardMenus);
    }

    return card;
}

static void applyCustomCard(ZCLibInitInfo *initInfo, NSDictionary *params) {
    NSDictionary *customCardDict = jsonDictValue(params, @"custom_card");
    if (customCardDict == nil) return;

    initInfo.customCard = buildCustomCard(customCardDict);
    if (customCardDict[@"showCustomCardAllMode"] != nil) {
        initInfo.showCustomCardAllMode = boolValue(customCardDict, @"showCustomCardAllMode");
    }
}

static ZCProductInfo* buildProductInfo(NSDictionary *params) {
    NSString *title = stringValue(params, @"goodsTitle");
    NSString *link = stringValue(params, @"goodsLink");
    if ([title length] == 0 || [link length] == 0) {
        return nil;
    }

    ZCProductInfo *productInfo = [ZCProductInfo new];
    productInfo.title = title;
    productInfo.link = link;

    NSString *desc = stringValue(params, @"goodsDesc");
    if ([desc length] > 0) productInfo.desc = desc;

    NSString *label = stringValue(params, @"goodsLabel");
    if ([label length] > 0) productInfo.label = label;

    NSString *thumbUrl = stringValue(params, @"goodsImage");
    if ([thumbUrl length] > 0) productInfo.thumbUrl = thumbUrl;

    return productInfo;
}

static ZCOrderGoodsModel* buildOrderGoodsInfo(NSDictionary *params) {
    NSString *orderCode = stringValue(params, @"orderCode");
    NSString *orderStatus = stringValue(params, @"orderStatus");
    NSString *statusCustom = stringValue(params, @"statusCustom");
    NSString *createTime = stringValue(params, @"createTime");
    NSString *goodsCount = stringValue(params, @"goodsCount");
    NSString *orderUrl = stringValue(params, @"orderUrl");
    NSString *totalFee = stringValue(params, @"totalFee");
    NSArray *goods = jsonArrayValue(params, @"goods");

    if ([orderCode length] == 0 &&
        [orderStatus length] == 0 &&
        [statusCustom length] == 0 &&
        [createTime length] == 0 &&
        [goodsCount length] == 0 &&
        [orderUrl length] == 0 &&
        [totalFee length] == 0 &&
        [goods count] == 0) {
        return nil;
    }

    ZCOrderGoodsModel *orderInfo = [ZCOrderGoodsModel new];
    if ([orderStatus length] > 0) orderInfo.orderStatus = intValue(params, @"orderStatus");
    if ([statusCustom length] > 0) orderInfo.statusCustom = statusCustom;
    if ([orderCode length] > 0) orderInfo.orderCode = orderCode;
    if ([createTime length] > 0) orderInfo.createTime = createTime;
    if ([goods count] > 0) orderInfo.goods = goods;
    if ([orderUrl length] > 0) orderInfo.orderUrl = orderUrl;
    if ([goodsCount length] > 0) orderInfo.goodsCount = goodsCount;
    if ([totalFee length] > 0) orderInfo.totalFee = totalFee;

    return orderInfo;
}

static NSDictionary* buildLocationDict(NSDictionary *params) {
    NSString *lat = stringValue(params, @"lat");
    NSString *lng = stringValue(params, @"lng");
    if ([lat length] == 0 || [lng length] == 0) {
        return nil;
    }

    NSMutableDictionary *locations = [NSMutableDictionary dictionary];
    locations[@"lat"] = lat;
    locations[@"lng"] = lng;
    locations[@"localLabel"] = stringValue(params, @"localLabel");
    locations[@"localName"] = stringValue(params, @"localName");
    locations[@"file"] = stringValue(params, @"file");

    return locations;
}

static void registerMessageLinkClickHandler() {
    if (s_linkClickCallback == nullptr) {
        return;
    }

    [ZCSobotApi setMessageLinkClick:^BOOL(ZCLinkClickType type, NSString * _Nonnull linkUrl, id _Nullable object) {
        NSString *safeLinkUrl = linkUrl ?: @"";
        NSLog(@"[SobotUnityBridge] message link click type=%ld url=%@", (long)type, safeLinkUrl);

        BOOL handled = s_linkClickCallback([safeLinkUrl UTF8String]);
        NSLog(@"[SobotUnityBridge] Unity link click handled=%d url=%@", handled ? 1 : 0, safeLinkUrl);
        return handled;
    }];

    NSLog(@"[SobotUnityBridge] message link click handler registered");
}

static void registerFunctionClickHandler() {
    if (s_functionClickCallback == nullptr) {
        return;
    }

    [ZCSobotApi setFunctionClickListener:^(id currentVC, ZCPageCloseType type) {
        NSLog(@"[SobotUnityBridge] function click type=%ld", (long)type);
        s_functionClickCallback((int)type);
    }];

    NSLog(@"[SobotUnityBridge] function click handler registered");
}

static void requestLocalNotificationPermission() {
    UNAuthorizationOptions options = UNAuthorizationOptionAlert | UNAuthorizationOptionSound | UNAuthorizationOptionBadge;
    [[UNUserNotificationCenter currentNotificationCenter] requestAuthorizationWithOptions:options completionHandler:^(BOOL granted, NSError * _Nullable error) {
        if (error != nil) {
            NSLog(@"[SobotUnityBridge] request local notification permission failed: %@", error);
        }
    }];
}

static void applyClientOptions(ZCLibClient *client, NSDictionary *params) {
    NSString *deviceToken = stringValue(params, @"deviceToken");
    if ([deviceToken length] > 0) {
        client.deviceToken = deviceToken;
    }

    if (hasValue(params, @"showNotification") || hasValue(params, @"autoNotification")) {
        BOOL showNotification = boolValue(params, @"showNotification") || boolValue(params, @"autoNotification");
        [client setAutoNotification:showNotification];
        if (showNotification) {
            requestLocalNotificationPermission();
        }
    }
}

static ZCLibInitInfo* applyInitInfo(NSDictionary *params) {
    ZCLibClient *client = [ZCLibClient getZCLibClient];
    applyClientOptions(client, params);

    ZCLibInitInfo *initInfo = client.libInitInfo;
    if (initInfo == nil) {
        initInfo = [ZCLibInitInfo new];
    }

    setStringIfPresent(^(NSString *v) { initInfo.app_key = v; }, params, @"app_key");
    setStringIfPresent(^(NSString *v) { initInfo.partnerid = v; }, params, @"partnerid");
    setStringIfPresent(^(NSString *v) { initInfo.choose_adminid = v; }, params, @"choose_adminid");
    if ([stringValue(params, @"tran_flag") length] > 0) initInfo.tran_flag = intValue(params, @"tran_flag");
    setStringIfPresent(^(NSString *v) { initInfo.user_nick = v; }, params, @"user_nick");
    setStringIfPresent(^(NSString *v) { initInfo.user_name = v; }, params, @"user_name");
    setStringIfPresent(^(NSString *v) { initInfo.user_tels = v; }, params, @"user_tels");
    setStringIfPresent(^(NSString *v) { initInfo.user_emails = v; }, params, @"user_emails");
    setStringIfPresent(^(NSString *v) { initInfo.isVip = v; }, params, @"isVip");
    setStringIfPresent(^(NSString *v) { initInfo.vip_level = v; }, params, @"vip_level");
    setStringIfPresent(^(NSString *v) { initInfo.user_label = v; }, params, @"user_label");
    setStringIfPresent(^(NSString *v) { initInfo.qq = v; }, params, @"qq");
    setStringIfPresent(^(NSString *v) { initInfo.face = v; }, params, @"face");
    setStringIfPresent(^(NSString *v) { initInfo.remark = v; }, params, @"remark");
    setStringIfPresent(^(NSString *v) { initInfo.groupid = v; }, params, @"groupid");
    setStringIfPresent(^(NSString *v) { initInfo.group_name = v; }, params, @"group_name");
    if ([stringValue(params, @"good_msg_type") length] > 0) initInfo.good_msg_type = intValue(params, @"good_msg_type");
    setStringIfPresent(^(NSString *v) { initInfo.content = v; }, params, @"content");
    setStringIfPresent(^(NSString *v) { initInfo.absolute_language = v; }, params, @"absolute_language");

    NSDictionary *customParams = jsonDictValue(params, @"params");
    if (customParams) initInfo.params = customParams;

    NSDictionary *customerFields = jsonDictValue(params, @"customer_fields");
    if (customerFields) initInfo.customer_fields = customerFields;

    NSDictionary *multiParams = jsonDictValue(params, @"multi_params");
    if (multiParams) initInfo.multi_params = multiParams;

    applyCustomCard(initInfo, params);

    client.libInitInfo = initInfo;
    return initInfo;
}

static ZCKitInfo* buildKitInfo(NSDictionary *params) {
    ZCKitInfo *kitInfo = [ZCKitInfo new];
    setStringIfPresent(^(NSString *v) { kitInfo.leaveMsgGroupId = v; }, params, @"leaveMsgGroupId");
    kitInfo.isShowReturnTips = boolValue(params, @"isShowReturnTips");
    kitInfo.ishidesBottomBarWhenPushed = boolValue(params, @"ishidesBottomBarWhenPushed");
    kitInfo.navcBarHidden = boolValue(params, @"navcBarHidden");
    kitInfo.isShowClose = boolValue(params, @"isShowClose");
    kitInfo.isShowCloseSatisfaction = boolValue(params, @"isShowCloseSatisfaction");
    kitInfo.isCloseAfterEvaluation = boolValue(params, @"isCloseAfterEvaluation");
    kitInfo.isOpenEvaluation = boolValue(params, @"isOpenEvaluation");
    if (hasValue(params, @"isShowEvaluation")) kitInfo.isShowEvaluation = boolValue(params, @"isShowEvaluation");
    kitInfo.canBackWithNotEvaluation = boolValue(params, @"canBackWithNotEvaluation");
    if (hasValue(params, @"isOpenRecord")) kitInfo.isOpenRecord = boolValue(params, @"isOpenRecord");
    if (hasValue(params, @"isOpenRobotVoice")) kitInfo.isOpenRobotVoice = boolValue(params, @"isOpenRobotVoice");
    kitInfo.hideRototEvaluationLabels = boolValue(params, @"hideRototEvaluationLabels");
    kitInfo.hideManualEvaluationLabels = boolValue(params, @"hideManualEvaluationLabels");
    kitInfo.isShowLandscape = boolValue(params, @"isLandscapeMode") || boolValue(params, @"landscape_screen");
    kitInfo.isShowPortrait = boolValue(params, @"isShowPortrait");

    ZCProductInfo *productInfo = buildProductInfo(params);
    if (productInfo) {
        kitInfo.productInfo = productInfo;
        kitInfo.isSendInfoCard = boolValue(params, @"isSendInfoCard");
        kitInfo.isEveryTimeSendCard = boolValue(params, @"isEveryTimeSendCard");
    }

    ZCOrderGoodsModel *orderInfo = buildOrderGoodsInfo(params);
    if (orderInfo) {
        kitInfo.orderGoodsInfo = orderInfo;
        kitInfo.autoSendOrderMessage = boolValue(params, @"autoSendOrderMessage");
        kitInfo.isEveryTimeAutoSend = boolValue(params, @"isEveryTimeAutoSend");
    }

    return kitInfo;
}

#pragma mark - 初始化

extern "C" void _sobotInitSDK(const char* paramJson, const char* gameObjectName, const char* callbackMethod) {
    NSDictionary *params = parseJson(paramJson);
    NSString *key = stringValue(params, @"app_key");
    NSString *host = stringValue(params, @"api_host");
    const char* objCopy = strdup(gameObjectName);
    const char* methodCopy = strdup(callbackMethod);

    dispatch_async(dispatch_get_main_queue(), ^{
        applyInitInfo(params);

        [ZCSobotApi initSobotSDK:key host:host result:^(id _Nonnull object) {
            NSString *result = [NSString stringWithFormat:@"%@", object];
            UnitySendMessage(objCopy, methodCopy, [result UTF8String]);
            free((void *)objCopy);
            free((void *)methodCopy);
        }];
    });
}

#pragma mark - 启动聊天

extern "C" void _sobotOpenChat(const char* paramJson) {
    NSDictionary *params = parseJson(paramJson);

    dispatch_async(dispatch_get_main_queue(), ^{
        applyInitInfo(params);
        registerMessageLinkClickHandler();
        registerFunctionClickHandler();

        ZCKitInfo *uiInfo = buildKitInfo(params);
        UIViewController *vc = topViewController();
        [ZCSobotApi openZCChat:uiInfo with:vc pageBlock:^(id _Nonnull object, ZCPageStateType type) {
            NSLog(@"[SobotSDK] Chat page state: %ld", (long)type);
            registerMessageLinkClickHandler();
            registerFunctionClickHandler();
        }];
        registerMessageLinkClickHandler();
        registerFunctionClickHandler();
    });
}

#pragma mark - 启动帮助中心

extern "C" void _sobotOpenServiceCenter(const char* paramJson) {
    NSDictionary *params = parseJson(paramJson);

    dispatch_async(dispatch_get_main_queue(), ^{
        applyInitInfo(params);
        registerMessageLinkClickHandler();
        registerFunctionClickHandler();

        ZCKitInfo *kitInfo = buildKitInfo(params);
        UIViewController *vc = topViewController();
        [ZCSobotApi openZCServiceCenter:kitInfo with:vc onItemClick:nil];
        registerMessageLinkClickHandler();
        registerFunctionClickHandler();
    });
}

#pragma mark - 启动留言

extern "C" void _sobotOpenLeave(const char* paramJson) {
    NSDictionary *params = parseJson(paramJson);

    dispatch_async(dispatch_get_main_queue(), ^{
        applyInitInfo(params);
        registerMessageLinkClickHandler();
        registerFunctionClickHandler();

        ZCKitInfo *kitInfo = buildKitInfo(params);
        UIViewController *vc = topViewController();
        [ZCSobotApi openLeaveisOnlyShowRecored:NO Kitinfo:kitInfo with:vc onItemClick:nil];
        registerMessageLinkClickHandler();
        registerFunctionClickHandler();
    });
}

#pragma mark - 关闭会话

extern "C" void _sobotCloseSession(bool closePush) {
    dispatch_async(dispatch_get_main_queue(), ^{
        [ZCSobotApi outCurrentUserZCLibInfo:closePush];
    });
}

#pragma mark - 获取离线消息数

extern "C" void _sobotGetOfflineMsg(const char* paramJson,
                                     const char* gameObjectName,
                                     const char* callbackMethod) {
    NSDictionary *params = parseJson(paramJson);
    NSString *pid = stringValue(params, @"partnerid");
    NSString *key = stringValue(params, @"app_key");
    const char* objCopy = strdup(gameObjectName);
    const char* methodCopy = strdup(callbackMethod);

    [ZCSobotApi getOfflineMsgAndUnAckMsgWith:pid appkey:key
        resultBlock:^(NSDictionary * _Nonnull object, NSString * _Nonnull message,
                      int unReadSize, int offlineSize, int unAckSize) {
        NSString *result = [NSString stringWithFormat:@"%d,%d,%d", unReadSize, offlineSize, unAckSize];
        UnitySendMessage(objCopy, methodCopy, [result UTF8String]);
        free((void *)objCopy);
        free((void *)methodCopy);
    }];
}

#pragma mark - 主动发送消息

extern "C" void _sobotSendCustomCardToChat(const char* paramJson,
                                            const char* gameObjectName,
                                            const char* callbackMethod,
                                            const char* requestId) {
    NSDictionary *params = parseJson(paramJson);
    NSString *objName = toNSString(gameObjectName);
    NSString *methodName = toNSString(callbackMethod);
    NSString *sendRequestId = toNSString(requestId);

    dispatch_async(dispatch_get_main_queue(), ^{
        NSDictionary *customCardDict = jsonDictValue(params, @"custom_card");
        if (customCardDict == nil) {
            sendUnitySendResultWithNames(objName, methodName, sendRequestId, @"custom_card 不能为空", -1);
            return;
        }

        SobotChatCustomCard *card = buildCustomCard(customCardDict);
        [ZCSobotApi sendCustomCardToChat:card resultBlock:^(NSString * _Nonnull msg, int code) {
            sendUnitySendResultWithNames(objName, methodName, sendRequestId, msg, code);
        }];
    });
}

extern "C" void _sobotSendProductInfo(const char* paramJson,
                                       const char* gameObjectName,
                                       const char* callbackMethod,
                                       const char* requestId) {
    NSDictionary *params = parseJson(paramJson);
    NSString *objName = toNSString(gameObjectName);
    NSString *methodName = toNSString(callbackMethod);
    NSString *sendRequestId = toNSString(requestId);

    dispatch_async(dispatch_get_main_queue(), ^{
        ZCProductInfo *productInfo = buildProductInfo(params);
        if (productInfo == nil) {
            sendUnitySendResultWithNames(objName, methodName, sendRequestId, @"goodsTitle 和 goodsLink 不能为空", -1);
            return;
        }

        [ZCSobotApi sendProductInfo:productInfo resultBlock:^(NSString *msg, int code) {
            sendUnitySendResultWithNames(objName, methodName, sendRequestId, msg, code);
        }];
    });
}

extern "C" void _sobotSendOrderGoodsInfo(const char* paramJson,
                                          const char* gameObjectName,
                                          const char* callbackMethod,
                                          const char* requestId) {
    NSDictionary *params = parseJson(paramJson);
    NSString *objName = toNSString(gameObjectName);
    NSString *methodName = toNSString(callbackMethod);
    NSString *sendRequestId = toNSString(requestId);

    dispatch_async(dispatch_get_main_queue(), ^{
        if ([stringValue(params, @"orderCode") length] == 0) {
            sendUnitySendResultWithNames(objName, methodName, sendRequestId, @"orderCode 不能为空", -1);
            return;
        }

        ZCOrderGoodsModel *orderInfo = buildOrderGoodsInfo(params);
        if (orderInfo == nil) {
            sendUnitySendResultWithNames(objName, methodName, sendRequestId, @"订单卡片参数不能为空", -1);
            return;
        }

        [ZCSobotApi sendOrderGoodsInfo:orderInfo resultBlock:^(NSString *msg, int code) {
            sendUnitySendResultWithNames(objName, methodName, sendRequestId, msg, code);
        }];
    });
}

extern "C" void _sobotSendLocation(const char* paramJson,
                                    const char* gameObjectName,
                                    const char* callbackMethod,
                                    const char* requestId) {
    NSDictionary *params = parseJson(paramJson);
    NSString *objName = toNSString(gameObjectName);
    NSString *methodName = toNSString(callbackMethod);
    NSString *sendRequestId = toNSString(requestId);

    dispatch_async(dispatch_get_main_queue(), ^{
        NSDictionary *locations = buildLocationDict(params);
        if (locations == nil) {
            sendUnitySendResultWithNames(objName, methodName, sendRequestId, @"lat 和 lng 不能为空", -1);
            return;
        }

        NSLog(@"[SobotUnityBridge] sendLocation request locations=%@", locations);
        [ZCSobotApi sendLocation:locations resultBlock:^(NSString *msg, int code) {
            NSLog(@"[SobotUnityBridge] sendLocation result code=%d msg=%@ locations=%@", code, msg ?: @"", locations);
            sendUnitySendResultWithNames(objName, methodName, sendRequestId, msg, code);
        }];
    });
}

#pragma mark - 链接点击监听

extern "C" void _sobotSetLinkClickListener(SobotUnityLinkClickCallback callback) {
    s_linkClickCallback = callback;

    dispatch_async(dispatch_get_main_queue(), ^{
        registerMessageLinkClickHandler();
    });
}

#pragma mark - 功能点击监听

extern "C" void _sobotSetFunctionClickListener(SobotUnityFunctionClickCallback callback) {
    s_functionClickCallback = callback;

    dispatch_async(dispatch_get_main_queue(), ^{
        registerFunctionClickHandler();
    });
}
