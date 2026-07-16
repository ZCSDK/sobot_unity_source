package com.sobot.unity;

import android.app.Activity;
import android.app.Application;
import android.content.Context;
import android.content.Intent;
import android.util.Log;

import com.unity3d.player.UnityPlayer;
import com.sobot.chat.MarkConfig;
import com.sobot.chat.SobotUIConfig;
import com.sobot.chat.ZCSobotApi;
import com.sobot.chat.listener.NewHyperlinkListener;
import com.sobot.chat.listener.SobotFunctionClickListener;
import com.sobot.network.http.callback.StringResultCallBack;

import org.json.JSONArray;
import org.json.JSONObject;

import java.lang.reflect.Method;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

/**
 * 智齿 SDK Unity Bridge
 */
public class SobotBridge {

    private static final String TAG = "SobotBridge";
    private static final String INFORMATION_CLASS = "com.sobot.chat.api.model.Information";
    private static final String CONSULTING_CONTENT_CLASS = "com.sobot.chat.api.model.ConsultingContent";
    private static final String ORDER_CARD_CONTENT_CLASS = "com.sobot.chat.api.model.OrderCardContentModel";
    private static final String ORDER_CARD_GOODS_CLASS = "com.sobot.chat.api.model.OrderCardContentModel$Goods";
    private static final String SOBOT_LOCATION_CLASS = "com.sobot.chat.api.model.SobotLocationModel";
    private static final String AUTO_SEND_MSG_MODE_CLASS = "com.sobot.chat.api.enumtype.SobotAutoSendMsgMode";
    private static final String CUSTOM_CARD_CLASS = "com.sobot.chat.api.model.customcard.SobotChatCustomCard";
    private static final String CUSTOM_GOODS_CLASS = "com.sobot.chat.api.model.customcard.SobotChatCustomGoods";
    private static final String CUSTOM_MENU_CLASS = "com.sobot.chat.api.model.customcard.SobotChatCustomMenu";
    private static final String LOCAL_BROADCAST_MANAGER_CLASS = "androidx.localbroadcastmanager.content.LocalBroadcastManager";
    private static final String EXTRA_SEND_DATA = "SOBOT_SEND_DATA";
    private static final String EXTRA_LOCATION_DATA = "SOBOT_LOCATION_DATA";
    private static final String ACTION_SEND_CARD = "SOBOT_BROCAST_ACTION_SEND_CARD";
    private static final String ACTION_SEND_ORDER_CARD = "SOBOT_BROCAST_ACTION_SEND_ORDERCARD";
    private static final String ACTION_SEND_CUSTOM_CARD = "SOBOT_BROCAST_ACTION_SEND_CUSTOM_CARD";
    private static final String ACTION_SEND_LOCATION = "SOBOT_BROCAST_ACTION_SEND_LOCATION";

    /**
     * 初始化智齿 Android SDK。
     * paramJson 来自 Unity 的 SobotParams JSON，主要读取 app_key 和 api_host。
     * @param paramJson Unity 侧传入的 SobotParams JSON，读取 app_key、api_host 等初始化参数。
     */
    public static void initSobotSDK(String paramJson) {
        try {
            JSONObject params = parse(paramJson);
            Activity activity = UnityPlayer.currentActivity;
            Application app = activity.getApplication();
            String api_host = optString(params, "api_host");
            String app_key = optString(params, "app_key");
            applyApiHost(api_host);
            ZCSobotApi.initSobotSDK(app, app_key, "");
            UnityPlayer.UnitySendMessage("ZCSobotApi", "OnInitResult", "success");
        } catch (Exception e) {
            UnityPlayer.UnitySendMessage("ZCSobotApi", "OnInitResult", "error:" + e.getMessage());
        }
    }

    /**
     * 打开智齿客服聊天页面。
     * 会先把 Unity 参数转换为 Android SDK 的 Information 对象。
     * @param paramJson Unity 侧传入的 SobotParams JSON，用于打开客服聊天页。
     */
    public static void openSobotChat(String paramJson) {
        try {
            Activity activity = UnityPlayer.currentActivity;
            Object info = buildInformation(parse(paramJson));
            invokeSobotApi("openZCChat", activity, info);
        } catch (Exception e) {
            Log.e(TAG, "openSobotChat error: " + e.getMessage());
        }
    }

    /**
     * 打开智齿帮助中心页面。
     * @param paramJson Unity 侧传入的 SobotParams JSON，用于打开帮助中心。
     */
    public static void openSobotHelpCenter(String paramJson) {
        try {
            Activity activity = UnityPlayer.currentActivity;
            Object info = buildInformation(parse(paramJson));
            invokeSobotApi("openZCServiceCenter", activity, info);
        } catch (Exception e) {
            Log.e(TAG, "openSobotHelpCenter error: " + e.getMessage());
        }
    }

    /**
     * 打开智齿留言页面。
     * @param paramJson Unity 侧传入的 SobotParams JSON，用于打开留言页。
     */
    public static void openSobotLeave(String paramJson) {
        try {
            Activity activity = UnityPlayer.currentActivity;
            Object info = buildInformation(parse(paramJson));
            invokeSobotApi("openLeave", activity, info, Boolean.FALSE);
        } catch (Exception e) {
            Log.e(TAG, "openSobotLeave error: " + e.getMessage());
        }
    }

    /**
     * 获取离线消息和未读消息数量。
     * 结果通过 Unity 侧传入的 StringResultCallBack 返回。
     * @param paramJson Unity 侧传入的 SobotParams JSON，用于查询未读消息。
     * @param callback Unity 层回传结果的回调。
     */
    public static void getUnReadMessage(String paramJson, StringResultCallBack callback) {
        try {
            JSONObject params = parse(paramJson);
            Activity activity = UnityPlayer.currentActivity;
            ZCSobotApi.offlineMsgSize(
                activity,
                optString(params, "app_key"),
                optString(params, "partnerid"),
                callback
            );
        } catch (Exception e) {
            Log.e(TAG, "getUnReadMessage error: " + e.getMessage());
        }
    }

    /**
     * 退出当前智齿用户会话。
     * closePush=true 时同时关闭推送相关状态。
     * @param paramJson Unity 侧传入的 SobotParams JSON，当前主要用于携带 closePush。
     */
    public static void closeSobotChat(String paramJson) {
        try {
            Activity activity = UnityPlayer.currentActivity;
            ZCSobotApi.outCurrentUserZCLibInfo(activity, "");
        } catch (Exception e) {
            Log.e(TAG, "closeSobotChat error: " + e.getMessage());
        }
    }

    /**
     * 注册消息链接点击监听。
     * Unity 侧返回 true 时表示拦截默认跳转。
     * @param listener 消息链接点击监听器，由 Unity 层决定是否拦截跳转。
     */
    public static void setMessageLinkClick(NewHyperlinkListener listener) {
        try {
            ZCSobotApi.setNewHyperlinkListener(listener);
        } catch (Exception e) {
            Log.e(TAG, "setMessageLinkClick error: " + e.getMessage());
        }
    }

    /**
     * 注册智齿页面功能按钮点击监听。
     * @param listener 功能按钮点击监听器。
     */
    public static void setFunctionClickListener(SobotFunctionClickListener listener) {
        try {
            ZCSobotApi.setFunctionClickListener(listener);
        } catch (Exception e) {
            Log.e(TAG, "setFunctionClickListener error: " + e.getMessage());
        }
    }

    /**
     * 主动发送自定义卡片消息。
     * @param paramJson Unity 侧传入的 SobotParams JSON，其中 custom_card 为必填。
     */
    public static boolean sendCustomCardToChat(String paramJson) {
        try {
            Activity activity = UnityPlayer.currentActivity;
            JSONObject params = parse(paramJson);
            JSONObject cardJson = optJSONObject(params, "custom_card");
            if (cardJson == null) {
                Log.w(TAG, "sendCustomCardToChat ignored: custom_card is empty");
                return false;
            }

            Log.d(TAG, "sendCustomCardToChat custom_card=" + cardJson.toString());
            return sendSobotLocalBroadcast(activity, ACTION_SEND_CUSTOM_CARD, EXTRA_SEND_DATA, buildCustomCard(cardJson));
        } catch (Exception e) {
            Log.e(TAG, "sendCustomCardToChat error", e);
            return false;
        }
    }

    /**
     * 主动发送商品卡片消息。
     * @param paramJson Unity 侧传入的 SobotParams JSON，其中 goodsTitle 和 goodsLink 为核心字段。
     */
    public static boolean sendProductInfo(String paramJson) {
        try {
            Activity activity = UnityPlayer.currentActivity;
            Object content = buildConsultingContent(parse(paramJson), true);
            if (content == null) return false;

            return sendSobotLocalBroadcast(activity, ACTION_SEND_CARD, EXTRA_SEND_DATA, content);
        } catch (Exception e) {
            Log.e(TAG, "sendProductInfo error", e);
            return false;
        }
    }

    /**
     * 主动发送订单卡片消息。
     * @param paramJson Unity 侧传入的 SobotParams JSON，其中 orderCode 为核心字段。
     */
    public static boolean sendOrderGoodsInfo(String paramJson) {
        try {
            Activity activity = UnityPlayer.currentActivity;
            Object order = buildOrderGoodsInfo(parse(paramJson), true);
            if (order == null) return false;

            return sendSobotLocalBroadcast(activity, ACTION_SEND_ORDER_CARD, EXTRA_SEND_DATA, order);
        } catch (Exception e) {
            Log.e(TAG, "sendOrderGoodsInfo error", e);
            return false;
        }
    }

    /**
     * 主动发送位置消息。
     * @param paramJson Unity 侧传入的 SobotParams JSON，其中 lat 和 lng 为必填。
     */
    public static boolean sendLocation(String paramJson) {
        try {
            Activity activity = UnityPlayer.currentActivity;
            Object location = buildLocation(parse(paramJson));
            if (location == null) return false;

            return sendSobotLocalBroadcast(activity, ACTION_SEND_LOCATION, EXTRA_LOCATION_DATA, location);
        } catch (Exception e) {
            Log.e(TAG, "sendLocation error", e);
            return false;
        }
    }

    /**
     * 根据 Unity 参数构造 Android SDK 的 Information 对象。
     * 使用反射设置字段，降低不同 Android SDK 版本方法差异带来的兼容风险。
     * @param params Unity 参数解析后的 JSON 对象。
     */
    private static Object buildInformation(JSONObject params) throws Exception {
        Object info = newSdkObject(INFORMATION_CLASS);

        applyStringSetter(info, "setApp_key", optString(params, "app_key"));
        applyStringSetter(info, "setPartnerid", optString(params, "partnerid"));
        applyStringSetter(info, "setChoose_adminid", optString(params, "choose_adminid"));
        applyIntSetter(info, "setTran_flag", optInt(params, "tran_flag"));
        applyStringSetter(info, "setUser_nick", optString(params, "user_nick"));
        applyStringSetter(info, "setUser_name", optString(params, "user_name"));
        applyStringSetter(info, "setUser_tels", optString(params, "user_tels"));
        applyStringSetter(info, "setUser_emails", optString(params, "user_emails"));
        applyStringSetter(info, "setIsVip", optString(params, "isVip"));
        applyStringSetter(info, "setVip_level", optString(params, "vip_level"));
        applyStringSetter(info, "setUser_label", optString(params, "user_label"));
        applyStringSetter(info, "setQq", optString(params, "qq"));
        applyStringSetter(info, "setFace", optString(params, "face"));
        applyStringSetter(info, "setRemark", optString(params, "remark"));
        applyStringSetter(info, "setParams", optString(params, "params"));
        applyStringSetter(info, "setCustomer_fields", optString(params, "customer_fields"));
        applyStringSetter(info, "setMulti_params", optString(params, "multi_params"));
        applyStringSetter(info, "setGroupid", optString(params, "groupid"));
        applyStringSetter(info, "setGroup_name", optString(params, "group_name"));
        applyAutoSendMsgMode(info, params);
        applyAndroidGlobalOptions(UnityPlayer.currentActivity, params);
        applyOptionalBooleanSetter(info, "setUseVoice", params, "isOpenRecord");
        applyOptionalBooleanSetter(info, "setUseRobotVoice", params, "isOpenRobotVoice");
        applyOptionalBooleanSetter(info, "setShowLeftBackPop", params, "isShowReturnTips");
        applyOptionalBooleanSetter(info, "setShowCloseBtn", params, "isShowClose");
        applyOptionalBooleanSetter(info, "setShowSatisfaction", params, "isOpenEvaluation");
        applyOptionalBooleanSetter(info, "setShowCloseSatisfaction", params, "isShowCloseSatisfaction");
        applyOptionalBooleanSetter(info, "setCanBackWithNotEvaluation", params, "canBackWithNotEvaluation");
        applyOptionalBooleanSetter(info, "setHideRototEvaluationLabels", params, "hideRototEvaluationLabels");
        applyOptionalBooleanSetter(info, "setHideManualEvaluationLabels", params, "hideManualEvaluationLabels");
        applyStringSetter(info, "setLeaveMsgGroupId", optString(params, "leaveMsgGroupId"));
        applyConsultingContent(info, params);
        applyOrderGoodsInfo(info, params);
        applyStringSetter(info, "setCusMoreArray", optString(params, "cusMoreArray"));
        applyCustomCard(info, params);

        return info;
    }

    /**
     * 应用 Android SDK 的全局 UI 和调试配置。
     * @param context 当前 Android Context。
     * @param params Unity 参数解析后的 JSON 对象。
     */
    private static void applyAndroidGlobalOptions(Context context, JSONObject params) {
        applyInternationalLanguage(context, optString(params, "absolute_language"));
        applyUrlRegular(optString(params, "urlRegular"));
        applyTelRegular(optString(params, "telRegular"));

        if (params.has("isCloseAfterEvaluation")) {
            boolean value = params.optBoolean("isCloseAfterEvaluation");
            try {
                ZCSobotApi.setEvaluationCompletedExit(context, value);
                Log.d(TAG, "setEvaluationCompletedExit=" + value);
            } catch (Exception e) {
                Log.d(TAG, "skip unsupported global option: isCloseAfterEvaluation");
            }
        }

        if (params.has("isShowEvaluation")) {
            boolean value = params.optBoolean("isShowEvaluation");
            SobotUIConfig.sobot_title_right_menu2_display = value;
            if (value) {
                SobotUIConfig.sobot_title_right_menu2_call_num = "";
                SobotUIConfig.sobot_title_right_menu2_bg = -1;
            }
            Log.d(TAG, "set isShowEvaluation via SobotUIConfig.sobot_title_right_menu2_display=" + value);
        }

        if (params.has("leaveCompleteCanReply")) {
            boolean value = params.optBoolean("leaveCompleteCanReply");
            try {
                ZCSobotApi.setSwitchMarkStatus(MarkConfig.LEAVE_COMPLETE_CAN_REPLY, value);
                Log.d(TAG, "set leaveCompleteCanReply=" + value);
            } catch (Exception e) {
                Log.d(TAG, "skip unsupported global option: leaveCompleteCanReply");
            }
        }

        if (params.has("showNotification")) {
            boolean value = params.optBoolean("showNotification");
            try {
                ZCSobotApi.setNotificationFlag(context, value, 0, 0);
                Log.d(TAG, "setNotificationFlag=" + value);
            } catch (Exception e) {
                Log.d(TAG, "skip unsupported global option: showNotification");
            }
        }
    }

    /**
     * 设置 Android SDK 国际化语言。
     * @param context 当前 Android Context。
     * @param value 语言标识字符串，例如 zh、en 等。
     */
    private static void applyInternationalLanguage(Context context, String value) {
        if (isEmpty(value)) return;
        try {
            ZCSobotApi.setInternationalLanguage(context, value.replace("_lproj", ""), true);
            Log.d(TAG, "setInternationalLanguage=" + value);
        } catch (Exception e) {
            Log.d(TAG, "skip unsupported global option: absolute_language");
        }
    }

    /**
     * 设置 URL 识别正则。
     * @param value URL 识别正则表达式。
     */
    private static void applyUrlRegular(String value) {
        if (isEmpty(value)) return;
        try {
            ZCSobotApi.replaceWebUrlPattern(value);
            Log.d(TAG, "replaceWebUrlPattern configured");
        } catch (Exception e) {
            Log.d(TAG, "skip unsupported global option: urlRegular");
        }
    }

    /**
     * 设置电话识别正则。
     * @param value 电话识别正则表达式。
     */
    private static void applyTelRegular(String value) {
        if (isEmpty(value)) return;
        try {
            ZCSobotApi.replacePhoneNumberPattern(value);
            Log.d(TAG, "replacePhoneNumberPattern configured");
        } catch (Exception e) {
            Log.d(TAG, "skip unsupported global option: telRegular");
        }
    }

    /**
     * 通过 LocalBroadcastManager 向智齿聊天页面发送卡片或位置消息。
     * @param context 当前 Android Context。
     * @param action 广播 action。
     * @param extraKey 附加数据 key。
     * @param data 需要随广播发送的数据对象。
     */
    private static boolean sendSobotLocalBroadcast(Context context, String action, String extraKey, Object data) throws Exception {
        if (context == null || data == null) return false;
        if (!(data instanceof Serializable)) {
            Log.e(TAG, "sendSobotLocalBroadcast ignored: data is not Serializable, action=" + action);
            return false;
        }

        Intent intent = new Intent();
        intent.setAction(action);
        intent.putExtra(extraKey, (Serializable) data);

        Class<?> managerClass = Class.forName(LOCAL_BROADCAST_MANAGER_CLASS);
        Method getInstance = managerClass.getMethod("getInstance", Context.class);
        Object manager = getInstance.invoke(null, context.getApplicationContext());
        Method sendBroadcast = managerClass.getMethod("sendBroadcast", Intent.class);
        Boolean delivered = (Boolean) sendBroadcast.invoke(manager, intent);
        boolean success = delivered != null && delivered.booleanValue();
        Log.d(TAG, "sendSobotLocalBroadcast action=" + action + " delivered=" + success);
        if (!success) {
            Log.w(TAG, "active send ignored: chat page receiver is not registered, action=" + action);
        }
        return success;
    }

    /**
     * 配置商品卡片和订单卡片的自动发送策略。
     * @param info Information 对象。
     * @param params Unity 参数解析后的 JSON 对象。
     */
    private static void applyAutoSendMsgMode(Object info, JSONObject params) {
        Integer goodMsgType = optInt(params, "good_msg_type");
        String content = optString(params, "content");
        if (goodMsgType == null || isEmpty(content)) return;

        String modeName;
        switch (goodMsgType.intValue()) {
            case 1:
                modeName = "SendToRobot";
                break;
            case 2:
                modeName = "SendToOperator";
                break;
            case 3:
                modeName = "SendToAll";
                break;
            default:
                Log.w(TAG, "auto send ignored: unsupported good_msg_type=" + goodMsgType);
                return;
        }

        try {
            Class<?> modeClass = Class.forName(AUTO_SEND_MSG_MODE_CLASS);
            Object mode = modeClass.getField(modeName).get(null);
            Method setContent = modeClass.getMethod("setContent", String.class);
            Object configuredMode = setContent.invoke(mode, content);
            applyObjectSetter(info, "setAutoSendMsgMode", configuredMode == null ? mode : configuredMode);
            Log.d(TAG, "auto send configured mode=" + modeName + " content=" + content);
        } catch (Exception e) {
            Log.e(TAG, "applyAutoSendMsgMode error: " + e.getMessage());
        }
    }

    /**
     * 解析 Unity 传入的 JSON 字符串。
     * @param paramJson Unity 传入的 JSON 字符串。
     */
    private static JSONObject parse(String paramJson) throws Exception {
        if (paramJson == null || paramJson.length() == 0) {
            return new JSONObject();
        }
        return new JSONObject(paramJson);
    }

    /**
     * 读取字符串字段，并把缺失值统一转为空字符串。
     * @param params 参数 JSON 对象。
     * @param key 字段名。
     */
    private static String optString(JSONObject params, String key) {
        return params.optString(key, "");
    }

    /**
     * 读取布尔字段，支持默认值。
     * @param params 参数 JSON 对象。
     * @param key 字段名。
     * @param defaultValue 字段缺失时返回的默认值。
     */
    private static boolean optBoolean(JSONObject params, String key, boolean defaultValue) {
        if (!params.has(key)) return defaultValue;
        return params.optBoolean(key, defaultValue);
    }

    /**
     * 读取整数字段，字段缺失或为空时返回 null。
     * @param params 参数 JSON 对象。
     * @param key 字段名。
     */
    private static Integer optInt(JSONObject params, String key) {
        if (!params.has(key)) return null;
        try {
            return params.getInt(key);
        } catch (Exception ignored) {
            try {
                String value = params.optString(key, "");
                return isEmpty(value) ? null : Integer.parseInt(value);
            } catch (Exception ignoredAgain) {
                return null;
            }
        }
    }

    /**
     * 判断字符串是否为空。
     * @param value 待判断字符串。
     */
    private static boolean isEmpty(String value) {
        return value == null || value.length() == 0;
    }

    /**
     * 判断多个字段中是否至少存在一个有效值。
     * @param params 参数 JSON 对象。
     * @param keys 需要检查的字段名列表。
     */
    private static boolean hasAnyValue(JSONObject params, String... keys) {
        for (String key : keys) {
            if (!isEmpty(optString(params, key))) return true;
        }
        return false;
    }

    /**
     * 将商品卡片信息写入 Information。
     * @param info Information 对象。
     * @param params Unity 参数解析后的 JSON 对象。
     */
    private static void applyConsultingContent(Object info, JSONObject params) throws Exception {
        Object content = buildConsultingContent(params, false);
        if (content != null) applyObjectSetter(info, "setContent", content);
    }

    /**
     * 构造 Android 商品卡片 ConsultingContent。
     * @param params Unity 参数解析后的 JSON 对象。
     * @param requireFields 是否要求核心字段必须存在。
     */
    private static Object buildConsultingContent(JSONObject params, boolean requireFields) throws Exception {
        if (!hasAnyValue(params, "goodsTitle", "goodsDesc", "goodsLabel", "goodsLink", "goodsImage")) {
            return null;
        }

        String title = optString(params, "goodsTitle");
        String link = optString(params, "goodsLink");
        if (requireFields && (isEmpty(title) || isEmpty(link))) {
            Log.w(TAG, "sendProductInfo ignored: goodsTitle and goodsLink are required");
            return null;
        }

        Object content = newSdkObject(CONSULTING_CONTENT_CLASS);
        applyStringSetter(content, "setSobotGoodsTitle", title);
        applyStringSetter(content, "setSobotGoodsDescribe", optString(params, "goodsDesc"));
        applyStringSetter(content, "setSobotGoodsLable", optString(params, "goodsLabel"));
        applyStringSetter(content, "setSobotGoodsFromUrl", link);
        applyStringSetter(content, "setSobotGoodsImgUrl", optString(params, "goodsImage"));
        applyBooleanSetter(content, "setAutoSend", params.optBoolean("isSendInfoCard"));
        applyBooleanSetter(content, "setEveryTimeAutoSend", params.optBoolean("isEveryTimeSendCard"));
        return content;
    }

    /**
     * 将订单卡片信息写入 Information。
     * @param info Information 对象。
     * @param params Unity 参数解析后的 JSON 对象。
     */
    private static void applyOrderGoodsInfo(Object info, JSONObject params) throws Exception {
        Object order = buildOrderGoodsInfo(params, false);
        if (order != null) applyObjectSetter(info, "setOrderGoodsInfo", order);
    }

    /**
     * 构造 Android 订单卡片模型。
     * @param params Unity 参数解析后的 JSON 对象。
     * @param requireFields 是否要求核心字段必须存在。
     */
    private static Object buildOrderGoodsInfo(JSONObject params, boolean requireFields) throws Exception {
        if (!hasAnyValue(params, "orderCode", "orderStatus", "statusCustom", "createTime", "goodsCount", "orderUrl", "goods", "totalFee")) {
            return null;
        }

        String orderCode = optString(params, "orderCode");
        if (requireFields && isEmpty(orderCode)) {
            Log.w(TAG, "sendOrderGoodsInfo ignored: orderCode is required");
            return null;
        }

        Object order = newSdkObject(ORDER_CARD_CONTENT_CLASS);
        Integer orderStatus = optInt(params, "orderStatus");
        Integer totalFee = optInt(params, "totalFee");
        applyIntSetter(order, "setOrderStatus", orderStatus == null ? Integer.valueOf(0) : orderStatus);
        applyStringSetter(order, "setOrderCode", orderCode);
        applyStringSetter(order, "setStatusCustom", optString(params, "statusCustom"));
        applyStringSetter(order, "setCreateTime", optString(params, "createTime"));
        applyStringSetter(order, "setGoodsCount", optString(params, "goodsCount"));
        applyStringSetter(order, "setOrderUrl", optString(params, "orderUrl"));
        applyIntSetter(order, "setTotalFee", totalFee == null ? Integer.valueOf(0) : totalFee);
        applyBooleanSetter(order, "setAutoSend", params.optBoolean("autoSendOrderMessage"));
        applyBooleanSetter(order, "setEveryTimeAutoSend", params.optBoolean("isEveryTimeAutoSend"));

        JSONArray goodsArray = optJSONArray(params, "goods");
        if (goodsArray != null) {
            List<Object> goodsList = new ArrayList<>();
            Class<?> goodsClass = Class.forName(ORDER_CARD_GOODS_CLASS);
            for (int i = 0; i < goodsArray.length(); i++) {
                JSONObject item = goodsArray.optJSONObject(i);
                if (item == null) continue;

                Object goods = goodsClass.getDeclaredConstructor().newInstance();
                applyStringSetter(goods, "setName", optString(item, "name"));
                applyStringSetter(goods, "setPictureUrl", optString(item, "pictureUrl"));
                goodsList.add(goods);
            }
            applyObjectSetter(order, "setGoods", goodsList);
        }

        return order;
    }

    /**
     * 构造 Android 位置消息模型。
     * @param params Unity 参数解析后的 JSON 对象。
     */
    private static Object buildLocation(JSONObject params) throws Exception {
        String lat = optString(params, "lat");
        String lng = optString(params, "lng");
        if (isEmpty(lat) || isEmpty(lng)) {
            Log.w(TAG, "sendLocation ignored: lat and lng are required");
            return null;
        }

        Object location = newSdkObject(SOBOT_LOCATION_CLASS);
        applyStringSetter(location, "setLat", lat);
        applyStringSetter(location, "setLng", lng);
        applyStringSetter(location, "setLocalLabel", optString(params, "localLabel"));
        applyStringSetter(location, "setLocalName", optString(params, "localName"));
        applyStringSetter(location, "setSnapshot", optString(params, "file"));
        return location;
    }

    /**
     * 写入自定义卡片参数。
     * @param info Information 对象。
     * @param params Unity 参数解析后的 JSON 对象。
     */
    private static void applyCustomCard(Object info, JSONObject params) throws Exception {
        JSONObject cardJson = optJSONObject(params, "custom_card");
        if (cardJson == null) return;

        applyObjectSetter(info, "setCustomCard", buildCustomCard(cardJson));
    }

    /**
     * 将 custom_card JSON 转换为 Android SDK 的 SobotChatCustomCard。
     * @param cardJson custom_card 子对象。
     */
    private static Object buildCustomCard(JSONObject cardJson) throws Exception {
        Object card = newSdkObject(CUSTOM_CARD_CLASS);
        applyStringSetter(card, "setOriginalInfo", cardJson.toString());

        Integer type = optInt(cardJson, "type");
        if (type != null) applyIntSetter(card, "setType", type);

        Integer cardStyle = optInt(cardJson, "cardStyle");
        if (cardStyle != null) applyIntSetter(card, "setCardStyle", cardStyle);

        Integer cardType = optInt(cardJson, "cardType");
        if (cardType != null) applyIntSetter(card, "setCardType", cardType);

        Integer isCustomerIdentity = optInt(cardJson, "isCustomerIdentity");
        if (isCustomerIdentity != null) applyIntSetter(card, "setIsCustomerIdentity", isCustomerIdentity);

        applyStringSetter(card, "setCardId", optString(cardJson, "cardId"));
        applyStringSetter(card, "setCardGuide", optString(cardJson, "cardGuide"));
        applyStringSetter(card, "setCardImg", optString(cardJson, "cardImg"));
        applyStringSetter(card, "setCardDesc", optString(cardJson, "cardDesc"));
        applyStringSetter(card, "setCardLink", optString(cardJson, "cardLink"));
        applyStringSetter(card, "setCustomCardLink", optString(cardJson, "customCardLink"));
        applyStringSetter(card, "setNodeId", optString(cardJson, "nodeId"));
        applyStringSetter(card, "setProcessId", optString(cardJson, "processId"));
        applyStringSetter(card, "setInterfaceInfo", optString(cardJson, "interfaceInfo"));

        if (cardJson.has("isOpen")) applyBooleanSetter(card, "setOpen", cardJson.optBoolean("isOpen"));
        if (cardJson.has("isHistory")) applyBooleanSetter(card, "setHistory", cardJson.optBoolean("isHistory"));
        if (cardJson.has("showCustomCardAllMode")) {
            applyBooleanSetter(card, "setShowCustomCardAllMode", cardJson.optBoolean("showCustomCardAllMode"));
        }

        Integer cardForm = optInt(cardJson, "cardForm");
        if (cardForm != null) applyIntSetter(card, "setCardForm", cardForm);

        JSONObject customField = cardJson.optJSONObject("customField");
        if (customField != null) applyObjectSetter(card, "setCustomField", jsonObjectToObjectMap(customField));

        JSONObject ticketPartnerField = cardJson.optJSONObject("ticketPartnerField");
        if (ticketPartnerField != null) applyObjectSetter(card, "setTicketPartnerField", jsonObjectToObjectMap(ticketPartnerField));

        JSONArray cardMenus = cardJson.optJSONArray("cardMenus");
        if (cardMenus != null) applyObjectSetter(card, "setCardMenus", buildCustomMenus(cardMenus));

        JSONArray customCards = cardJson.optJSONArray("customCards");
        if (customCards != null) {
            List<Object> goodsList = new ArrayList<>();
            Class<?> goodsClass = Class.forName(CUSTOM_GOODS_CLASS);
            for (int i = 0; i < customCards.length(); i++) {
                JSONObject item = customCards.optJSONObject(i);
                if (item == null) continue;

                Object goods = goodsClass.getDeclaredConstructor().newInstance();
                applyStringSetter(goods, "setOriginalString", item.toString());
                applyStringSetter(goods, "setCustomCardId", optString(item, "customCardId"));
                applyStringSetter(goods, "setCustomCardName", optString(item, "customCardName"));
                applyStringSetter(goods, "setCustomCardThumbnail", optString(item, "customCardThumbnail"));
                applyStringSetter(goods, "setCustomCardAmount", optString(item, "customCardAmount"));
                applyStringSetter(goods, "setCustomCardAmountSymbol", optString(item, "customCardAmountSymbol"));
                applyStringSetter(goods, "setCustomCardLink", optString(item, "customCardLink"));
                applyStringSetter(goods, "setCustomCardDesc", optString(item, "customCardDesc"));
                applyStringSetter(goods, "setCustomCardTime", optString(item, "customCardTime"));
                applyStringSetter(goods, "setCustomCardCount", optString(item, "customCardCount"));
                applyStringSetter(goods, "setCustomCardCode", optString(item, "customCardCode"));
                applyStringSetter(goods, "setCustomCardStatus", optString(item, "customCardStatus"));
                applyStringSetter(goods, "setCustomCardQuestion", optString(item, "customCardQuestion"));

                Integer customCardType = optInt(item, "customCardType");
                if (customCardType != null) applyIntSetter(goods, "setCustomCardType", customCardType);

                JSONObject goodsCustomField = item.optJSONObject("customField");
                if (goodsCustomField != null) applyObjectSetter(goods, "setCustomField", jsonObjectToStringMap(goodsCustomField));

                JSONArray customMenus = item.optJSONArray("customMenus");
                if (customMenus != null) applyObjectSetter(goods, "setCustomMenus", buildCustomMenus(customMenus));

                goodsList.add(goods);
            }
            applyObjectSetter(card, "setCustomCards", goodsList);
        }

        return card;
    }

    /**
     * 构造自定义卡片菜单列表。
     * @param menuArray 菜单数组。
     */
    private static List<Object> buildCustomMenus(JSONArray menuArray) throws Exception {
        List<Object> menus = new ArrayList<>();
        Class<?> menuClass = Class.forName(CUSTOM_MENU_CLASS);
        for (int i = 0; i < menuArray.length(); i++) {
            JSONObject item = menuArray.optJSONObject(i);
            if (item == null) continue;

            Object menu = menuClass.getDeclaredConstructor().newInstance();
            Integer menuId = optInt(item, "menuId");
            if (menuId != null) applyIntSetter(menu, "setMenuId", menuId);
            applyBooleanSetter(menu, "setDisable", item.optBoolean("isDisable"));
            applyStringSetter(menu, "setMenuName", optString(item, "menuName"));
            applyStringSetter(menu, "setMenuLink", optString(item, "menuLink"));
            applyIntSetter(menu, "setMenuType", item.optInt("menuType"));
            applyIntSetter(menu, "setMenuLinkType", item.optInt("menuLinkType"));
            applyStringSetter(menu, "setMenuTip", optString(item, "menuTip"));
            menus.add(menu);
        }
        return menus;
    }

    /**
     * 读取对象字段，兼容字段值本身就是 JSON 字符串的情况。
     * @param params 参数 JSON 对象。
     * @param key 字段名。
     */
    private static JSONObject optJSONObject(JSONObject params, String key) {
        Object value = params.opt(key);
        if (value instanceof JSONObject) return (JSONObject) value;
        if (!(value instanceof String)) return null;

        try {
            String json = (String) value;
            return isEmpty(json) ? null : new JSONObject(json);
        } catch (Exception ignored) {
            return null;
        }
    }

    /**
     * 读取数组字段，兼容字段值本身就是 JSON 字符串的情况。
     * @param params 参数 JSON 对象。
     * @param key 字段名。
     */
    private static JSONArray optJSONArray(JSONObject params, String key) {
        Object value = params.opt(key);
        if (value instanceof JSONArray) return (JSONArray) value;
        if (!(value instanceof String)) return null;

        try {
            String json = (String) value;
            return isEmpty(json) ? null : new JSONArray(json);
        } catch (Exception ignored) {
            return null;
        }
    }

    /**
     * 将 JSONObject 转换为 Object Map，保留数组和对象结构。
     * @param json 待转换的 JSONObject。
     */
    private static Map<String, Object> jsonObjectToObjectMap(JSONObject json) {
        Map<String, Object> map = new HashMap<>();
        Iterator<String> keys = json.keys();
        while (keys.hasNext()) {
            String key = keys.next();
            Object value = json.opt(key);
            if (value instanceof JSONObject) {
                map.put(key, jsonObjectToObjectMap((JSONObject) value));
            } else if (value instanceof JSONArray) {
                map.put(key, jsonArrayToList((JSONArray) value));
            } else {
                map.put(key, value);
            }
        }
        return map;
    }

    /**
     * 将 JSONObject 转换为字符串 Map，便于 Android SDK 直接消费。
     * @param json 待转换的 JSONObject。
     */
    private static Map<String, String> jsonObjectToStringMap(JSONObject json) {
        Map<String, String> map = new HashMap<>();
        Iterator<String> keys = json.keys();
        while (keys.hasNext()) {
            String key = keys.next();
            map.put(key, optString(json, key));
        }
        return map;
    }

    /**
     * 将 JSONArray 转换为普通 List。
     * @param array 待转换的 JSONArray。
     */
    private static List<Object> jsonArrayToList(JSONArray array) {
        List<Object> list = new ArrayList<>();
        for (int i = 0; i < array.length(); i++) {
            Object value = array.opt(i);
            if (value instanceof JSONObject) {
                list.add(jsonObjectToObjectMap((JSONObject) value));
            } else if (value instanceof JSONArray) {
                list.add(jsonArrayToList((JSONArray) value));
            } else {
                list.add(value);
            }
        }
        return list;
    }

    /**
     * 设置私有化或指定环境的 API Host。
     * @param api_host 需要写入的接口地址。
     */
    private static void applyApiHost(String api_host) {
        if (isEmpty(api_host)) return;
        String[] classNames = {
            "com.sobot.chat.SobotBaseUrl",
            "com.sobot.chat.api.SobotBaseUrl"
        };
        for (String className : classNames) {
            try {
                Class<?> clazz = Class.forName(className);
                Method method = clazz.getMethod("setApi_Host", String.class);
                method.invoke(null, api_host);
                return;
            } catch (Exception ignored) {
                Log.d(TAG, "skip unsupported api_host setter: " + className);
            }
        }
    }

    /**
     * 按类名创建 Android SDK 对象。
     * @param className Android SDK 的完整类名。
     */
    private static Object newSdkObject(String className) throws Exception {
        return Class.forName(className).getDeclaredConstructor().newInstance();
    }

    /**
     * 兼容不同版本 Android SDK 的静态方法调用。
     * @param methodName Android SDK 静态方法名。
     * @param args 静态方法参数。
     */
    private static void invokeSobotApi(String methodName, Object... args) throws Exception {
        Method method = findCompatibleStaticMethod(ZCSobotApi.class, methodName, args);
        if (method == null) {
            throw new NoSuchMethodException(methodName);
        }
        method.invoke(null, args);
    }

    /**
     * 查找参数数量和类型兼容的静态方法。
     * @param clazz 目标类。
     * @param methodName 方法名。
     * @param args 方法参数。
     */
    private static Method findCompatibleStaticMethod(Class<?> clazz, String methodName, Object[] args) {
        Method[] methods = clazz.getMethods();
        for (Method method : methods) {
            if (!method.getName().equals(methodName)) continue;

            Class<?>[] parameterTypes = method.getParameterTypes();
            if (parameterTypes.length != args.length) continue;

            boolean compatible = true;
            for (int i = 0; i < parameterTypes.length; i++) {
                if (!isCompatibleParam(parameterTypes[i], args[i])) {
                    compatible = false;
                    break;
                }
            }
            if (compatible) return method;
        }
        return null;
    }

    /**
     * 判断反射调用参数是否可赋值或可自动装箱。
     * @param parameterType 方法参数类型。
     * @param arg 实际参数对象。
     */
    private static boolean isCompatibleParam(Class<?> parameterType, Object arg) {
        if (arg == null) return !parameterType.isPrimitive();
        if (parameterType.isPrimitive()) {
            if (parameterType == boolean.class) return arg instanceof Boolean;
            if (parameterType == int.class) return arg instanceof Integer;
            if (parameterType == long.class) return arg instanceof Long;
            if (parameterType == float.class) return arg instanceof Float;
            if (parameterType == double.class) return arg instanceof Double;
            if (parameterType == byte.class) return arg instanceof Byte;
            if (parameterType == short.class) return arg instanceof Short;
            if (parameterType == char.class) return arg instanceof Character;
            return false;
        }
        return parameterType.isAssignableFrom(arg.getClass());
    }

    /**
     * 安全调用字符串 setter，空值不写入。
     *
     * @param target 目标对象。
     * @param methodName setter 名称。
     * @param value 要写入的字符串值。
     */
    private static void applyStringSetter(Object target, String methodName, String value) {
        if (isEmpty(value)) return;
        try {
            Method method = target.getClass().getMethod(methodName, String.class);
            method.invoke(target, value);
        } catch (Exception ignored) {
            Log.d(TAG, "skip unsupported setter: " + methodName);
        }
    }

    /**
     * 安全调用 int setter。
     *
     * @param target 目标对象。
     * @param methodName setter 名称。
     * @param value 要写入的整数值。
     */
    private static void applyIntSetter(Object target, String methodName, int value) {
        applyIntSetter(target, methodName, Integer.valueOf(value));
    }

    /**
     * 安全调用可空 int setter。
     *
     * @param target 目标对象。
     * @param methodName setter 名称。
     * @param value 要写入的可空整数值。
     */
    private static void applyIntSetter(Object target, String methodName, Integer value) {
        if (value == null) return;
        try {
            Method method = target.getClass().getMethod(methodName, int.class);
            method.invoke(target, value.intValue());
        } catch (Exception ignored) {
            Log.d(TAG, "skip unsupported setter: " + methodName);
        }
    }

    /**
     * 安全调用对象 setter。
     *
     * @param target 目标对象。
     * @param methodName setter 名称。
     * @param value 要写入的对象值。
     */
    private static void applyObjectSetter(Object target, String methodName, Object value) {
        if (value == null) return;
        try {
            Method method = findCompatibleInstanceMethod(target.getClass(), methodName, value);
            if (method == null) {
                Log.d(TAG, "skip unsupported setter: " + methodName);
                return;
            }
            method.invoke(target, value);
        } catch (Exception ignored) {
            Log.d(TAG, "skip unsupported setter: " + methodName);
        }
    }

    /**
     * 仅在参数存在时调用 boolean setter。
     *
     * @param target 目标对象。
     * @param methodName setter 名称。
     * @param params 参数 JSON 对象。
     * @param key 字段名。
     */
    private static void applyOptionalBooleanSetter(Object target, String methodName, JSONObject params, String key) {
        if (!params.has(key)) return;
        applyBooleanSetter(target, methodName, params.optBoolean(key));
    }

    /**
     * 查找参数类型兼容的实例方法。
     *
     * @param clazz 目标类。
     * @param methodName 方法名。
     * @param arg 实际参数对象。
     */
    private static Method findCompatibleInstanceMethod(Class<?> clazz, String methodName, Object arg) {
        Method[] methods = clazz.getMethods();
        for (Method method : methods) {
            if (!method.getName().equals(methodName)) continue;

            Class<?>[] parameterTypes = method.getParameterTypes();
            if (parameterTypes.length != 1) continue;
            if (isCompatibleParam(parameterTypes[0], arg)) return method;
        }
        return null;
    }

    /**
     * 安全调用 boolean setter。
     *
     * @param target 目标对象。
     * @param methodName setter 名称。
     * @param value 要写入的布尔值。
     */
    private static void applyBooleanSetter(Object target, String methodName, boolean value) {
        try {
            Method method = target.getClass().getMethod(methodName, boolean.class);
            method.invoke(target, value);
            Log.d(TAG, "set boolean " + methodName + "=" + value);
        } catch (Exception ignored) {
            Log.d(TAG, "skip unsupported setter: " + methodName);
        }
    }
}
