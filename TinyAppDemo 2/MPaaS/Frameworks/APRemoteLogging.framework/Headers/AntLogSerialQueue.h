//
//  AntLogSerialQueue.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2017/1/15.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^AntLogTask)(void);

/**
 日志串行队列.
 GCD队列中执行Block时存在偶现的系统Crash,该类用于代替GCD的串行队列.
 内部封装了一个日志专用线程,线程名为"com.aliapy.antlog"
 */
@interface AntLogSerialQueue : NSObject

/**
 获取日志专用线程对象单例.

 @return 日志专用线程对象.
 */
+ (NSThread *)internalThread;

/**
 同步入队一个日志任务.
 @note 该方法会阻塞当前线程直至\c block 执行完成.

 @param block 待入队的日志任务.  @see \c AntLogTask
 */
+ (void)enqueueTaskSync:(AntLogTask)block;

/**
 异步入队一个日志任务.
 @note 该方法会立即返回.
 
 @param block 待入队的日志任务.  @see \c AntLogTask
 */
+ (void)enqueueTaskAsync:(AntLogTask)block;

@end

#pragma mark - 
#pragma mark NSTread Addon

@interface NSThread (AntLog)

/**
 查询该线程是否为日志专用线程

 @return 该线程为日志专用线程时返回 \c YES , 否则返回 \c NO .
 */
- (BOOL)isAntLogThread;

@end
