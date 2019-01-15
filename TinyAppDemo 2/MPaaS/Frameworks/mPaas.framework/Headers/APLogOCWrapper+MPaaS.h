//
//  APLogOCWrapper+MPaaS.h
//  APMobileFoundation
//
//  Created by shenmo on 5/5/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

@protocol APLogOCWrapperClass <NSObject>

+ (void)APLogWarn:(NSString*)tag format:(NSString*)format, ...;
+ (void)APLogDebug:(NSString*)tag format:(NSString*)format, ...;
+ (void)APLogInfo:(NSString*)tag format:(NSString*)format, ...;
+ (void)APLogError:(NSString*)tag format:(NSString*)format, ...;

/**
 *  APLogMonitor对应APLog.h中的APLogMonitor方法，当DEBUG时生效，发布版不生效。
 */
+ (void)APLogMonitor:(NSString*)tag format:(NSString*)format, ...;

@end