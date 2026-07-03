# 智齿 SDK Unity 封装分析文档

## 项目背景

将智齿客服原生 Android SDK 和 iOS SDK 封装为 Unity Package，供 Unity 游戏/应用开发者使用。

## SDK 功能分析

### iOS SDK（SobotKit.xcframework）

核心类：
- `ZCSobotApi` - 主入口，提供所有功能接口
- `ZCLibClient` - 全局配置，管理 libInitInfo
- `ZCLibInitInfo` - 初始化参数（用户信息、接待模式等）
- `ZCKitInfo` - UI 参数（颜色、控件显隐等）

已有资源（Assets/Plugins/Sobot/iOS/frameworks）：
- `SobotKit.xcframework` - UI 代码库
- `SobotCommon.xcframework` - 基础代码库
- `SobotChatClient.xcframework` - 接口代码库
- `SobotKit.bundle` - 资源库（图片、多语言）

### Android SDK

核心类：
- `ZCSobotApi` - 主入口
- `Information` - 启动配置参数类

集成方式：Maven 依赖 `com.sobot.chat:client:+`

## 功能范围映射

| 功能 | iOS 接口 | Android 接口 | Unity 封装方法 |
|------|---------|-------------|--------------|
| 初始化 | `[ZCSobotApi initSobotSDK:host:result:]` | `ZCSobotApi.initSobotSDK()` | `ZCSobotApi.InitSobotSDK()` |
| 启动聊天 | `[ZCSobotApi openZCChat:with:pageBlock:]` | `ZCSobotApi.openZCChat()` | `ZCSobotApi.OpenZCChat()` |
| 启动帮助中心 | `[ZCSobotApi openZCServiceCenter:with:onItemClick:]` | `ZCSobotApi.openZCServiceCenter()` | `ZCSobotApi.OpenZCServiceCenter()` |
| 启动留言 | `[ZCSobotApi openLeaveisOnlyShowRecored:Kitinfo:with:onItemClick:]` | `ZCSobotApi.openLeave()` | `ZCSobotApi.OpenLeave()` |
| 监听链接点击 | `[ZCSobotApi setMessageLinkClick:]` | `ZCSobotApi.setNewHyperlinkListener()` | `ZCSobotApi.SetLinkClickListener()` |
| 关闭会话 | `[ZCSobotApi outCurrentUserZCLibInfo:]` | `ZCSobotApi.outCurrentUserZCLibInfo()` | `ZCSobotApi.CloseSession()` |
| 获取未读消息 | `[ZCSobotApi getOfflineMsgAndUnAckMsgWith:appkey:resultBlock:]` | `ZCSobotApi.offlineMsgSize()` | `ZCSobotApi.GetOfflineMessageCount()` |

## 架构设计

```
Unity C# (ZCSobotApi.cs)
    ├── UNITY_EDITOR  → Debug.Log 模拟
    ├── UNITY_ANDROID → AndroidJavaClass/AndroidJavaProxy 调用
    └── UNITY_IOS     → DllImport 调用 .mm 桥接层
                            └── SobotUnityBridge.mm → 原生 ObjC SDK
```

## 注意事项

1. iOS 需要在 Xcode 中添加系统框架依赖：AVFoundation、AssetsLibrary、AudioToolbox、SystemConfiguration、MobileCoreServices、WebKit
2. iOS 需要在 Info.plist 添加权限：相机、麦克风、相册
3. Android 需要在 build.gradle 添加 `com.sobot.chat:client:+` 依赖
4. partnerid 不能写死固定值，同一 ID 的聊天记录会共享
5. 所有 SDK 接口必须在初始化完成后调用
