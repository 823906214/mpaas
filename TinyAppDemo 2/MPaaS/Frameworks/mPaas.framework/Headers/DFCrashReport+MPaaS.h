//
//  DFCrashReport+MPaaS.h
//  APCrashReporter
//
//  Created by shenmo on 5/5/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

@protocol DFCrashReportClass <NSObject>

/**
 *  上传crash日志
 */
+ (void)uploadCrashReport;

/**
 *  获取内存中所有的VC
 *
 *  @return 返回包含所有VC的字符串
 */
+ (NSString *) allAliveVc;

/**
 *  开启Low Memory Crash Log收集服务
 */
+ (void)enableMemoryCrashReport;

@end