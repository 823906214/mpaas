//
//  APMobileIdentifier.h
//  APMobileIdentifer
//
//  Created by WenBi on 14-1-21.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APMobileIdentifier : NSObject

+ (APMobileIdentifier *)shareIdentifier;
    
@property(nonatomic, copy) NSString *UTDID;
@property(nonatomic, copy) NSString *IMSI;
@property(nonatomic, copy) NSString *IMEI;
@property(nonatomic, copy) NSString *UUID;
@property(nonatomic, copy) NSString *TID;
@property(nonatomic, copy) NSString *deviceFingerprint;
@property(readonly) NSString *AWID;
@property(readonly) NSString *clientId;
@property(nonatomic, strong, readonly) NSString *deviceModel;
@property(nonatomic, assign, readonly) unsigned long memoryAwailable;
@property(nonatomic, assign, readonly) int diskTotalSpace;

@end

// 为了兼容性
@interface MPMobileIdentifier : APMobileIdentifier

@end