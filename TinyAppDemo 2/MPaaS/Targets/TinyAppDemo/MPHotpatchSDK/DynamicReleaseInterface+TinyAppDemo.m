//
//  DynamicReleaseInterface+TinyAppDemo.m
//  TinyAppDemo
//
//  Created by quinn on 2018/07/23. All rights reserved.
//

#import "DynamicReleaseInterface+TinyAppDemo.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"

@implementation DynamicReleaseInterface (TinyAppDemo)

- (NSString*)AESEncryptionKeyName
{
    return @"0D4F511232152_IOS";
}

//#ifdef MPNebulaHandler
- (id<NebulaHandler>)getNebulaHandler
{
    NARequestManager *handle = [NARequestManager sharedInctance];
    return handle;
}
//#endif

@end

#pragma clang diagnostic pop

