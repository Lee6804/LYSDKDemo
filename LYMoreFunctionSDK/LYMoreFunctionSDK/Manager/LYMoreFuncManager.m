//
//  LYMoreFuncManager.m
//  LYMoreFunctionSDK
//
//  Created by Lee on 2022/5/7.
//

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
