//
//  LYFunctionManager.m
//  LYFunctionSDK
//
//  Created by Lee on 2022/5/7.
//

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
