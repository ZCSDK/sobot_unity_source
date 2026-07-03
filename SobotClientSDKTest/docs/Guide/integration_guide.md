# 智齿 SDK Unity 集成指南

## 快速开始

### 1. 获取 AppKey

登录 [智齿管理平台](https://www.sobot.com) → 首页 → 在线客服 → 设置 → 对接渠道设置 → 添加 APP

### 2. 文件结构

```
Assets/Plugins/Sobot/
├── ZCSobotApi.cs              # Unity 封装入口（核心文件）
├── iOS/
│   ├── SobotUnityBridge.mm     # iOS 原生桥接层
│   └── frameworks/
│       ├── SobotKit.xcframework
│       ├── SobotCommon.xcframework
│       ├── SobotChatClient.xcframework
│       └── SobotKit.bundle
└── Android/
    └── (Android SDK 通过 Maven 依赖集成)
```

---

## iOS 集成步骤

### 1. Unity 构建设置

Build Settings → iOS → 构建 Xcode 工程

### 2. Xcode 工程配置

**添加系统框架**（TARGETS → Build Phases → Link Binary With Libraries）：
- AVFoundation.framework
- AssetsLibrary.framework
- AudioToolbox.framework
- SystemConfiguration.framework
- MobileCoreServices.framework
- WebKit.framework

**添加 Info.plist 权限**：
```xml
<key>NSCameraUsageDescription</key>
<string>发送图片需要访问相机</string>
<key>NSMicrophoneUsageDescription</key>
<string>发送语音需要访问麦克风</string>
<key>NSPhotoLibraryUsageDescription</key>
<string>发送图片需要访问相册</string>
```

### 3. 域名配置（可选）

默认使用 SaaS 域名 `https://api.sobot.com`，如需修改在初始化参数中传入 `api_host`。

---

## Android 集成步骤

### 1. 添加 Maven 依赖

在 Unity 导出的 Android 工程 `build.gradle` 中添加：

```gradle
dependencies {
    implementation 'com.sobot.chat:client:+'
    implementation 'com.squareup.okhttp3:okhttp:4.4.0'
    implementation 'androidx.appcompat:appcompat:1.0.0'
    implementation 'androidx.recyclerview:recyclerview:1.0.0'
    implementation 'com.github.bumptech.glide:glide:4.9.0'
}
```

### 2. 混淆配置

```
-keep class com.sobot.chat.** {*;}
-dontwarn com.sobot.chat.**
```

---

## Unity 代码使用

### 引入命名空间

```csharp
using SobotChatClient;
```

### 创建参数对象

```csharp
var param = new SobotParams
{
    app_key = "your_app_key",
    partnerid = "user_unique_id",
    user_nick = "用户昵称"
};
```

### 初始化（必须最先调用）

```csharp
ZCSobotApi.initSobotSDK(param, (success, msg) => {
    Debug.Log($"初始化结果: {success}, {msg}");
});
```

### 启动聊天

```csharp
// partnerid 必须是用户唯一标识，不能写死
ZCSobotApi.openSobotChat(param);
```

### 启动帮助中心

```csharp
ZCSobotApi.openSobotHelpCenter(param);
```

### 启动留言

```csharp
ZCSobotApi.openSobotLeave(param);
```

### 监听链接点击

```csharp
ZCSobotApi.setMessageLinkClick((url) => {
    Debug.Log($"点击链接: {url}");
    // 返回 true 拦截，false 由 SDK 处理
    return url.Contains("sobot://");
});
```

### 关闭会话

```csharp
// 用户退出登录时调用
ZCSobotApi.closeSobotChat(new SobotParams { closePush = false });
```

### 获取未读消息数

```csharp
ZCSobotApi.getUnReadMessage(param, (unRead, offline, unAck) => {
    Debug.Log($"未读:{unRead}, 离线:{offline}, 未确认:{unAck}");
});
```

---

## 常见问题

**Q: 初始化失败？**
A: 检查 AppKey 是否正确，网络是否可用，域名是否配置正确。

**Q: iOS 编译报错找不到头文件？**
A: 确认 frameworks 已正确添加到 Xcode 工程，并在 Build Settings 中设置 Framework Search Paths。

**Q: Android 运行时崩溃？**
A: 检查 build.gradle 依赖是否添加，混淆规则是否配置。

**Q: partnerid 有什么要求？**
A: 必须是用户唯一标识，不能写死（如 "123456"），同一 partnerid 的聊天记录会共享，最大 300 字符。



**Q: 导出Android项目版本问题？**
grade替换为8.10.2
#distributionUrl=https\://services.gradle.org/distributions/gradle-7.5.1-bin.zip
distributionUrl=https\://mirrors.cloud.tencent.com/gradle/gradle-8.10.2-bin.zip
plugins替换为8.3.2
id 'com.android.application' version '8.3.2' apply false
id 'com.android.library' version '8.3.2' apply false
