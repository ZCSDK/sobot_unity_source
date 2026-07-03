# 本地构建缓存清理方案

## 背景

iOS 导出失败时，Unity 日志中出现了旧设备路径：

```text
/Users/zhangxinyao/Documents/project/unity/...
```

这不是业务代码问题，而是 Unity IL2CPP/Bee 构建缓存中保存了上一台设备的绝对路径。项目换机器、换目录、协作交接后，如果继续复用这些本地生成物，就可能导致 iOS 导出失败、Xcode 工程未刷新、真机运行仍是旧代码。

## 已落地内容

1. 通用命令行脚本：

```text
docs/sh/clean_local_build_cache.sh
```

2. Unity 编辑器菜单：

```text
Sobot -> Clean Local Build Cache -> iOS IL2CPP Cache
Sobot -> Clean Local Build Cache -> Unity Build Cache
Sobot -> Clean Local Build Cache -> iOS Exported Build Outputs
Sobot -> Clean Local Build Cache -> Generated Build Outputs
Sobot -> Clean Local Build Cache -> Scan Absolute Paths
```

脚本和菜单都从当前项目根目录动态计算路径，不依赖 `/Users/lizh`、`/Users/zhangxinyao` 等设备路径。

## 推荐处理 iOS 导出失败

先关闭 Unity 和 Xcode，然后执行：

```bash
cd "/Users/lizh/Documents/智齿项目文件/U3D/Zhichi/SobotClientSDKTest"
bash docs/sh/clean_local_build_cache.sh --profile unity-ios
```

如果想先确认会删除哪些目录：

```bash
bash docs/sh/clean_local_build_cache.sh --profile unity-ios --dry-run
```

清理后重新打开 Unity，再执行：

```text
Build Settings -> iOS -> Build
```

建议导出到独立新目录：

```text
builder/iOSnew
```

不要导出到旧工程内部的子目录，例如：

```text
builder/iOS/iOSnew
```

如果已经导出到了旧工程子目录，`unity-ios` 会同时清理：

```text
Library/Il2cppBuildCache/iOS
Temp/StagingArea
builder/iOS/iOSnew
builder/iOSnew
```

这样可以避免 IL2CPP 生成代码继续引用旧 C# 类型名或旧路径。

## 跨技术栈使用

这个脚本可以复制到其他项目中使用，也可以显式传入项目根目录：

```bash
bash docs/sh/clean_local_build_cache.sh "/path/to/project" --profile scan
bash docs/sh/clean_local_build_cache.sh "/path/to/project" --profile mobile --dry-run
```

可用 profile：

| profile | 用途 |
| --- | --- |
| `unity-ios` | 清理 Unity iOS IL2CPP 路径敏感缓存和 iOS 导出工程，默认推荐 |
| `unity` | 清理 Unity 常见本地构建缓存 |
| `mobile` | 清理 Unity iOS、导出的 iOS/Android 工程、Gradle、Xcode 本地缓存 |
| `node` | 清理前端项目常见本地缓存 |
| `scan` | 只扫描生成物中的绝对路径，不删除 |
| `all` | 清理脚本已识别的所有本地生成缓存 |

## 注意事项

1. 清理前关闭 Unity/Xcode，避免正在构建或导入资源。
2. 脚本只处理可再生成的本地缓存和 `builder` 下的导出工程，不处理 `Assets`、`Packages`、`ProjectSettings`、插件源码。
3. 如果清理后仍显示旧访客昵称，需要卸载手机 App 后重装，或者临时更换 `partnerid` 排除 SDK/服务端访客缓存。
