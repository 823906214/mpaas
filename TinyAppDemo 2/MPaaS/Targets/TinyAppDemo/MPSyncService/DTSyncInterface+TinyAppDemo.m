//
//  DTSyncInterface+TinyAppDemo.m
//  TinyAppDemo
//
//  Created by quinn on 2018/07/23. All rights reserved.
//

#import "DTSyncInterface+TinyAppDemo.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"

@implementation DTSyncInterface (TinyAppDemo)

- (NSString*)appId
{
    return @"0D4F511232152";
}

- (NSString*)platform
{
    return @"IOS";
}

- (NSString*)workspaceId
{
    return @"default";
}

- (int)syncPort
{
    return 443;
}

- (NSString*)syncServer
{
    return @"cn-hangzhou-mss-link.cloud.alipay.com";
}

@end

#pragma clang diagnostic pop

