//
//  UIViewController+Log.h
//  APMonitor
//
//  Created by tashigaofei on 15/5/26.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController (AT)

@property (nonatomic, strong) NSString *appId;
@property (nonatomic, strong) NSString *logPageId;
@property (nonatomic, strong) NSString *logPageTitle;
@property (nonatomic, strong) NSString *logSourceAppId;

/**
 业务自定义的ABTestInfo值，落入自动化埋点模型的字段10.
 业务未赋值时，SDK内部会根据logSpmId自动查询ABTestSDK命中的实验ID列表作为替代.
 */
@property (atomic, strong) NSString *logABTestInfo;

/**
 SCM(EntityId)值,落入自动化埋点模型的字段15.
 */
@property (atomic, strong) NSString *logEntityId;

/**
 SPM值，落入自动化埋点模型的字段16
 */
@property (atomic, strong) NSString *logSpmId;

/**
 埋点扩展参数4，字典会被转换成@“key1=value1^key2=value2”落入自动化埋点模型的字段23.
 */
@property (atomic, strong) NSDictionary *logExtendParam;

@end
