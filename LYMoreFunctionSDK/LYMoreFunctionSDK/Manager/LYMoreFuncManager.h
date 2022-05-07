//
//  LYMoreFuncManager.h
//  LYMoreFunctionSDK
//
//  Created by Lee on 2022/5/7.
//

#import <Foundation/Foundation.h>
#import <LYMoreFunctionSDK/LYFunc1Manager.h>
#import <LYMoreFunctionSDK/LYFunc2Manager.h>
#import <LYMoreFunctionSDK/LYFunc3Manager.h>

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


