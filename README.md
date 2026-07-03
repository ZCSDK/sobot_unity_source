
# 智齿 Unity SDK 插件项目

本仓库用于维护智齿客服 Unity SDK 插件、演示工程和打包资料。用户可以通过本项目了解 Unity 层、Android 原生层、iOS 原生层之间的调用关系，并基于现有工程完成调试、替换原生 SDK、导出 `.unitypackage`、构建 Android/iOS 应用。

## 1. 仓库结构

```text
sobot_unity/
├── SobotClientSDKTest/                 # SDK 开发与打包工程
│   ├── Assets/
│   │   ├── StartPage.cs                # Demo 页面，展示所有主要 API 调用
│   │   ├── Editor/                     # 构建后处理、Android 构建配置、UnityPackage 导出脚本
│   │   └── Plugins/Sobot/              # Unity 插件主体
│   │       ├── ZCSobotApi.cs           # Unity C# 对外 API
│   │       ├── Android/SobotBridge.java# Android 桥接层
│   │       └── iOS/                    # iOS 桥接层与原生 SDK 包
│   ├── Packages/
│   └── ProjectSettings/
├── SobotUnityIntegrationDemo/           # 用户集成后的演示工程
├── Unity平台SDK集成/                    # 设计、集成、打包和问题记录文档
├── SobotClientSDK.unitypackage          # 当前导出的 Unity SDK 包
└── README.md                            # 开源入口文档
```

### 工程区别

| 工程 | 用途 | 适合对象 |
|---|---|---|
| `SobotClientSDKTest` | SDK 开发、维护、原生包替换、导出 `.unitypackage` | SDK 维护者 |
| `SobotUnityIntegrationDemo` | 模拟用户导入 SDK 后的最终效果 | SDK 使用者、验证人员 |
| `Unity平台SDK集成` | 历史方案、接入指南、打包记录、问题记录 | 维护者、排障人员 |

## 2. 环境要求

- Unity：`2021.3.45f2c1`
- Android：Unity Android Build Support、Android SDK/NDK、JDK
- iOS：macOS、Xcode、有效的 Apple Developer Team、证书和描述文件
- 建议真机验证：Android ARM64 真机、iPhone 真机

Unity 版本记录在：

```text
SobotClientSDKTest/ProjectSettings/ProjectVersion.txt
SobotUnityIntegrationDemo/ProjectSettings/ProjectVersion.txt
```

## 3. 插件架构

```text
Unity 业务代码
    ↓
SobotChatClient.ZCSobotApi
    ↓
平台分发
    ├── Android: Unity C# → AndroidJavaClass → com.sobot.unity.SobotBridge → 智齿 Android SDK
    └── iOS: Unity C# → DllImport("__Internal") → SobotUnityBridge.mm → 智齿 iOS SDK
```

核心文件：

| 文件 | 作用 |
|---|---|
| `SobotClientSDKTest/Assets/Plugins/Sobot/ZCSobotApi.cs` | 对外 C# API、统一参数 `SobotParams`、回调桥接 |
| `SobotClientSDKTest/Assets/Plugins/Sobot/Android/SobotBridge.java` | Android 原生桥接，负责初始化、打开客服、发送卡片、链接回调等 |
| `SobotClientSDKTest/Assets/Plugins/Sobot/iOS/SobotUnityBridge.mm` | iOS 原生桥接，负责调用 iOS SDK、同步链接拦截、通知权限等 |
| `SobotClientSDKTest/Assets/Editor/SobotPostProcessBuild.cs` | Android Gradle 依赖注入、iOS Xcode 工程后处理 |
| `SobotClientSDKTest/Assets/Editor/SobotAndroidBuildSettings.cs` | 自动设置 Android `IL2CPP + ARM64` |
| `SobotClientSDKTest/Assets/Editor/SobotPackageExporter.cs` | 导出 SDK/Demo `.unitypackage` |
| `SobotClientSDKTest/Assets/StartPage.cs` | Demo 按钮页和调用示例 |

## 4. 运行 Demo

### 4.1 打开开发工程

1. 打开 Unity Hub。
2. 选择 `Add project from disk`。
3. 选择 `SobotClientSDKTest`。
4. 使用 Unity `2021.3.45f2c1` 打开。
5. 打开场景：`Assets/Scenes/SampleScene.unity`。
6. 运行 Editor，可看到 `StartPage.cs` 绘制的 Demo 按钮页面。

### 4.2 配置 Demo 参数

Demo 参数集中在：

```text
SobotClientSDKTest/Assets/StartPage.cs
```

重点字段：

```csharp
private const string APP_KEY = "替换为你的 app_key";
private const string PARTNER_ID = "替换为你的用户唯一标识";
```

主要参数在 `CreateDemoParams()` 中统一构造。用户接入自己的项目时，也应优先参考该方法创建 `SobotParams`。

### 4.3 主要 API

命名空间：

```csharp
using SobotChatClient;
```

常用方法：

| 方法 | 说明 |
|---|---|
| `ZCSobotApi.initSobotSDK(SobotParams param, callback)` | 初始化 SDK |
| `ZCSobotApi.openSobotChat(SobotParams param)` | 打开客服会话 |
| `ZCSobotApi.openSobotHelpCenter(SobotParams param)` | 打开帮助中心 |
| `ZCSobotApi.openSobotLeave(SobotParams param)` | 打开留言 |
| `ZCSobotApi.getUnReadMessage(SobotParams param, callback)` | 获取未读消息 |
| `ZCSobotApi.closeSobotChat(SobotParams param)` | 关闭会话 |
| `ZCSobotApi.setMessageLinkClick(callback)` | 注册链接点击拦截 |
| `ZCSobotApi.setFunctionClickListener(callback)` | 注册功能按钮点击监听 |
| `ZCSobotApi.sendCustomCardToChat(param, callback)` | 主动发送自定义卡片 |
| `ZCSobotApi.sendProductInfo(param, callback)` | 主动发送商品卡片 |
| `ZCSobotApi.sendOrderGoodsInfo(param, callback)` | 主动发送订单卡片 |
| `ZCSobotApi.sendLocation(param, callback)` | 主动发送定位消息 |

## 5. 替换 iOS 原生集成包

iOS 原生 SDK 位于：

```text
SobotClientSDKTest/Assets/Plugins/Sobot/iOS/frameworks/
├── SobotKit.xcframework
├── SobotCommon.xcframework
├── SobotChatClient.xcframework
├── SobotKit.bundle
└── PrivacyInfo.xcprivacy
```

### 5.1 替换步骤

1. 关闭 Unity，避免导入过程中产生临时状态。
2. 备份 `SobotClientSDKTest/Assets/Plugins/Sobot/iOS/frameworks`。
3. 删除旧的原生包本体：
   - `SobotKit.xcframework`
   - `SobotCommon.xcframework`
   - `SobotChatClient.xcframework`
   - `SobotKit.bundle`
4. 不要删除对应 `.meta` 文件：
   - `SobotKit.xcframework.meta`
   - `SobotCommon.xcframework.meta`
   - `SobotChatClient.xcframework.meta`
   - `SobotKit.bundle.meta`
5. 将新版同名文件复制到相同目录。
6. 如果新版 SDK 附带新的 `PrivacyInfo.xcprivacy`，同步替换该文件，并保留 `PrivacyInfo.xcprivacy.meta`。
7. 重新打开 Unity，等待资源导入完成。
8. 在 Inspector 中检查这些 iOS 插件：`Any Platform` 关闭，`iOS` 开启。

### 5.2 `.meta` 是否需要修改

通常不需要修改 `.meta`。当前 `.xcframework.meta` 的关键配置是：

```text
Any Platform: disabled
Editor: disabled
iPhone/iOS: enabled
AddToEmbeddedBinaries: false
```

当前仓库中的 3 个 `.xcframework` 是静态 framework，`AddToEmbeddedBinaries: false` 是合理配置。

只有以下情况才需要调整 `.meta` 或 Unity Inspector 导入配置：

- 新版 iOS SDK 从静态 framework 改为动态 framework，需要 Embed 到 Xcode 工程。
- SDK 文件名变化，例如不再叫 `SobotKit.xcframework`。
- SDK 新增其他 `.xcframework`、`.bundle`、`.a`、`.framework` 文件。
- Unity 导入后平台勾选异常，导致 iOS 工程没有包含对应文件。

### 5.3 iOS 后处理逻辑

`SobotPostProcessBuild.cs` 在导出 Xcode 工程后会自动处理：

- 添加 `UserNotifications.framework`。
- 确保 `SobotKit.bundle` 被复制并加入 `Copy Bundle Resources`。
- 清理旧路径下的 `SobotKit.bundle` 引用。
- 补充常见 `Info.plist` 权限文案。

如果新版 iOS SDK 增加系统库依赖，需要在 `SobotPostProcessBuild.cs` 的 iOS 部分继续追加 `AddFrameworkToProject` 或相关 Build Settings。

## 6. 替换 Android 原生集成包和依赖版本

Android 插件桥接文件位于：

```text
SobotClientSDKTest/Assets/Plugins/Sobot/Android/SobotBridge.java
```

Android SDK 依赖不是以 `.aar` 放在仓库里，而是在 Unity 导出 Gradle 工程后由以下脚本自动注入：

```text
SobotClientSDKTest/Assets/Editor/SobotPostProcessBuild.cs
```

当前注入依赖：

```gradle
implementation 'com.sobot.chat:client:+'
implementation 'com.squareup.okhttp3:okhttp:4.4.0'
implementation 'androidx.appcompat:appcompat:1.0.0'
implementation 'androidx.recyclerview:recyclerview:1.0.0'
implementation 'com.github.bumptech.glide:glide:4.9.0'
```

### 6.1 修改 Android SDK 版本号

如果需要锁定智齿 Android SDK 版本，把：

```gradle
implementation 'com.sobot.chat:client:+'
```

改为指定版本，例如：

```gradle
implementation 'com.sobot.chat:client:版本号'
```

修改位置在：

```text
SobotClientSDKTest/Assets/Editor/SobotPostProcessBuild.cs
```

搜索关键字：

```text
com.sobot.chat:client
```

修改后重新构建 Android，Unity 会在导出的 `unityLibrary/build.gradle` 中注入新版本。

### 6.2 修改 Android 间接依赖版本

如果智齿 Android SDK 升级后要求更新 OkHttp、AndroidX、Glide 等依赖，也在同一个依赖注入块里修改：

```text
SobotClientSDKTest/Assets/Editor/SobotPostProcessBuild.cs
```

修改后需要验证：

- Gradle Sync 成功。
- Android 真机运行成功。
- 客服会话、帮助中心、留言、未读消息、主动发送卡片等功能正常。

### 6.3 使用本地 AAR 的情况

如果后续 Android SDK 不再通过 Maven 依赖接入，而是改为本地 `.aar`，建议放到：

```text
SobotClientSDKTest/Assets/Plugins/Sobot/Android/libs/
```

同时需要：

- 检查 Unity 是否正确识别 `.aar` 为 Android 插件。
- 保留 `.aar.meta` 中 Android 平台启用配置。
- 删除或调整 `SobotPostProcessBuild.cs` 中重复的 Maven 依赖，避免类重复。
- 必要时增加 `mainTemplate.gradle` 或继续通过后处理脚本注入 `implementation files(...)`。

## 7. 打包 Android

### 7.1 使用开发工程打包

1. 打开 `SobotClientSDKTest`。
2. 选择 `File > Build Settings > Android > Switch Platform`。
3. 点击菜单 `Sobot > Apply Android Build Settings`。
4. 确认配置：
   - `Scripting Backend`: `IL2CPP`
   - `Target Architectures`: `ARM64`
   - `Min SDK Version`: 建议 `22` 或以上
5. 连接 Android 真机并开启 USB 调试。
6. 点击 `Build And Run`。

构建后处理会自动：

- 修改 `settings.gradle`，加入 Maven 镜像仓库。
- 修改根 `build.gradle`，补充 `mavenCentral()`。
- 修改 `unityLibrary/build.gradle`，注入智齿 Android SDK 依赖。

### 7.2 常见 Android 问题

| 问题 | 排查方向 |
|---|---|
| 找不到 `com.sobot.chat:client` | 检查 Maven 仓库、网络、版本号是否存在 |
| 类重复 | 检查是否同时接入 Maven 依赖和本地 AAR |
| 设备架构不支持 | 确认使用 `IL2CPP + ARM64` |
| 方法找不到或反射失败 | 检查新版 Android SDK API 是否变更，必要时更新 `SobotBridge.java` |

## 8. 打包 iOS

1. 打开 `SobotClientSDKTest`。
2. 选择 `File > Build Settings > iOS > Switch Platform`。
3. 点击 `Build` 导出 Xcode 工程。
4. 使用 Xcode 打开导出的工程。
5. 配置：
   - `Signing & Capabilities > Team`
   - `Bundle Identifier`
   - 证书和描述文件
6. 连接 iPhone 真机运行。

构建后处理会自动把 `SobotKit.bundle` 加入 Xcode 工程资源，并添加 `UserNotifications.framework`。如果新版 iOS SDK 要求其他系统库或权限，需要同步修改 `SobotPostProcessBuild.cs`。

### 8.1 常见 iOS 问题

| 问题 | 排查方向 |
|---|---|
| 链接时报 symbol not found | 检查 `.xcframework` 是否完整、架构是否包含 `ios-arm64` |
| 运行时报 `dyld` 找不到库 | 检查新版 SDK 是否动态 framework，必要时开启 Embed |
| 图片/多语言/表情缺失 | 检查 `SobotKit.bundle` 是否进入 `Copy Bundle Resources` |
| App Store 隐私检查失败 | 检查 `PrivacyInfo.xcprivacy` 和权限文案是否同步更新 |

## 9. 导出 Unity SDK 包

在 `SobotClientSDKTest` 中提供导出菜单：

```text
Sobot > Export Unity SDK Package
Sobot > Export Unity SDK Demo Package
```

导出内容由以下文件控制：

```text
SobotClientSDKTest/Assets/Editor/SobotPackageExporter.cs
```

默认输出目录：

```text
~/Desktop/三方平台SDK集成/UnitySDKPackage/
```

两个导出目标：

| 菜单 | 内容 |
|---|---|
| `Export Unity SDK Package` | 只导出 `Assets/Plugins/Sobot` 和必要 Editor 脚本 |
| `Export Unity SDK Demo Package` | 导出插件、Editor 脚本、`StartPage.cs`、`SampleScene.unity` |

如果新增必须随 SDK 分发的文件，需要同步加入 `SobotPackageExporter.cs` 的 `SdkAssetPaths` 或 `DemoAssetPaths`。

## 10. 修改或新增代码

### 10.1 新增 Unity 对外 API

推荐流程：

1. 在 `ZCSobotApi.cs` 中新增公开方法和必要回调。
2. Android：在 `SobotBridge.java` 中新增对应静态方法。
3. iOS：在 `SobotUnityBridge.mm` 中新增 `extern "C"` 方法。
4. 在 `StartPage.cs` 中增加 Demo 按钮或调用示例。
5. 分别在 Android/iOS 真机验证。
6. 如果新功能需要原生依赖、系统权限或资源文件，同步修改 `SobotPostProcessBuild.cs`。

### 10.2 新增参数字段

统一参数对象是：

```text
SobotClientSDKTest/Assets/Plugins/Sobot/ZCSobotApi.cs
```

在 `SobotParams` 中新增字段后，需要同步检查：

- C# 是否通过 `JsonUtility.ToJson` 正确输出字段。
- Android `SobotBridge.java` 是否读取该 JSON 字段并设置到智齿 Android SDK。
- iOS `SobotUnityBridge.mm` 是否读取该 JSON 字段并设置到智齿 iOS SDK。
- `StartPage.cs` 是否需要补充 Demo 参数。

## 11. 开源前建议检查

发布到 GitHub 前建议确认：

- 删除不应公开的账号、密钥、测试用户信息、证书、描述文件。
- Demo 中的 `APP_KEY` 和 `PARTNER_ID` 改成占位值或说明值。
- 清理 Unity 临时目录，例如 `Library/`、`Temp/`、`Obj/`、`Build/`。
- 确认 `.gitignore` 覆盖 Unity 常见中间产物。
- 确认 iOS 原生 SDK、Android Maven SDK 的分发许可允许开源仓库包含或引用。
- 确认 `SobotClientSDK.unitypackage` 是否需要随仓库发布，或改为 Release 附件发布。

## 12. 推荐阅读顺序

新用户建议按以下顺序阅读：

1. `README.md`
2. `SobotUnityIntegrationDemo/README.md`
3. `Unity平台SDK集成/智齿SDK_Unity_SDK_用户集成指南.md`
4. `Unity平台SDK集成/智齿SDK_Unity_SDK_集成对接文档_中文.md`
5. `Unity平台SDK集成/Sobot_Unity_Plugin_Analysis.md`
6. `Unity平台SDK集成/Unity_SDK_打包与Demo制作记录.md`


