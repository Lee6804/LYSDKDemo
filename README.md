# iOS SDK架构设计

- [1、背景](#1背景)
- [2、SDK结构](#2sdk结构)
  - [2.1 功能型SDK](#21-功能型sdk)
  - [2.2 业务型SDK](#22-业务型sdk)

## 1、背景

目前SDK的设计总体分为两大类型：

1、功能型：提供单一的功能服务供外部使用，例如：配网SDK、日志SDK、埋点SDK等；

2、业务型：在一个大的业务需求（如实现局域网内APP与设备之间进行通讯）前提之下囊括多个不同的功能。例如：局域网SDK，其中可能会包含：局域网控制、局域网OTA、局域网Log传输等一系列功能。

## 2、SDK结构
### 2.1 功能型SDK
功能型SDK来讲相对简单，外部调用入口主要集中在LYFunctionManager上，此Manager对外提供两种大类方法既可以满足大部分使用场景。

- 代理（delegate）：SDK相关的一些回调方法
- 方法（Methods）：SDK提供给外部调用的一些主动方法

**整体结构示例：**

![image](https://user-images.githubusercontent.com/20941758/167248740-00e42c7c-536d-4d0b-8f96-8531f418c2ec.png)

**代码示例：**
<details>
<summary>LYFunctionManager</summary>
  
  #### LYFunctionManager.h
```Objective-C
#import <Foundation/Foundation.h>
 
NS_ASSUME_NONNULL_BEGIN
 
//代理
@protocol LYFunctionManagerDelegate <NSObject>
 
@optional
 
//回调方法
 
@end
 
@interface LYFunctionManager : NSObject
 
@property (nonatomic, weak) id <LYFunctionManagerDelegate> delegate;
 
+ (instancetype)shared;
 
//调用方法
 
 
@end
 
NS_ASSUME_NONNULL_END
```
  #### LYFunctionManager.m
```Objective-C
#import "LYFunctionManager.h"
 
@implementation LYFunctionManager
 
static LYFunctionManager *_instance = nil;
 
+ (instancetype)shared {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [[LYFunctionManager alloc] init];
    });
    return _instance;
}
 
@end
```
</details>



### 2.2 业务型SDK
业务型SDK主要区别在于，一个SDK内包含多个不同功能，在基于一个整体管理类Manager的基础上，分别进行处理对应的功能逻辑。
  
**设计思路：**

- SDK`仅`提供一个主入口Manager
- 不同功能采用不同Manager进行管理，并在入口Manager中进行声明
- 功能Manager采用`Protocol`方式创建，定义对应的协议方法，并创建一个遵循协议且实现协议方法的功能类
- 无论入口Manager还是功能Manager，都遵循`Delegate+Methods`的方式创建
- 入口Manager一般`不提供`remove delegate的操作，仅在应用启动时开启监听，`全局add一次即可`
- 功能Manager提供add & remove delegate是由于一个功能在执行完操作后，退出时相当于此Manager已完成所需要做的事情，故无需继续监听
- 入口Manager中声明功能Mananger时需采用`strong`修饰

**整体结构示例：**

![image](https://user-images.githubusercontent.com/20941758/167248770-606ca189-ec99-4a6e-a2d1-5262d407f323.png)
  
![image](https://user-images.githubusercontent.com/20941758/167326566-65247aff-b791-473f-803e-11f16eb3fd98.png)
  
**代码示例：**
<details>
<summary>LYMoreFuncManager</summary>
  
  #### LYMoreFuncManager.h
```Objective-C
#import <Foundation/Foundation.h>
#import "LYFunc1Manager.h"
#import "LYFunc2Manager.h"
#import "LYFunc3Manager.h"
 
NS_ASSUME_NONNULL_BEGIN
 
//主代理（整个SDK通用）
@protocol LYMoreFuncManagerDelegate <NSObject>
 
@optional
 
//通用回调方法
 
 
@end
 
@interface LYMoreFuncManager : NSObject
 
@property (nonatomic, weak) id <LYMoreFuncManagerDelegate> delegate;
 
@property (nonatomic, strong) id <LYFunc1Manager> fun1Manager;//功能1
 
@property (nonatomic, strong) id <LYFunc2Manager> fun2Manager;//功能2
 
@property (nonatomic, strong) id <LYFunc3Manager> fun3Manager;//功能3
 
+ (instancetype)shared;
 
//通用调用方法
 
 
@end
 
NS_ASSUME_NONNULL_END
```
  #### LYMoreFuncManager.m
```Objective-C
#import "LYMoreFuncManager.h"
#import "LYFunc1.h"
#import "LYFunc2.h"
#import "LYFunc3.h"
 
@implementation LYMoreFuncManager
 
static LYMoreFuncManager *_instance = nil;
 
+ (instancetype)shared {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [[LYMoreFuncManager alloc] init];
    });
    return _instance;
}
 
- (void)setDelegate:(id<LYMoreFuncManagerDelegate>)delegate {
    if (!_delegate) {
        _delegate = delegate;
        self.fun1Manager = [[LYFunc1 alloc] init];
        self.fun2Manager = [[LYFunc2 alloc] init];
        self.fun3Manager = [[LYFunc3 alloc] init];
    }
}
 
@end
```
</details>

<details>
<summary>LYFunc1Manager</summary>
  
  #### LYFunc1Manager.h
```Objective-C
#import <Foundation/Foundation.h>
 
NS_ASSUME_NONNULL_BEGIN
 
@protocol LYFunc1ManagerDelegate <NSObject>
 
@optional
 
//function 1的回调方法
 
@end
 
@protocol LYFunc1Manager <NSObject>
 
- (void)addDelegate:(id<LYFunc1ManagerDelegate>)delegate;
 
- (void)removeDelegate;
 
- (void)func1Test;
 
@end
 
NS_ASSUME_NONNULL_END
```
</details>
  
<details>
<summary>LYFunc1</summary>
  
  #### LYFunc1.h
```Objective-C
#import <Foundation/Foundation.h>
#import "LYFunc1Manager.h"
 
NS_ASSUME_NONNULL_BEGIN
 
@interface LYFunc1 : NSObject <LYFunc1Manager>
 
@end
 
NS_ASSUME_NONNULL_END
```
   #### LYFunc1.m
```Objective-C
#import "LYFunc1.h"
 
@interface LYFunc1 () <LYFunc1ManagerDelegate>
 
@property (nonatomic, weak) id<LYFunc1ManagerDelegate> func1Delegate;
 
@end
 
@implementation LYFunc1
 
- (void)addDelegate:(id<LYFunc1ManagerDelegate>)delegate {
    if (delegate && !self.func1Delegate) {
        self.func1Delegate = delegate;
    }
}
 
- (void)removeDelegate {
    self.func1Delegate = nil;
}
 
- (void)func1Test {
     
}
 
@end
```
</details>
