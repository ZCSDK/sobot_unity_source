# Unity SDK 二阶段主动发送消息实施计划

生成时间：2026-06-24  
参考项目：`/Users/lizh/Documents/智齿项目文件/DcloudV7/sobot_chat_client_v7_uts/`  
Unity 项目：`/Users/lizh/Documents/智齿项目文件/U3D/Zhichi/SobotClientSDKTest`

## 1. 本阶段目标

二阶段参考 UNI 插件中的主动发送消息能力，将以下能力同步到 Unity 插件：

| 能力 | Unity 二阶段外抛方法 | 说明 |
|---|---|---|
| 主动发送自定义卡片 | `sendCustomCardToChat(SobotParams param)` | 消费 `param.custom_card`。 |
| 主动发送商品卡片 | `sendProductInfo(SobotParams param)` | 消费 `goodsTitle`、`goodsLink` 等商品字段。 |
| 主动发送订单卡片 | `sendOrderGoodsInfo(SobotParams param)` | 消费 `orderCode`、`goods` 等订单字段。 |
| 主动发送定位消息 | `sendLocation(SobotParams param)` | 二阶段需要给 `SobotParams` 补充定位字段。 |

本阶段先只输出方案，不直接修改代码。代码需要在方案确认后再执行，并在执行后补充代码落地文档。

## 2. UNI 当前差异理解

UNI 项目当前主动发送商品和订单存在平台不对称：

| 方法 | Android | iOS | 现状问题 |
|---|---|---|---|
| `sendProductInfo(options)` | 有实现，参数为 `ZCProductInfoOptions` | 空实现 | Android 可用，iOS 不可用。 |
| `sendProductInfoObj(productInfoObj)` | 空实现 | 有实现，参数为 `UTSJSONObject` | iOS 可用，Android 不可用。 |
| `sendOrderGoodsInfo(options)` | 有实现，参数为 `ZCOrderGoodsOptions` | 空实现 | Android 可用，iOS 不可用。 |
| `sendOrderGoodsInfoObj(orderGoodsObj)` | 空实现 | 有实现，参数为 `UTSJSONObject` | iOS 可用，Android 不可用。 |

这两个 Obj 方法不是独立业务能力，而是因为 UNI 双端参数形态不同临时拆出来的兼容方法。Unity 二阶段不继续复制这种不对称 API，而是在 Unity 层统一只保留：

```csharp
ZCSobotApi.sendProductInfo(param);
ZCSobotApi.sendOrderGoodsInfo(param);
```

Android 和 iOS 的参数差异全部收敛到各自桥接层内部处理。

## 3. Unity 对外 API 设计

二阶段建议新增 4 个外抛方法：

```csharp
public delegate void SendMessageResultCallback(bool success, int code, string message);

public static void sendCustomCardToChat(SobotParams param, SendMessageResultCallback callback = null);
public static void sendProductInfo(SobotParams param, SendMessageResultCallback callback = null);
public static void sendOrderGoodsInfo(SobotParams param, SendMessageResultCallback callback = null);
public static void sendLocation(SobotParams param, SendMessageResultCallback callback = null);
```

不新增以下 Unity 方法：

```csharp
sendProductInfoObj(...)
sendOrderGoodsInfoObj(...)
```

原因：

1. Unity 已经统一使用 `SobotParams` 一个大对象，不需要再区分 typed options 和 object options。
2. Unity 到原生层本身就是 JSON 字符串桥接，Android 可解析为 `JSONObject`，iOS 可解析为 `NSDictionary`。
3. 对外 API 越少，三端文档越容易统一，也避免客户按平台写分支。

## 4. 参数对象调整

继续沿用第一阶段的 `SobotParams`，不新增 `SobotProductParams`、`SobotOrderParams`、`SobotLocationParams`。

二阶段需要新增定位字段：

| 字段 | 类型 | 必填 | 说明 |
|---|---|---|---|
| `lat` | `string` | `sendLocation` 必填 | 纬度。 |
| `lng` | `string` | `sendLocation` 必填 | 经度。 |
| `localLabel` | `string` | 否 | 位置地址标签。 |
| `localName` | `string` | 否 | 位置名称。 |
| `file` | `string` | 否 | 位置截图或文件路径。 |

现有字段继续复用：

| 方法 | 必填字段 | 可选字段 |
|---|---|---|
| `sendCustomCardToChat` | `custom_card` | 使用 Unity Demo 中的 `custom_card` 自定义卡片 JSON 字符串样式。 |
| `sendProductInfo` | `goodsTitle`、`goodsLink` | `goodsDesc`、`goodsLabel`、`goodsImage`、`isSendInfoCard`、`isEveryTimeSendCard`。 |
| `sendOrderGoodsInfo` | `orderCode` | `orderStatus`、`statusCustom`、`createTime`、`goodsCount`、`orderUrl`、`goods`、`totalFee`、`autoSendOrderMessage`、`isEveryTimeAutoSend`。`goods` 使用 Unity Demo 中的 JSON 数组字符串样式。 |
| `sendLocation` | `lat`、`lng` | `localLabel`、`localName`、`file`。 |

说明：

1. 商品卡片 `goodsTitle` 和 `goodsLink` 按 iOS `ZCProductInfo` 头文件要求作为必填。
2. Android `ZCSobotApi.sendOrderGoodsInfo` 源码会在 `orderCode` 为空时直接返回，所以 Unity 侧将 `orderCode` 作为订单主动发送的跨端必填字段。
3. `goods` 统一使用 Unity Demo 当前示例的 JSON 数组字符串形态，例如 `[{ "name": "商品名称", "pictureUrl": "图片URL" }]`，不使用 `{ "goods": [...] }` 包裹格式。
4. `custom_card` 统一使用 Unity Demo 当前示例的自定义卡片 JSON 字符串形态，字段结构按 Demo 的 `CreateDemoCustomCardJson()` 对齐。

## 5. 双端原生调用映射

Android 二阶段调用：

| Unity 方法 | Android SDK 调用 | 桥接模型 |
|---|---|---|
| `sendCustomCardToChat` | `ZCSobotApi.sendCustomCard(context, card)` | `SobotChatCustomCard` |
| `sendProductInfo` | `ZCSobotApi.sendProductInfo(context, content)` | `ConsultingContent` |
| `sendOrderGoodsInfo` | `ZCSobotApi.sendOrderGoodsInfo(context, order)` | `OrderCardContentModel` |
| `sendLocation` | `ZCSobotApi.sendLocation(context, location)` | `SobotLocationModel` |

iOS 二阶段调用：

| Unity 方法 | iOS SDK 调用 | 桥接模型 |
|---|---|---|
| `sendCustomCardToChat` | `[ZCSobotApi sendCustomCardToChat:resultBlock:]` | `SobotChatCustomCard` |
| `sendProductInfo` | `[ZCSobotApi sendProductInfo:resultBlock:]` | `ZCProductInfo` |
| `sendOrderGoodsInfo` | `[ZCSobotApi sendOrderGoodsInfo:resultBlock:]` | `ZCOrderGoodsModel` |
| `sendLocation` | `[ZCSobotApi sendLocation:resultBlock:]` | `NSDictionary` |

## 6. 桥接层实施思路

Unity C#：

1. `SobotParams` 增加 `lat`、`lng`、`localLabel`、`localName`、`file`。
2. `ZCSobotApi` 增加 4 个 public static 方法，并预留 `SendMessageResultCallback callback = null` 参数。
3. Editor 模式只做参数校验和 `Debug.Log` 模拟，不做真实发送。
4. Android 调 `SobotBridge` 同名静态方法。Android 原生主动发送接口没有直接结果回调，第一版可以暂不回调 Unity。
5. iOS 通过 `DllImport("__Internal")` 调 `_sobotSendCustomCardToChat`、`_sobotSendProductInfo`、`_sobotSendOrderGoodsInfo`、`_sobotSendLocation`，并通过 iOS `resultBlock` 回调 Unity。

Android 桥接：

1. 复用或抽取现有 `buildCustomCard(JSONObject)`。
2. 将当前 `applyConsultingContent(...)` 中的商品卡片构建逻辑抽为 `buildConsultingContent(JSONObject)`，供启动参数和主动发送共同使用。
3. 将当前 `applyOrderGoodsInfo(...)` 中的订单卡片构建逻辑抽为 `buildOrderGoodsInfo(JSONObject)`，供启动参数和主动发送共同使用。
4. 新增 `buildLocation(JSONObject)`，映射 `lat`、`lng`、`localLabel`、`localName`、`file`。
5. 对必填字段缺失只记录日志并 return，不抛异常中断 Unity。

iOS 桥接：

1. 复用现有 `buildCustomCard(...)`、`buildProductInfo(...)`、`buildOrderGoodsInfo(...)`。
2. `buildProductInfo(...)` 保持 `goodsTitle`、`goodsLink` 必填，其余字段有值才赋值。
3. `buildOrderGoodsInfo(...)` 用于主动发送时至少检查 `orderCode`，其余字段有值才赋值。
4. `goods` 只解析 Unity Demo 样式的 JSON 数组字符串。
5. iOS 原生 `resultBlock` 调用 Unity 预留的 `SendMessageResultCallback`；Android 第一版可以暂不回调。

## 7. Demo 调整计划

方案确认并落代码后，`Assets/StartPage.cs` 增加 4 个按钮：

```csharp
ZCSobotApi.sendCustomCardToChat(CreateDemoParams(), OnSendMessageResult);
ZCSobotApi.sendProductInfo(CreateDemoParams(), OnSendMessageResult);
ZCSobotApi.sendOrderGoodsInfo(CreateDemoParams(), OnSendMessageResult);
ZCSobotApi.sendLocation(CreateDemoParams(), OnSendMessageResult);
```

Demo 参数沿用现有商品、订单、自定义卡片测试数据，并补充定位测试数据：

```csharp
lat = "39.908823";
lng = "116.397470";
localLabel = "北京市东城区东长安街";
localName = "天安门";
file = "";
```

## 8. 验证计划

代码落地后需要按以下顺序验证：

1. C# 小范围编译检查，确认新增 API 和 `SobotParams` 字段无语法问题。
2. iOS `SobotUnityBridge.mm` 使用 `clang -fsyntax-only` 做语法检查。
3. Android 确认当前 Maven SDK 版本包含 `sendCustomCard`、`sendProductInfo`、`sendOrderGoodsInfo`、`sendLocation`。
4. Unity Editor 点击 Demo 按钮，确认参数校验日志符合预期。
5. Android 真机进入聊天页面后分别点击 4 个主动发送按钮，观察聊天消息是否出现。
6. iOS 真机进入聊天页面后分别点击 4 个主动发送按钮，观察聊天消息是否出现，并查看 Xcode 日志和 Unity 回调中的 `resultBlock` 结果。
7. Android 第一版可只验证消息是否出现，不强制验证 Unity 结果回调。

## 9. 风险和待确认项

1. 主动发送类 API 必须在 `initSobotSDK` 初始化成功之后调用；Demo 和文档都需要明确提示先初始化成功，再打开或进入聊天场景后发送。
2. Unity 外抛方法先预留发送结果回调参数；iOS 使用原生 `resultBlock` 回调，Android 当前主动发送接口是本地广播，无直接结果回调，第一版 Android 可以暂不回调。
3. `goods` 字段统一使用 Unity Demo 当前示例的 JSON 数组字符串样式，不使用 UNI 文档中的 `{ "goods": [...] }` 包裹格式。
4. `custom_card` 字段统一使用 Unity Demo 当前示例的自定义卡片 JSON 字符串样式，继续用字符串承载动态对象，避免强类型字段丢失扩展内容。
5. 二阶段不处理文本、图片、文件、视频等主动发送能力，避免扩大范围。
