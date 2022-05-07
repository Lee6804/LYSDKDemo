//
//  LYFunc1.m
//  LYMoreFunctionSDK
//
//  Created by Lee on 2022/5/7.
//

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
