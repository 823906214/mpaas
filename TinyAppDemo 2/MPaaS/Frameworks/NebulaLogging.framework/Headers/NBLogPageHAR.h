//
//  H5PageHAR.h
//  NebulaBiz
//
//  Created by 章海滨 on 2017/4/30.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NBLogPageHAR : NSObject

/**
 立即将现有采集的HAR集合写入沙盒
 */
+ (void) saveHARFiles;

/**
 记录当前HAR并触发写入
 */
- (void) triggerRecord;

/**
 将当前HAR缓存到临时数组
 */
- (void) addCurrentHAR2TempPool;

/**
 采集pageload和domReady时间
 */
- (void) setPagesWithMainUrl:(NSString *)mainUrl startDate:(NSDate *)startDate onContentLoad:(NSTimeInterval)onContentLoad onLoad:(NSTimeInterval)onLoad;

/**
 采集网络发起
 */
- (void) addRequest:(NSURLRequest *)request WithUniqueId:(NSString *)uniqueId requestTime:(NSDate *) requestTime;

/**
 采集网络返回
 */
- (void) addEntriesWithUniqueId:(NSString *)uniqueId response:(NSHTTPURLResponse *)response receiveData:(NSData *)receiveData responseTime:(NSDate *)responseTime;

@end
