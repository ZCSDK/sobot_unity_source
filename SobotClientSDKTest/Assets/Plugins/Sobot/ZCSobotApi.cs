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

        public delegate void InitResultCallback(bool success, string message);
        public delegate void OfflineMsgCallback(int unReadSize, int offlineSize, int unAckSize);
        public delegate bool LinkClickCallback(string linkUrl);
        public delegate void FunctionClickCallback(int type);
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
        private static extern void _sobotInitSDK(string paramJson, string gameObjectName, string callbackMethod);

        [DllImport("__Internal")]
        private static extern void _sobotOpenChat(string paramJson);

        [DllImport("__Internal")]
        private static extern void _sobotOpenServiceCenter(string paramJson);

        [DllImport("__Internal")]
        private static extern void _sobotOpenLeave(string paramJson);

        [DllImport("__Internal")]
        private static extern void _sobotCloseSession([MarshalAs(UnmanagedType.I1)] bool closePush);

        [DllImport("__Internal")]
        private static extern void _sobotGetOfflineMsg(string paramJson, string gameObjectName, string callbackMethod);

        [DllImport("__Internal")]
        private static extern void _sobotSetLinkClickListener(IOSLinkClickCallback callback);

        [DllImport("__Internal")]
        private static extern void _sobotSetFunctionClickListener(IOSFunctionClickCallback callback);

        [DllImport("__Internal")]
        private static extern void _sobotSendCustomCardToChat(string paramJson, string gameObjectName, string callbackMethod, string requestId);

        [DllImport("__Internal")]
        private static extern void _sobotSendProductInfo(string paramJson, string gameObjectName, string callbackMethod, string requestId);

        [DllImport("__Internal")]
        private static extern void _sobotSendOrderGoodsInfo(string paramJson, string gameObjectName, string callbackMethod, string requestId);

        [DllImport("__Internal")]
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

        private static string ToJson(SobotParams param)
        {
            string json = JsonUtility.ToJson(param ?? new SobotParams());
            return json.Replace("\"_params\"", "\"params\"");
        }

        private static bool EnsureInitialized(string methodName, SendMessageResultCallback callback)
        {
            if (_isInitialized) return true;

            string message = "请先调用 initSobotSDK 并等待初始化成功后再发送消息";
            Debug.LogWarning($"[SobotSDK] {methodName} ignored: {message}");
            callback?.Invoke(false, -1, message);
            return false;
        }

        private static bool RequireString(string value, string methodName, string fieldName, SendMessageResultCallback callback)
        {
            if (!string.IsNullOrEmpty(value)) return true;

            string message = $"{fieldName} 不能为空";
            Debug.LogWarning($"[SobotSDK] {methodName} ignored: {message}");
            callback?.Invoke(false, -1, message);
            return false;
        }

#if UNITY_ANDROID && !UNITY_EDITOR
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

        private static string StoreSendCallback(SendMessageResultCallback callback)
        {
            if (callback == null) return string.Empty;

            string requestId = (++_sendRequestSeq).ToString();
            _sendCallbacks[requestId] = callback;
            return requestId;
        }

        private void OnInitResult(string message)
        {
            Debug.Log($"[SobotSDK] OnInitResult: {message}");
            bool success = message != null && !message.StartsWith("error");
            _isInitialized = success;
            _initCallback?.Invoke(success, message);
        }

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
            public AndroidOfflineMsgCallback(OfflineMsgCallback cb)
                : base("com.sobot.network.http.callback.StringResultCallBack") => _callback = cb;

            public void onSuccess(AndroidJavaObject model)
            {
                _callback?.Invoke(
                    model.Call<int>("getUnReadSize"),
                    model.Call<int>("getOfflineSize"),
                    model.Call<int>("getUnAckSize")
                );
            }

            public void onFailure(AndroidJavaObject e, string des)
            {
                Debug.LogError($"[SobotSDK] getUnReadMessage failed: {des}");
                _callback?.Invoke(0, 0, 0);
            }
        }

        private class AndroidLinkClickListener : AndroidJavaProxy
        {
            private readonly LinkClickCallback _callback;
            public AndroidLinkClickListener(LinkClickCallback cb)
                : base("com.sobot.chat.listener.NewHyperlinkListener") => _callback = cb;

            public bool onUrlClick(AndroidJavaObject context, string url)
            {
                bool handled = _callback?.Invoke(url) ?? false;
                Debug.Log($"[SobotSDK] Android link click url={url}, handled={handled}");
                return handled;
            }

            public bool onEmailClick(AndroidJavaObject context, string email)
            {
                Debug.Log($"[SobotSDK] Android email click email={email}");
                return false;
            }

            public bool onPhoneClick(AndroidJavaObject context, string phone)
            {
                Debug.Log($"[SobotSDK] Android phone click phone={phone}");
                return false;
            }
        }

        private class AndroidFunctionClickListener : AndroidJavaProxy
        {
            private readonly FunctionClickCallback _callback;
            public AndroidFunctionClickListener(FunctionClickCallback cb)
                : base("com.sobot.chat.listener.SobotFunctionClickListener") => _callback = cb;

            public void onClickFunction(AndroidJavaObject context, AndroidJavaObject functionType)
            {
                int type = ConvertAndroidFunctionType(functionType);
                Debug.Log($"[SobotSDK] Android function click type={type}");
                _callback?.Invoke(type);
            }

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
