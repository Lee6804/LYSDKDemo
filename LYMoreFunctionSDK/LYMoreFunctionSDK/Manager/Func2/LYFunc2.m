//
//  LYFunc2.m
//  LYMoreFunctionSDK
//
//  Created by Lee on 2022/5/7.
//

#import "LYFunc2.h"

@interface LYFunc2 () <LYFunc2ManagerDelegate>

@property (nonatomic, weak) id<LYFunc2ManagerDelegate> func2Delegate;

@end

@implementation LYFunc2

- (void)addDelegate:(id<LYFunc2ManagerDelegate>)delegate {
    if (delegate && !self.func2Delegate) {
        self.func2Delegate = delegate;
    }
}

- (void)removeDelegate {
    self.func2Delegate = nil;
}

- (void)func2Test {
    
}


@end
