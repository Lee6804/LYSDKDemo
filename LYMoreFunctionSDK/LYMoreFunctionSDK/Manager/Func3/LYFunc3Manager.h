//
//  LYFunc3Manager.h
//  LYMoreFunctionSDK
//
//  Created by Lee on 2022/5/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol LYFunc3ManagerDelegate <NSObject>

@optional

//function 3的回调方法

@end

@protocol LYFunc3Manager <NSObject>

- (void)addDelegate:(id<LYFunc3ManagerDelegate>)delegate;

- (void)removeDelegate;

- (void)func3Test;

@end

NS_ASSUME_NONNULL_END
