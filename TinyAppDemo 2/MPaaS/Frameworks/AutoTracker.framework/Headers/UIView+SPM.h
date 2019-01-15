//
//  DTRpcClient+AddAPMonitor.h
//  APMonitor
//
//  Created by zhiyuan.yzy on 14-2-13.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (SPM)

/**
 SPM值. 落入自动化埋点模型的字段16
 */
@property (nonatomic, strong) NSString *logSpmId;

/**
 SCM(EntityId)值.落入自动化埋点模型的字段15
 */
@property (nonatomic, strong) NSString *logEntityId;

/**
 埋点扩展参数4，字典会被转换成@“key1=value1^key2=value2”落入自动化埋点模型的字段23.
 */
@property (nonatomic, strong) NSDictionary *logExtendParam;

/**
 SPM值. 已废弃，使用logSpmId代替。
 */
@property (nonatomic, strong) NSString *spmTag __deprecated_msg("Use logSpmId instead.");

@end
