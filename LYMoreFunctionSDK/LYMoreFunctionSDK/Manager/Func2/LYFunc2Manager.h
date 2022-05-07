//
//  LYFunc2Manager.h
//  LYMoreFunctionSDK
//
//  Created by Lee on 2022/5/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol LYFunc2ManagerDelegate <NSObject>

@optional

//function 2的回调方法

@end

@protocol LYFunc2Manager <NSObject>

- (void)addDelegate:(id<LYFunc2ManagerDelegate>)delegate;

- (void)removeDelegate;

- (void)func2Test;

@end

NS_ASSUME_NONNULL_END
