//
//  LYFunc3.m
//  LYMoreFunctionSDK
//
//  Created by Lee on 2022/5/7.
//

#import "LYFunc3.h"

@interface LYFunc3 () <LYFunc3ManagerDelegate>

@property (nonatomic, weak) id<LYFunc3ManagerDelegate> func3Delegate;

@end

@implementation LYFunc3

- (void)addDelegate:(id<LYFunc3ManagerDelegate>)delegate {
    if (delegate && !self.func3Delegate) {
        self.func3Delegate = delegate;
    }
}

- (void)removeDelegate {
    self.func3Delegate = nil;
}

- (void)func3Test {
    
}

@end
