//
//  LYFunctionManager.h
//  LYFunctionSDK
//
//  Created by Lee on 2022/5/7.
//

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


