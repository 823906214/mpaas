//
//  APRemoteLogger+AntLog.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2017/9/29.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <APRemoteLogging/APRemoteLogging.h>
#import "AntBehavior.h"
#import "AntPerformance.h"

@interface APRemoteLogger (AntLog)
/**
 行为埋点接口
 
 @param behavior 行为埋点信息. @see \c AntBehavior.
 */
+ (void)logBehavior:(AntBehavior *)behavior;

/**
 性能埋点接口
 
 @param performance 性能埋点信息. @see \c AntPerformance.
 */
+ (void)logPerformance:(AntPerformance *)performance;
@end
