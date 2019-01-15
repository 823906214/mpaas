//
//  NBLogSPMHelper.h
//  NebulaBiz
//
//  Created by Glance on 16/8/10.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

static const char *kNBSPMInfo_KEY = "kNBSPMInfo_KEY";


@interface H5SPMToken : NSObject<NSCopying>

@property (nonatomic, copy) NSString *uuid;

@end


@interface NBSPMInfo : NSObject

@property(nonatomic, strong) NSString *spmId;
@property(nonatomic, strong) H5SPMToken *spmToken;
@property(nonatomic, strong) NSString *bizType;
@property(nonatomic, strong) NSString *chInfo;
@property(nonatomic, strong) NSDictionary *spmDetail;

@end


@interface NBSPMHelper : NSObject

+ (NSDictionary *)getTracerInfoFromScene:(PSDScene *)scene;

+ (H5SPMToken *)tokenOfPSDContentView:(PSDContentView *)view;

+ (void)logPageStartWithSpmId:(NSString *)spmId index:(NSObject *)index;

+ (void)logPageEndWithSpmId:(NSString *)spmId index:(NSObject *)index bizType:(NSString *)bizType param:(NSDictionary *)param;

+ (void)updateLastSpm:(NSString *)spmId index:(NSObject *)index;

@end

