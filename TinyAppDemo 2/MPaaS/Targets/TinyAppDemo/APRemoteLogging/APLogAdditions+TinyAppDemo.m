//
//  APLogAdditions+TinyAppDemo.m
//  TinyAppDemo
//
//  Created by quinn on 2018/07/23. All rights reserved.
//

#import "APLogAdditions+TinyAppDemo.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"

@implementation APLogAdditions (TinyAppDemo)

- (NSString*)logServerURL
{
    return @"https://cn-hangzhou-mas-log.cloud.alipay.com/loggw/logUpload.do";
}

- (NSArray*)defaultUploadLogTypes
{
    return @[@(APLogTypeBehavior), @(APLogTypeCrash), @(APLogTypeAuto), @(APLogTypeMonitor), @(APLogTypeKeyBizTrace), @(APLogTypePerformance)];
}

- (NSString *)platformID
{
    return @"0D4F511232152_IOS-default";
}

@end

#pragma clang diagnostic pop

