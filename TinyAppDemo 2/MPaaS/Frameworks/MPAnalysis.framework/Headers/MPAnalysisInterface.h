//
//  MPAnalysisInterface.h
//  MPAnalysis
//
//  Created by yangwei on 16/12/7.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MPAnalysisInterface : NSObject

+ (instancetype)sharedInstance;

/**
 *  后台回前台时，是否进行报活
 *  该方法默认实现为YES。
 */
- (BOOL)shouldLogReportActiveWillEnterForeground;

/**
 *  当使用日志报活功能时，可以配置从后台切回前台的报活最小间隔时间。
 *  从后台切回前台时，距离上次报活时间少于多少秒时，不再报活。如果传0，每次后台切回前台都会报活。
 *  这个不影响冷启动，如果冷启动，每次都会报活。
 *  该方法默认返回0，单位秒(s)
 */
- (NSTimeInterval)logReportActiveMinInterval;

@end
