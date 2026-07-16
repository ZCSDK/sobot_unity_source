using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using UnityEngine;

namespace SobotChatClient
{
    /// <summary>
    /// 智齿 SDK 统一参数对象，字段命名对齐 UNI ZhiChiApiOptions 和智齿原生 SDK。
    /// </summary>
    [Serializable]
    public class SobotParams
    {
        public string api_host;
        public string app_key;
        public string partnerid;
        public string choose_adminid;
        public string tran_flag;

        public string user_nick;
        public string user_name;
        public string user_tels;
        public string user_emails;
        public string isVip;
        public string vip_level;
        public string user_label;
        public string qq;
        public string face;
        public string remark;
        public string @params;
        public string customer_fields;
        public string multi_params;

        public string groupid;
        public string group_name;
        public int good_msg_type;
        public string content;

        public string absolute_language;
        public string urlRegular;
        public string telRegular;

        public bool isOpenRecord;
        public bool isOpenRobotVoice;
        public bool isShowReturnTips;
        public bool isShowClose;
        public bool isOpenEvaluation;
        public bool isShowEvaluation;
        public bool isShowCloseSatisfaction;
        public bool isCloseAfterEvaluation;
        public bool canBackWithNotEvaluation;
        public bool hideRototEvaluationLabels;
        public bool hideManualEvaluationLabels;

        public string leaveMsgGroupId;
        public bool leaveCompleteCanReply;
        public bool isShowLog;

        public bool landscape_screen;
        public bool isLandscapeMode;
        public bool showNotification;

        public bool isShowPortrait;
        public bool ishidesBottomBarWhenPushed;
        public bool navcBarHidden;
        public bool isUseImagesxcassets;
        public string deviceToken;
        public bool autoNotification;
        public string custom_card;

        public string goodsTitle;
        public string goodsDesc;
        public string goodsLabel;
        public string goodsLink;
        public string goodsImage;
        public bool isSendInfoCard;
        public bool isEveryTimeSendCard;

        public string orderCode;
        public string orderStatus;
        public string statusCustom;
        public string createTime;
        public string goodsCount;
        public string orderUrl;
        public string goods;
        public string totalFee;
        public bool autoSendOrderMessage;
        public bool isEveryTimeAutoSend;

        public string lat;
        public string lng;
        public string localLabel;
        public string localName;
        public string file;

        public string cusMoreArray;
        public bool closePush;
    }

    /// <summary>
    /// 智齿客服 SDK Unity 封装。
    /// </summary>
    public class ZCSobotApi : MonoBehaviour
    {
        private static ZCSobotApi _instance;

        /// <summary>
        /// 获取单例桥接对象，用于接收 iOS 的 UnitySendMessage 回调。
        /// 该对象会在首次访问时自动创建并常驻场景。
        /// </summary>
        public static ZCSobotApi Instance
        {
            get
            {
                if (_instance == null)
                {
                    GameObject go = new GameObject("ZCSobotApi");
                    _instance = go.AddComponent<ZCSobotApi>();
                    DontDestroyOnLoad(go);
                }
                return _instance;
            }
        }

        /// <summary>初始化结果回调。</summary>
        public delegate void InitResultCallback(bool success, string message);
        /// <summary>离线消息数回调，返回未读、离线和未确认数量。</summary>
        public delegate void OfflineMsgCallback(int unReadSize, int offlineSize, int unAckSize);
        /// <summary>链接点击回调，返回 <c>true</c> 表示由 Unity 侧拦截处理。</summary>
        public delegate bool LinkClickCallback(string linkUrl);
        /// <summary>功能按钮点击回调。</summary>
        public delegate void FunctionClickCallback(int type);
        /// <summary>主动发送消息结果回调。</summary>
        public delegate void SendMessageResultCallback(bool success, int code, string message);

        private static InitResultCallback _initCallback;
        private static OfflineMsgCallback _offlineMsgCallback;
        private static LinkClickCallback _linkClickCallback;
        private static FunctionClickCallback _functionClickCallback;
        private static bool _isInitialized;
        private static int _sendRequestSeq;
        private static readonly Dictionary<string, SendMessageResultCallback> _sendCallbacks =
            new Dictionary<string, SendMessageResultCallback>();

#if UNITY_IOS && !UNITY_EDITOR
        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        [return: MarshalAs(UnmanagedType.I1)]
        private delegate bool IOSLinkClickCallback([MarshalAs(UnmanagedType.LPStr)] string url);

        [UnmanagedFunctionPointer(CallingConvention.Cdecl)]
        private delegate void IOSFunctionClickCallback(int type);

        private static readonly IOSLinkClickCallback _iosLinkClickCallback = OnIOSLinkClick;
        private static readonly IOSFunctionClickCallback _iosFunctionClickCallback = OnIOSFunctionClick;

        [DllImport("__Internal")]
        /// <summary>iOS 初始化入口，对应 <c>SobotUnityBridge.mm</c> 中的 <c>_sobotInitSDK</c>。</summary>
        private static extern void _sobotInitSDK(string paramJson, string gameObjectName, string callbackMethod);

        [DllImport("__Internal")]
        /// <summary>iOS 打开客服聊天入口。</summary>
        private static extern void _sobotOpenChat(string paramJson);

        [DllImport("__Internal")]
        /// <summary>iOS 打开帮助中心入口。</summary>
        private static extern void _sobotOpenServiceCenter(string paramJson);

        [DllImport("__Internal")]
        /// <summary>iOS 打开留言入口。</summary>
        private static extern void _sobotOpenLeave(string paramJson);

        [DllImport("__Internal")]
        /// <summary>iOS 关闭当前会话入口。</summary>
        private static extern void _sobotCloseSession([MarshalAs(UnmanagedType.I1)] bool closePush);

        [DllImport("__Internal")]
        /// <summary>iOS 获取离线消息数入口。</summary>
        private static extern void _sobotGetOfflineMsg(string paramJson, string gameObjectName, string callbackMethod);

        [DllImport("__Internal")]
        /// <summary>iOS 注册链接点击监听。</summary>
        private static extern void _sobotSetLinkClickListener(IOSLinkClickCallback callback);

        [DllImport("__Internal")]
        /// <summary>iOS 注册功能按钮点击监听。</summary>
        private static extern void _sobotSetFunctionClickListener(IOSFunctionClickCallback callback);

        [DllImport("__Internal")]
        /// <summary>iOS 主动发送自定义卡片入口。</summary>
        private static extern void _sobotSendCustomCardToChat(string paramJson, string gameObjectName, string callbackMethod, string requestId);

        [DllImport("__Internal")]
        /// <summary>iOS 主动发送商品卡片入口。</summary>
        private static extern void _sobotSendProductInfo(string paramJson, string gameObjectName, string callbackMethod, string requestId);

        [DllImport("__Internal")]
        /// <summary>iOS 主动发送订单卡片入口。</summary>
        private static extern void _sobotSendOrderGoodsInfo(string paramJson, string gameObjectName, string callbackMethod, string requestId);

        [DllImport("__Internal")]
        /// <summary>iOS 主动发送定位消息入口。</summary>
        private static extern void _sobotSendLocation(string paramJson, string gameObjectName, string callbackMethod, string requestId);
#endif

#if UNITY_ANDROID && !UNITY_EDITOR
        private static AndroidJavaClass _bridge;
        private static AndroidJavaClass Bridge
        {
            get
            {
                if (_bridge == null)
                    _bridge = new AndroidJavaClass("com.sobot.unity.SobotBridge");
                return _bridge;
            }
        }
#endif

        /// <summary>
        /// 初始化智齿 SDK。
        /// Unity 侧会根据当前平台分发到 Editor 模拟、Android 原生桥接或 iOS 原生桥接。
        /// </summary>
        /// <param name="param">初始化参数，至少需要包含 `app_key`，可选传入 `api_host` 和用户信息。</param>
        /// <param name="callback">初始化结果回调，返回成功状态和错误信息。</param>
        public static void initSobotSDK(SobotParams param, InitResultCallback callback = null)
        {
            _initCallback = callback;
            _isInitialized = false;
            var inst = Instance;

#if UNITY_EDITOR
            Debug.Log($"[SobotSDK] initSobotSDK app_key={param?.app_key}");
            _isInitialized = true;
            callback?.Invoke(true, "Editor模式，模拟初始化成功");

#elif UNITY_ANDROID
            string paramJson = ToJson(param);
            try
            {
                Bridge.CallStatic("initSobotSDK", paramJson);
            }
            catch (Exception e)
            {
                Debug.LogError($"[SobotSDK] initSobotSDK error: {e.Message}");
                _isInitialized = false;
                callback?.Invoke(false, e.Message);
            }

#elif UNITY_IOS
            string paramJson = ToJson(param);
            _sobotInitSDK(paramJson, inst.gameObject.name, "OnInitResult");
#endif
        }

        /// <summary>打开智齿客服聊天页面。</summary>
        /// <param name="param">打开聊天页所需参数，通常至少包含 `app_key` 和 `partnerid`。</param>
        public static void openSobotChat(SobotParams param)
        {
#if UNITY_EDITOR
            Debug.Log($"[SobotSDK] openSobotChat app_key={param?.app_key} partnerid={param?.partnerid}");

#elif UNITY_ANDROID
            string paramJson = ToJson(param);
            try { Bridge.CallStatic("openSobotChat", paramJson); }
            catch (Exception e) { Debug.LogError($"[SobotSDK] openSobotChat error: {e.Message}"); }

#elif UNITY_IOS
            string paramJson = ToJson(param);
            _sobotOpenChat(paramJson);
#endif
        }

        /// <summary>打开智齿帮助中心页面。</summary>
        /// <param name="param">打开帮助中心所需参数，通常至少包含 `app_key` 和 `partnerid`。</param>
        public static void openSobotHelpCenter(SobotParams param)
        {
#if UNITY_EDITOR
            Debug.Log($"[SobotSDK] openSobotHelpCenter app_key={param?.app_key} partnerid={param?.partnerid}");

#elif UNITY_ANDROID
            string paramJson = ToJson(param);
            try { Bridge.CallStatic("openSobotHelpCenter", paramJson); }
            catch (Exception e) { Debug.LogError($"[SobotSDK] openSobotHelpCenter error: {e.Message}"); }

#elif UNITY_IOS
            string paramJson = ToJson(param);
            _sobotOpenServiceCenter(paramJson);
#endif
        }

        /// <summary>打开智齿留言页面。</summary>
        /// <param name="param">打开留言页所需参数，通常至少包含 `app_key` 和 `partnerid`。</param>
        public static void openSobotLeave(SobotParams param)
        {
#if UNITY_EDITOR
            Debug.Log($"[SobotSDK] openSobotLeave app_key={param?.app_key} partnerid={param?.partnerid}");

#elif UNITY_ANDROID
            string paramJson = ToJson(param);
            try { Bridge.CallStatic("openSobotLeave", paramJson); }
            catch (Exception e) { Debug.LogError($"[SobotSDK] openSobotLeave error: {e.Message}"); }

#elif UNITY_IOS
            string paramJson = ToJson(param);
            _sobotOpenLeave(paramJson);
#endif
        }

        /// <summary>查询离线消息和未读消息数量。</summary>
        /// <param name="param">查询未读消息所需参数，通常至少包含 `app_key` 和 `partnerid`。</param>
        /// <param name="callback">查询完成后的回调，返回未读、离线和未确认消息数量。</param>
        public static void getUnReadMessage(SobotParams param, OfflineMsgCallback callback)
        {
            _offlineMsgCallback = callback;
            var inst = Instance;

#if UNITY_EDITOR
            Debug.Log($"[SobotSDK] getUnReadMessage partnerid={param?.partnerid}");
            callback?.Invoke(0, 0, 0);

#elif UNITY_ANDROID
            string paramJson = ToJson(param);
            try
            {
                Bridge.CallStatic("getUnReadMessage", paramJson, new AndroidOfflineMsgCallback(callback));
            }
            catch (Exception e)
            {
                Debug.LogError($"[SobotSDK] getUnReadMessage error: {e.Message}");
                callback?.Invoke(0, 0, 0);
            }

#elif UNITY_IOS
            string paramJson = ToJson(param);
            _sobotGetOfflineMsg(paramJson, inst.gameObject.name, "OnOfflineMsgResult");
#endif
        }

        /// <summary>关闭当前客服会话。</summary>
        /// <param name="param">关闭会话所需参数，`closePush` 可控制是否同步关闭推送状态。</param>
        public static void closeSobotChat(SobotParams param)
        {
#if UNITY_EDITOR
            Debug.Log("[SobotSDK] closeSobotChat");

#elif UNITY_ANDROID
            try { Bridge.CallStatic("closeSobotChat", ToJson(param)); }
            catch (Exception e) { Debug.LogError($"[SobotSDK] closeSobotChat error: {e.Message}"); }

#elif UNITY_IOS
            bool closePush = param != null && param.closePush;
            _sobotCloseSession(closePush);
#endif
        }

        /// <summary>
        /// 注册消息中的链接点击监听。
        /// 返回 <c>true</c> 时表示由 Unity 侧接管链接跳转。
        /// </summary>
        /// <param name="callback">链接点击回调，返回 `true` 表示由 Unity 侧拦截跳转。</param>
        public static void setMessageLinkClick(LinkClickCallback callback)
        {
            var inst = Instance;
            _linkClickCallback = callback;

#if UNITY_EDITOR
            Debug.Log("[SobotSDK] setMessageLinkClick registered");

#elif UNITY_ANDROID
            try
            {
                Bridge.CallStatic("setMessageLinkClick", new AndroidLinkClickListener(callback));
            }
            catch (Exception e) { Debug.LogError($"[SobotSDK] setMessageLinkClick error: {e.Message}"); }

#elif UNITY_IOS
            _sobotSetLinkClickListener(_iosLinkClickCallback);
            Debug.Log("[SobotSDK] setMessageLinkClick registered for iOS");
#endif
        }

        /// <summary>注册页面内功能按钮点击监听。</summary>
        /// <param name="callback">功能按钮点击回调，参数为智齿定义的功能类型编号。</param>
        public static void setFunctionClickListener(FunctionClickCallback callback)
        {
            var inst = Instance;
            _functionClickCallback = callback;

#if UNITY_EDITOR
            Debug.Log("[SobotSDK] setFunctionClickListener registered");

#elif UNITY_ANDROID
            try
            {
                Bridge.CallStatic("setFunctionClickListener", new AndroidFunctionClickListener(callback));
            }
            catch (Exception e) { Debug.LogError($"[SobotSDK] setFunctionClickListener error: {e.Message}"); }

#elif UNITY_IOS
            _sobotSetFunctionClickListener(_iosFunctionClickCallback);
            Debug.Log("[SobotSDK] setFunctionClickListener registered for iOS");
#endif
        }

        /// <summary>向聊天窗口主动发送自定义卡片。</summary>
        /// <param name="param">自定义卡片参数，必须包含 `custom_card` 对象。</param>
        /// <param name="callback">发送结果回调，可为空。</param>
        public static void sendCustomCardToChat(SobotParams param, SendMessageResultCallback callback = null)
        {
            if (!EnsureInitialized("sendCustomCardToChat", callback)) return;
            if (!RequireString(param?.custom_card, "sendCustomCardToChat", "custom_card", callback)) return;

#if UNITY_EDITOR
            Debug.Log("[SobotSDK] sendCustomCardToChat editor mock");
            callback?.Invoke(true, 0, "Editor模式，模拟发送自定义卡片成功");

#elif UNITY_ANDROID
            try { InvokeAndroidActiveSend("sendCustomCardToChat", ToJson(param), callback); }
            catch (Exception e) { Debug.LogError($"[SobotSDK] sendCustomCardToChat error: {e.Message}"); callback?.Invoke(false, -1, e.Message); }

#elif UNITY_IOS
            var inst = Instance;
            string requestId = StoreSendCallback(callback);
            _sobotSendCustomCardToChat(ToJson(param), inst.gameObject.name, "OnSendMessageResult", requestId);
#endif
        }

        /// <summary>向聊天窗口主动发送商品卡片。</summary>
        /// <param name="param">商品卡片参数，至少需要 `goodsTitle` 和 `goodsLink`。</param>
        /// <param name="callback">发送结果回调，可为空。</param>
        public static void sendProductInfo(SobotParams param, SendMessageResultCallback callback = null)
        {
            if (!EnsureInitialized("sendProductInfo", callback)) return;
            if (!RequireString(param?.goodsTitle, "sendProductInfo", "goodsTitle", callback)) return;
            if (!RequireString(param?.goodsLink, "sendProductInfo", "goodsLink", callback)) return;

#if UNITY_EDITOR
            Debug.Log($"[SobotSDK] sendProductInfo editor mock title={param?.goodsTitle}");
            callback?.Invoke(true, 0, "Editor模式，模拟发送商品卡片成功");

#elif UNITY_ANDROID
            try { InvokeAndroidActiveSend("sendProductInfo", ToJson(param), callback); }
            catch (Exception e) { Debug.LogError($"[SobotSDK] sendProductInfo error: {e.Message}"); callback?.Invoke(false, -1, e.Message); }

#elif UNITY_IOS
            var inst = Instance;
            string requestId = StoreSendCallback(callback);
            _sobotSendProductInfo(ToJson(param), inst.gameObject.name, "OnSendMessageResult", requestId);
#endif
        }

        /// <summary>向聊天窗口主动发送订单卡片。</summary>
        /// <param name="param">订单卡片参数，至少需要 `orderCode`。</param>
        /// <param name="callback">发送结果回调，可为空。</param>
        public static void sendOrderGoodsInfo(SobotParams param, SendMessageResultCallback callback = null)
        {
            if (!EnsureInitialized("sendOrderGoodsInfo", callback)) return;
            if (!RequireString(param?.orderCode, "sendOrderGoodsInfo", "orderCode", callback)) return;

#if UNITY_EDITOR
            Debug.Log($"[SobotSDK] sendOrderGoodsInfo editor mock orderCode={param?.orderCode}");
            callback?.Invoke(true, 0, "Editor模式，模拟发送订单卡片成功");

#elif UNITY_ANDROID
            try { InvokeAndroidActiveSend("sendOrderGoodsInfo", ToJson(param), callback); }
            catch (Exception e) { Debug.LogError($"[SobotSDK] sendOrderGoodsInfo error: {e.Message}"); callback?.Invoke(false, -1, e.Message); }

#elif UNITY_IOS
            var inst = Instance;
            string requestId = StoreSendCallback(callback);
            _sobotSendOrderGoodsInfo(ToJson(param), inst.gameObject.name, "OnSendMessageResult", requestId);
#endif
        }

        /// <summary>向聊天窗口主动发送位置消息。</summary>
        /// <param name="param">位置消息参数，至少需要 `lat` 和 `lng`。</param>
        /// <param name="callback">发送结果回调，可为空。</param>
        public static void sendLocation(SobotParams param, SendMessageResultCallback callback = null)
        {
            if (!EnsureInitialized("sendLocation", callback)) return;
            if (!RequireString(param?.lat, "sendLocation", "lat", callback)) return;
            if (!RequireString(param?.lng, "sendLocation", "lng", callback)) return;

#if UNITY_EDITOR
            Debug.Log($"[SobotSDK] sendLocation editor mock lat={param?.lat} lng={param?.lng}");
            callback?.Invoke(true, 0, "Editor模式，模拟发送定位消息成功");

#elif UNITY_ANDROID
            try { InvokeAndroidActiveSend("sendLocation", ToJson(param), callback); }
            catch (Exception e) { Debug.LogError($"[SobotSDK] sendLocation error: {e.Message}"); callback?.Invoke(false, -1, e.Message); }

#elif UNITY_IOS
            var inst = Instance;
            string requestId = StoreSendCallback(callback);
            _sobotSendLocation(ToJson(param), inst.gameObject.name, "OnSendMessageResult", requestId);
#endif
        }

        /// <summary>将参数对象序列化为 JSON，供 Android/iOS 原生层解析。</summary>
        /// <param name="param">待序列化的参数对象。</param>
        private static string ToJson(SobotParams param)
        {
            string json = JsonUtility.ToJson(param ?? new SobotParams());
            return json.Replace("\"_params\"", "\"params\"");
        }

        /// <summary>检查 SDK 是否已初始化；未初始化时返回错误给主动发送接口。</summary>
        /// <param name="methodName">当前调用的方法名，用于错误提示。</param>
        /// <param name="callback">需要回传错误结果的发送回调。</param>
        private static bool EnsureInitialized(string methodName, SendMessageResultCallback callback)
        {
            if (_isInitialized) return true;

            string message = "请先调用 initSobotSDK 并等待初始化成功后再发送消息";
            Debug.LogWarning($"[SobotSDK] {methodName} ignored: {message}");
            callback?.Invoke(false, -1, message);
            return false;
        }

        /// <summary>校验主动发送接口中必须存在的字符串字段。</summary>
        /// <param name="value">需要检查的字段值。</param>
        /// <param name="methodName">当前调用的方法名，用于错误提示。</param>
        /// <param name="fieldName">字段名，用于错误提示。</param>
        /// <param name="callback">需要回传错误结果的发送回调。</param>
        private static bool RequireString(string value, string methodName, string fieldName, SendMessageResultCallback callback)
        {
            if (!string.IsNullOrEmpty(value)) return true;

            string message = $"{fieldName} 不能为空";
            Debug.LogWarning($"[SobotSDK] {methodName} ignored: {message}");
            callback?.Invoke(false, -1, message);
            return false;
        }

#if UNITY_ANDROID && !UNITY_EDITOR
        /// <summary>统一封装 Android 侧主动发送消息的调用与回调注册。</summary>
        /// <param name="methodName">Android 桥接方法名。</param>
        /// <param name="paramJson">传给原生层的 JSON 参数。</param>
        /// <param name="callback">发送结果回调。</param>
        private static void InvokeAndroidActiveSend(string methodName, string paramJson, SendMessageResultCallback callback)
        {
            bool delivered = Bridge.CallStatic<bool>(methodName, paramJson);
            if (delivered)
            {
                callback?.Invoke(true, 0, "Android 已发送到聊天页");
                return;
            }

            string message = "Android 聊天页未打开或尚未加载完成，主动发送广播没有接收者";
            Debug.LogWarning($"[SobotSDK] {methodName} ignored: {message}");
            callback?.Invoke(false, -1, message);
        }
#endif

        /// <summary>保存主动发送结果回调，并生成供原生层回传的请求 id。</summary>
        /// <param name="callback">发送结果回调，可为空。</param>
        private static string StoreSendCallback(SendMessageResultCallback callback)
        {
            if (callback == null) return string.Empty;

            string requestId = (++_sendRequestSeq).ToString();
            _sendCallbacks[requestId] = callback;
            return requestId;
        }

        /// <summary>iOS 初始化结果回调入口，由原生层通过 UnitySendMessage 调用。</summary>
        /// <param name="message">iOS 原生层回传的初始化结果字符串。</param>
        private void OnInitResult(string message)
        {
            Debug.Log($"[SobotSDK] OnInitResult: {message}");
            bool success = message != null && !message.StartsWith("error");
            _isInitialized = success;
            _initCallback?.Invoke(success, message);
        }

        /// <summary>iOS 离线消息结果回调入口。</summary>
        /// <param name="data">iOS 原生层回传的离线消息结果字符串。</param>
        private void OnOfflineMsgResult(string data)
        {
            try
            {
                string[] parts = data.Split(',');
                int unRead = parts.Length > 0 ? int.Parse(parts[0]) : 0;
                int offline = parts.Length > 1 ? int.Parse(parts[1]) : 0;
                int unAck = parts.Length > 2 ? int.Parse(parts[2]) : 0;
                _offlineMsgCallback?.Invoke(unRead, offline, unAck);
            }
            catch { _offlineMsgCallback?.Invoke(0, 0, 0); }
        }

        /// <summary>iOS 主动发送消息结果回调入口。</summary>
        /// <param name="data">iOS 原生层回传的主动发送结果字符串。</param>
        private void OnSendMessageResult(string data)
        {
            try
            {
                string[] parts = (data ?? string.Empty).Split(new[] { '|' }, 3);
                string requestId = parts.Length > 0 ? parts[0] : string.Empty;
                int code = parts.Length > 1 ? int.Parse(parts[1]) : -1;
                string message = parts.Length > 2 ? parts[2] : string.Empty;

                if (!string.IsNullOrEmpty(requestId) && _sendCallbacks.TryGetValue(requestId, out var callback))
                {
                    _sendCallbacks.Remove(requestId);
                    callback?.Invoke(code == 0, code, message);
                }
            }
            catch (Exception e)
            {
                Debug.LogError($"[SobotSDK] OnSendMessageResult error: {e.Message}");
            }
        }

#if UNITY_IOS && !UNITY_EDITOR
        [AOT.MonoPInvokeCallback(typeof(IOSLinkClickCallback))]
        /// <summary>iOS 链接点击回调转发到 Unity 业务层。</summary>
        /// <param name="url">被点击的链接地址。</param>
        private static bool OnIOSLinkClick(string url)
        {
            try
            {
                bool handled = _linkClickCallback?.Invoke(url) ?? false;
                Debug.Log($"[SobotSDK] OnIOSLinkClick url={url}, handled={handled}");
                return handled;
            }
            catch (Exception e)
            {
                Debug.LogError($"[SobotSDK] OnIOSLinkClick error: {e.Message}");
                return false;
            }
        }

        [AOT.MonoPInvokeCallback(typeof(IOSFunctionClickCallback))]
        /// <summary>iOS 功能点击回调转发到 Unity 业务层。</summary>
        /// <param name="type">智齿定义的功能按钮类型编号。</param>
        private static void OnIOSFunctionClick(int type)
        {
            try
            {
                Debug.Log($"[SobotSDK] OnIOSFunctionClick type={type}");
                _functionClickCallback?.Invoke(type);
            }
            catch (Exception e)
            {
                Debug.LogError($"[SobotSDK] OnIOSFunctionClick error: {e.Message}");
            }
        }
#endif

#if UNITY_ANDROID && !UNITY_EDITOR
        private class AndroidOfflineMsgCallback : AndroidJavaProxy
        {
            private readonly OfflineMsgCallback _callback;
            /// <summary>创建 Android 离线消息回调代理。</summary>
            /// <param name="cb">离线消息结果回调。</param>
            public AndroidOfflineMsgCallback(OfflineMsgCallback cb)
                : base("com.sobot.network.http.callback.StringResultCallBack") => _callback = cb;

            /// <summary>Android SDK 获取离线消息成功时调用。</summary>
            /// <param name="model">Android SDK 返回的离线消息模型。</param>
            public void onSuccess(AndroidJavaObject model)
            {
                _callback?.Invoke(
                    model.Call<int>("getUnReadSize"),
                    model.Call<int>("getOfflineSize"),
                    model.Call<int>("getUnAckSize")
                );
            }

            /// <summary>Android SDK 获取离线消息失败时调用。</summary>
            /// <param name="e">Android SDK 的异常对象。</param>
            /// <param name="des">失败描述。</param>
            public void onFailure(AndroidJavaObject e, string des)
            {
                Debug.LogError($"[SobotSDK] getUnReadMessage failed: {des}");
                _callback?.Invoke(0, 0, 0);
            }
        }

        private class AndroidLinkClickListener : AndroidJavaProxy
        {
            private readonly LinkClickCallback _callback;
            /// <summary>创建 Android 链接点击监听代理。</summary>
            /// <param name="cb">链接点击回调。</param>
            public AndroidLinkClickListener(LinkClickCallback cb)
                : base("com.sobot.chat.listener.NewHyperlinkListener") => _callback = cb;

            /// <summary>Android URL 链接点击回调。</summary>
            /// <param name="context">当前 Android 上下文。</param>
            /// <param name="url">点击的 URL。</param>
            public bool onUrlClick(AndroidJavaObject context, string url)
            {
                bool handled = _callback?.Invoke(url) ?? false;
                Debug.Log($"[SobotSDK] Android link click url={url}, handled={handled}");
                return handled;
            }

            /// <summary>Android 邮箱链接点击回调。</summary>
            /// <param name="context">当前 Android 上下文。</param>
            /// <param name="email">点击的邮箱地址。</param>
            public bool onEmailClick(AndroidJavaObject context, string email)
            {
                Debug.Log($"[SobotSDK] Android email click email={email}");
                return false;
            }

            /// <summary>Android 电话链接点击回调。</summary>
            /// <param name="context">当前 Android 上下文。</param>
            /// <param name="phone">点击的电话号码。</param>
            public bool onPhoneClick(AndroidJavaObject context, string phone)
            {
                Debug.Log($"[SobotSDK] Android phone click phone={phone}");
                return false;
            }
        }

        private class AndroidFunctionClickListener : AndroidJavaProxy
        {
            private readonly FunctionClickCallback _callback;
            /// <summary>创建 Android 功能按钮点击监听代理。</summary>
            /// <param name="cb">功能点击回调。</param>
            public AndroidFunctionClickListener(FunctionClickCallback cb)
                : base("com.sobot.chat.listener.SobotFunctionClickListener") => _callback = cb;

            /// <summary>Android 功能按钮点击回调。</summary>
            /// <param name="context">当前 Android 上下文。</param>
            /// <param name="functionType">Android SDK 返回的功能类型枚举对象。</param>
            public void onClickFunction(AndroidJavaObject context, AndroidJavaObject functionType)
            {
                int type = ConvertAndroidFunctionType(functionType);
                Debug.Log($"[SobotSDK] Android function click type={type}");
                _callback?.Invoke(type);
            }

            /// <summary>把 Android 枚举对象转换为 Unity 层使用的整数类型。</summary>
            /// <param name="functionType">Android SDK 返回的功能类型枚举对象。</param>
            private static int ConvertAndroidFunctionType(AndroidJavaObject functionType)
            {
                if (functionType == null) return 0;

                try
                {
                    string name = functionType.Call<string>("name");
                    switch (name)
                    {
                        case "ZC_CloseLeave": return 1;
                        case "ZC_CloseChat": return 2;
                        case "ZC_CloseHelpCenter": return 3;
                        case "ZC_CloseChatList": return 4;
                        case "ZC_PhoneCustomerService": return 5;
                    }
                }
                catch (Exception e)
                {
                    Debug.LogWarning($"[SobotSDK] ConvertAndroidFunctionType name error: {e.Message}");
                }

                try
                {
                    return functionType.Call<int>("ordinal") + 1;
                }
                catch (Exception e)
                {
                    Debug.LogWarning($"[SobotSDK] ConvertAndroidFunctionType ordinal error: {e.Message}");
                    return 0;
                }
            }
        }
#endif
    }
}
