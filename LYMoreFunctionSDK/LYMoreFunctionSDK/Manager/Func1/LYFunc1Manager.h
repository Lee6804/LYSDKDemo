//
//  LYFunc1Manager.h
//  LYMoreFunctionSDK
//
//  Created by Lee on 2022/5/7.
//

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
