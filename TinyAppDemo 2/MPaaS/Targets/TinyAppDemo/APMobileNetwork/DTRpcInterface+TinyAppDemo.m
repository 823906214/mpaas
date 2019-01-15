//
//  DTRpcInterface+TinyAppDemo.m
//  TinyAppDemo
//
//  Created by quinn on 2018/07/23. All rights reserved.
//

#import "DTRpcInterface+TinyAppDemo.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"

@implementation DTRpcInterface (TinyAppDemo)

- (NSString*)gatewayURL
{
    return @"https://cn-hangzhou-mgs-gw.cloud.alipay.com/mgw.htm";
}

- (NSString*)signKeyForRequest:(NSURLRequest*)request
{
    return @"0D4F511232152_IOS";
}

- (NSString *)productId
{
    return @"0D4F511232152";
}

- (NSString*)commonInterceptorClassName
{
    return @"DTRpcCommonInterceptor";
}

@end

#pragma clang diagnostic pop

