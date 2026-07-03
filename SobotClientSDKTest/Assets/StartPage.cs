using System.Collections;
using System.Collections.Generic;
using SobotChatClient;
using UnityEngine;

/// <summary>
/// 智齿 SDK 功能测试 Demo
/// 适配 iOS 和 Android 双平台
/// </summary>
public class StartPage : MonoBehaviour
{
    // 替换为你在智齿管理平台获取的 AppKey
    private const string APP_KEY = "1c1da2c0aad047d7ba1d14ecd18ae4f6";

    // 用户唯一标识（实际使用时应传入真实用户 ID，不能写死）
    private const string PARTNER_ID = "znw12345";

    private string _statusMessage = "请先点击「初始化」";
    private bool _isInitialized = false;
    private Vector2 _scrollPosition = Vector2.zero;

    void Start()
    {
        RegisterLinkClickListener();
        RegisterFunctionClickListener();
    }

    void OnGUI()
    {
        // 适配不同屏幕尺寸
        float scale = Screen.dpi / 160f;
        if (scale < 1f) scale = 1f;

        int btnWidth = (int)(240 * scale);
        int btnHeight = (int)(80 * scale);
        int fontSize = (int)(20 * scale);

        GUIStyle btnStyle = new GUIStyle(GUI.skin.button);
        btnStyle.fontSize = fontSize;

        GUIStyle labelStyle = new GUIStyle(GUI.skin.label);
        labelStyle.fontSize = fontSize;
        labelStyle.wordWrap = true;

        GUILayout.BeginArea(new Rect(20, 20, Screen.width - 40, Screen.height - 40));
        _scrollPosition = GUILayout.BeginScrollView(_scrollPosition);

        // 状态提示
        GUILayout.Label("状态: " + _statusMessage, labelStyle);
        GUILayout.Space(10);

        // 注册链接点击监听
        if (GUILayout.Button("注册链接监听", btnStyle, GUILayout.Width(btnWidth), GUILayout.Height(btnHeight)))
        {
            RegisterLinkClickListener();
            _statusMessage = "链接监听已注册";
        }

        GUILayout.Space(10);

        // 注册功能点击监听
        if (GUILayout.Button("注册功能点击监听", btnStyle, GUILayout.Width(btnWidth), GUILayout.Height(btnHeight)))
        {
            RegisterFunctionClickListener();
            _statusMessage = "功能点击监听已注册";
        }

        GUILayout.Space(10);

        // 初始化
        if (GUILayout.Button("智齿初始化", btnStyle, GUILayout.Width(btnWidth), GUILayout.Height(btnHeight)))
        {
            _statusMessage = "初始化中...";
            ZCSobotApi.initSobotSDK(CreateDemoParams(), (success, msg) =>
            {
                _isInitialized = success;
                _statusMessage = success ? "初始化成功" : $"初始化失败: {msg}";
                Debug.Log($"[Demo] 初始化结果: {success}, {msg}");
            });
        }

        GUILayout.Space(10);

        // 启动帮助中心
        if (GUILayout.Button("启动帮助中心", btnStyle, GUILayout.Width(btnWidth), GUILayout.Height(btnHeight)))
        {
            if (!_isInitialized)
            {
                _statusMessage = "请先初始化 SDK";
            }
            else
            {
                _statusMessage = "打开帮助中心...";
                ZCSobotApi.openSobotHelpCenter(CreateDemoParams());
            }
        }

        GUILayout.Space(10);

        // 启动客服聊天
        if (GUILayout.Button("启动客服聊天", btnStyle, GUILayout.Width(btnWidth), GUILayout.Height(btnHeight)))
        {
            if (!_isInitialized)
            {
                _statusMessage = "请先初始化 SDK";
            }
            else
            {
                _statusMessage = "打开客服聊天...";
                ZCSobotApi.openSobotChat(CreateDemoParams());
            }
        }

        GUILayout.Space(10);

        // 启动留言
        if (GUILayout.Button("启动留言", btnStyle, GUILayout.Width(btnWidth), GUILayout.Height(btnHeight)))
        {
            if (!_isInitialized)
            {
                _statusMessage = "请先初始化 SDK";
            }
            else
            {
                _statusMessage = "打开留言页面...";
                ZCSobotApi.openSobotLeave(CreateDemoParams());
            }
        }

        GUILayout.Space(10);

        // 获取未读消息数
        if (GUILayout.Button("获取未读消息数", btnStyle, GUILayout.Width(btnWidth), GUILayout.Height(btnHeight)))
        {
            if (!_isInitialized)
            {
                _statusMessage = "请先初始化 SDK";
            }
            else
            {
                ZCSobotApi.getUnReadMessage(CreateDemoParams(), (unRead, offline, unAck) =>
                {
                    _statusMessage = $"未读:{unRead} 离线:{offline} 未确认:{unAck}";
                    Debug.Log($"[Demo] 消息数 - 未读:{unRead}, 离线:{offline}, 未确认:{unAck}");
                });
            }
        }

        GUILayout.Space(10);

        // 主动发送自定义卡片
        if (GUILayout.Button("发送自定义卡片", btnStyle, GUILayout.Width(btnWidth), GUILayout.Height(btnHeight)))
        {
            if (EnsureDemoReadyForSend())
            {
                _statusMessage = "已调用发送自定义卡片，请在聊天页观察";
                ZCSobotApi.sendCustomCardToChat(CreateDemoParams(), OnSendMessageResult);
            }
        }

        GUILayout.Space(10);

        // 主动发送商品卡片
        if (GUILayout.Button("发送商品卡片", btnStyle, GUILayout.Width(btnWidth), GUILayout.Height(btnHeight)))
        {
            if (EnsureDemoReadyForSend())
            {
                _statusMessage = "已调用发送商品卡片，请在聊天页观察";
                ZCSobotApi.sendProductInfo(CreateDemoParams(), OnSendMessageResult);
            }
        }

        GUILayout.Space(10);

        // 主动发送订单卡片
        if (GUILayout.Button("发送订单卡片", btnStyle, GUILayout.Width(btnWidth), GUILayout.Height(btnHeight)))
        {
            if (EnsureDemoReadyForSend())
            {
                _statusMessage = "已调用发送订单卡片，请在聊天页观察";
                ZCSobotApi.sendOrderGoodsInfo(CreateDemoParams(), OnSendMessageResult);
            }
        }

        GUILayout.Space(10);

        // 主动发送定位消息
        if (GUILayout.Button("发送定位消息", btnStyle, GUILayout.Width(btnWidth), GUILayout.Height(btnHeight)))
        {
            if (EnsureDemoReadyForSend())
            {
                _statusMessage = "已调用发送定位消息，请在聊天页观察";
                ZCSobotApi.sendLocation(CreateDemoParams(), OnSendMessageResult);
            }
        }

        GUILayout.Space(10);

        // 关闭会话
        if (GUILayout.Button("关闭会话", btnStyle, GUILayout.Width(btnWidth), GUILayout.Height(btnHeight)))
        {
            _statusMessage = "会话已关闭";
            ZCSobotApi.closeSobotChat(CreateDemoParams());
        }

        GUILayout.EndScrollView();
        GUILayout.EndArea();
    }

    /// <summary>
    /// 链接点击回调
    /// </summary>
    /// <returns>true 拦截，false 由 SDK 处理</returns>
    private bool OnLinkClick(string url)
    {
        Debug.Log($"[Demo] 链接点击: {url}");
        _statusMessage = $"链接: {url}";

        // 示例：拦截特定链接
        if (url != null && url.Contains("www.sobot.com"))
        {
            Debug.Log("[Demo] 拦截 sobot:// 协议链接");
            return true;
        }
        return false;
    }

    /// <summary>
    /// 功能点击回调，包含留言返回、客服服务中心返回、电商消息中心返回、聊天返回、点击电话按钮等事件。
    /// </summary>
    private void OnFunctionClick(int type)
    {
        Debug.Log($"[Demo] 功能点击事件: {GetFunctionClickTypeName(type)}({type})");
        _statusMessage = $"功能点击: {GetFunctionClickTypeName(type)}({type})";
    }

    private void OnSendMessageResult(bool success, int code, string message)
    {
        _statusMessage = success ? $"发送成功: {message}" : $"发送失败({code}): {message}";
        Debug.Log($"[Demo] 主动发送结果: success={success}, code={code}, message={message}");
    }

    private void RegisterLinkClickListener()
    {
        ZCSobotApi.setMessageLinkClick(OnLinkClick);
        Debug.Log("[Demo] 链接监听已注册");
    }

    private void RegisterFunctionClickListener()
    {
        ZCSobotApi.setFunctionClickListener(OnFunctionClick);
        Debug.Log("[Demo] 功能点击监听已注册");
    }

    private bool EnsureDemoReadyForSend()
    {
        if (_isInitialized) return true;

        _statusMessage = "请先初始化 SDK，并进入聊天页面后再发送";
        return false;
    }

    private string GetFunctionClickTypeName(int type)
    {
        switch (type)
        {
            case 1: return "留言返回";
            case 2: return "聊天返回";
            case 3: return "帮助中心返回";
            case 4: return "电商消息中心返回";
            case 5: return "点击电话按钮";
            case 6: return "帮助中心加载";
            case 7: return "聊天页面加载";
            case 8: return "留言页面加载";
            case 9: return "留言页返回";
            default: return "未知事件";
        }
    }

    private SobotParams CreateDemoParams()
    {
        return new SobotParams
        {
            api_host = "https://www.sobot.com",
            app_key = APP_KEY,
            partnerid = PARTNER_ID,
            user_nick = "智齿unity用户",
            user_name = "智齿unity用户",
            user_tels = "18510002000",
            user_emails = "123@qq.com",
            qq = "123456789",
            choose_adminid = "79727dec062943faafca9d83fe36c88c",
            remark = "好好学习，天天向上",
            @params = CreateDemoExtParamsJson(),
            landscape_screen = false,
            isLandscapeMode = false,
            showNotification = true,
            deviceToken = "",
            custom_card = CreateDemoCustomCardJson(),
            isShowReturnTips = true,
            isShowClose = true,
            isShowCloseSatisfaction = true,
            isCloseAfterEvaluation = true,
            isOpenEvaluation = true,
            isShowEvaluation = true,
            goodsTitle = "商品名字",
            goodsLabel = "30.5$",
            goodsDesc = "商品描述",
            goodsImage = "https://img.sobot.com/chatres/75574e5fa29a48458d1f57ab5489a4c5/msg/20200612/75574e5fa29a48458d1f57ab5489a4c5123456789/aae707c620744e92bb112de8b67cd3ed.png",
            goodsLink = "https://home.firefoxchina.cn/",
            isSendInfoCard = true,
            isEveryTimeSendCard = true,
            goods = CreateDemoGoodsJson(),
            orderUrl = "https://www.sobot.com",
            statusCustom = "已发货",
            orderStatus = "0",
            orderCode = "v2131232132",
            goodsCount = "2",
            totalFee = "3034",
            createTime = "1569491413000",
            lat = "39.908823",
            lng = "116.397470",
            localLabel = "北京市东城区东长安街",
            localName = "天安门",
            file = "",
            autoSendOrderMessage = true,
            isEveryTimeAutoSend = true,
            absolute_language = "en_lproj",
            hideRototEvaluationLabels = true,
            hideManualEvaluationLabels = true,
            good_msg_type = 2,
            content = "我是unity传过来的数据，要发送消息"
        };
    }

    private string CreateDemoExtParamsJson()
    {
        return @"{
  ""deviceid"": ""iOS"",
  ""actionType"": ""to_group"",
  ""optionId"": ""4"",
  ""deciId"": ""a457f4dfe92842f8a11d1616c1c58dc1"",
  ""key2"": ""123456""
}";
    }

    private string CreateDemoGoodsJson()
    {
        return @"[
  {
    ""name"": ""商品名称111"",
    ""pictureUrl"": ""https://img1.baidu.com/it/u=1086264495,2583232026&fm=253&fmt=auto&app=138&f=JPEG?w=500&h=500""
  },
  {
    ""name"": ""商品名称222"",
    ""pictureUrl"": ""https://img.sobot.com/console/common/face/admin.png""
  }
]";
    }

    private string CreateDemoCustomCardJson()
    {
        return @"{
        ""isCustomerIdentity"":1,
  ""cardDesc"": ""测试的是的方式测试的是的方式测试的是的方式测试的是的方式测试的是的方式测试的是的方式测试的是的方式"",
  ""cardGuide"": ""测试标题 引导语测试标题 引导语测试标题 引导语测试标题 引导语测试标题 引导语测试标题 引导语测试标题 引导语"",
  ""cardId"": ""cardId121212vv12"",
  ""cardImg"": ""https://hk.sobot.com/auth/_next/static/media/sideZh.74024132.png"",
  ""cardMenus"": [
    {
      ""isDisable"": false,
      ""menuId"": 0,
      ""menuLink"": ""胜多负少士大夫胜多负少士大夫胜多负少士大夫胜多负少士大夫"",
      ""menuLinkType"": 0,
      ""menuName"": ""发送"",
      ""menuTip"": ""发送提示"",
      ""menuType"": 2
    },
    {
      ""isDisable"": false,
      ""menuId"": 0,
      ""menuLink"": ""胜多负少士大夫"",
      ""menuLinkType"": 2,
      ""menuName"": ""确认"",
      ""menuTip"": ""发送提示"",
      ""menuType"": 1
    },
    {
      ""isDisable"": false,
      ""menuId"": 0,
      ""menuLink"": ""胜多负少士大夫"",
      ""menuLinkType"": 2,
      ""menuName"": ""查看详情手动阀手动阀是的发士大夫士大夫士大夫是的发士大夫"",
      ""menuTip"": ""发送提示"",
      ""menuType"": 0
    }
  ],
  ""cardStyle"": 1,
  ""cardType"": 1,
  ""customCards"": [
    {
      ""customCardAmount"": ""222.9"",
      ""customCardAmountSymbol"": ""￥"",
      ""customCardCode"": ""sobot121u321u3"",
      ""customCardCount"": ""5"",
      ""customCardDesc"": ""测试邮箱我是的就就的的的是是我我我的的的嗡嗡嗡嗡嗡嗡嗡嗡嗡问问二位问问额嗡嗡嗡嗡嗡嗡为微软微软微软微软微软微软"",
      ""customCardId"": ""cardId_0"",
      ""customCardName"": ""0测试邮箱我是的就就的的的是是我我我的的的嗡嗡嗡嗡嗡嗡嗡嗡嗡问问二位问问额嗡嗡嗡嗡嗡嗡为微软微软微软微软微软微软"",
      ""customCardStatus"": ""待收货"",
      ""customCardThumbnail"": ""https://hk.sobot.com/auth/_next/static/media/sideZh.74024132.png"",
      ""customCardTime"": ""2023-06-25 14:32:21"",
      ""customMenus"": [
        {
          ""isDisable"": false,
          ""menuId"": 0,
          ""menuLink"": ""胜多负少士大夫胜多负少士大夫胜多负少士大夫胜多负少士大夫"",
          ""menuLinkType"": 0,
          ""menuName"": ""发送"",
          ""menuTip"": ""发送提示"",
          ""menuType"": 2
        }
      ]
    },
    {
      ""customCardAmount"": ""222.9"",
      ""customCardAmountSymbol"": ""￥"",
      ""customCardCode"": ""sobot121u321u3"",
      ""customCardCount"": ""5"",
      ""customCardDesc"": ""测试邮箱我是的就就的的的是是我我我的的的嗡嗡嗡嗡嗡嗡嗡嗡嗡问问二位问问额嗡嗡嗡嗡嗡嗡为微软微软微软微软微软微软"",
      ""customCardId"": ""cardId_1"",
      ""customCardName"": ""1测试邮箱我是的就就的的的是是我我我的的的嗡嗡嗡嗡嗡嗡嗡嗡嗡问问二位问问额嗡嗡嗡嗡嗡嗡为微软微软微软微软微软微软"",
      ""customCardStatus"": ""待收货"",
      ""customCardThumbnail"": ""https://hk.sobot.com/auth/_next/static/media/sideZh.74024132.png"",
      ""customCardTime"": ""2023-06-25 14:32:21"",
      ""customMenus"": [
        {
          ""isDisable"": false,
          ""menuId"": 0,
          ""menuLink"": ""胜多负少士大夫胜多负少士大夫胜多负少士大夫胜多负少士大夫"",
          ""menuLinkType"": 0,
          ""menuName"": ""发送"",
          ""menuTip"": ""发送提示"",
          ""menuType"": 2
        },
        {
          ""isDisable"": false,
          ""menuId"": 0,
          ""menuLink"": ""胜多负少士大夫"",
          ""menuLinkType"": 2,
          ""menuName"": ""确认"",
          ""menuTip"": ""发送提示"",
          ""menuType"": 1
        }
      ]
    },
    {
      ""customCardAmount"": ""222.9"",
      ""customCardAmountSymbol"": ""￥"",
      ""customCardCode"": ""sobot121u321u3"",
      ""customCardCount"": ""5"",
      ""customCardDesc"": ""测试邮箱我是的就就的的的是是我我我的的的嗡嗡嗡嗡嗡嗡嗡嗡嗡问问二位问问额嗡嗡嗡嗡嗡嗡为微软微软微软微软微软微软"",
      ""customCardId"": ""cardId_2"",
      ""customCardName"": ""2测试邮箱我是的就就的的的是是我我我的的的嗡嗡嗡嗡嗡嗡嗡嗡嗡问问二位问问额嗡嗡嗡嗡嗡嗡为微软微软微软微软微软微软"",
      ""customCardStatus"": ""待收货"",
      ""customCardThumbnail"": ""https://hk.sobot.com/auth/_next/static/media/sideZh.74024132.png"",
      ""customCardTime"": ""2023-06-25 14:32:21"",
      ""customMenus"": [
        {
          ""isDisable"": false,
          ""menuId"": 0,
          ""menuLink"": ""胜多负少士大夫胜多负少士大夫胜多负少士大夫胜多负少士大夫"",
          ""menuLinkType"": 0,
          ""menuName"": ""发送"",
          ""menuTip"": ""发送提示"",
          ""menuType"": 2
        },
        {
          ""isDisable"": false,
          ""menuId"": 0,
          ""menuLink"": ""胜多负少士大夫"",
          ""menuLinkType"": 2,
          ""menuName"": ""确认"",
          ""menuTip"": ""发送提示"",
          ""menuType"": 1
        },
        {
          ""isDisable"": false,
          ""menuId"": 0,
          ""menuLink"": ""胜多负少士大夫"",
          ""menuLinkType"": 2,
          ""menuName"": ""查看详情手动阀手动阀是的发士大夫士大夫士大夫是的发士大夫"",
          ""menuTip"": ""发送提示"",
          ""menuType"": 0
        }
      ]
    }
  ],
  ""customField"": {
    ""顶顶顶2"": ""399"",
    ""顶顶顶3"": ""399"",
    ""测试"": ""0999999999999990"",
    ""顶顶ew顶"": ""399"",
    ""顶顶wer顶"": ""399"",
    ""顶顶s顶"": ""399"",
    ""顶顶顶"": ""399"",
    ""顶顶3顶"": ""399"",
    ""顶顶we顶"": ""399"",
    ""顶顶2顶"": ""399"",
    ""顶顶1顶"": ""399""
  },
  ""isOpen"": false,
  ""showCustomCardAllMode"": true
}";
    }
}
