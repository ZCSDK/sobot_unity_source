# 这是一个unity项目，希望封装原生实现的Android 和 iOS SDK成为一个package包，供客户使用



# 封装步骤

## 规则说明

### 生成新文件存放说明
1. 所有分析类文档放到 docs/Analyze 目录
2. 所有归档类文档放到 docs/Archive 目录
3. 所有可执行总结类文档放到 docs/Guide 目录
4. 脚本 docs/sh 目录
5. 脚本 docs/export 目录
6. 所有计划打包到package包中的文件，放到Assets/Plugins/Sobot目录


### 文件使用规则
1. 所有非项目的文档说明，使用md格式
2. 封装SDK的入口文件，统一使用Assets/Plugins/Sobot/ZCSobotApi文件
3. 可以新增文件或文件夹用于辅助和方便完成工作


### 资料使用
1. Android 参考 https://developer.zhichi.com/pages/60a57e 对接说明

2. iOS 参考 https://developer.zhichi.com/pages/53f6b3/ 对接说明

3.iOS 的相关资源已经存放到Assets/Plugins/Sobot/iOS/frameworks,可直接使用


### 功能范围
1. 基础功能：初始化、启动帮助中心、启动聊天、启动留言功能

2.辅助功能：监听链接点击、关闭会话、获取未读离线消息



### 功能调用
1. 再Assets/StartPage文件，完成简单功能测试demo，要求demo需要适配iOS和Android

