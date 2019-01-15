//
//  MPThreadManager.h
//  MPThreadManager
//
//  Created by shenmo on 12/28/14.
//  Copyright (c) 2014 shenmo. All rights reserved.
//

#import <UIKit/UIKit.h>

#pragma mark APThreadManager.h

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    typedef enum _APTBizType
    {
        APTBiz_Unknown  = 0,
    }APTBizType;
    
    /**
     *  异步到子线程执行block。
     *
     *  @param bizType      调用的业务类型，方便框架统一针对当前所处业务进行线程使用调优。无特殊的和不确定的，统一填0。
     *  @param tag          调用的标识串，方便跟进调用方，跟进性能、线程资源消耗等问题。目前统一填__FUNCTION__。
     *  @param delayTime    延迟执行时间，单位：秒。不延迟填0即可。
     *  @param priority     优先级，方便排队管理。系统定义的5级优先级＋扩展优先级。
     *                      扩展优先级（10000:最高优先执行，不排队；后面扩展优先级，支持各种单独queue、串行queue需求，以及策略）。
     *                      原则：先管理，然后内部消化。默认填0优先级。
     */
    //void APTAsyncCall(APTBizType bizType, const char* tag, double delayTime, NSOperationQueuePriority priority, dispatch_block_t block);
    
    /**
     *  异步到主线程执行block。
     *  APTMainCall和APTMainACall的区别：(业务需要)
     *        APTMainCall  - 如果主线程调用，block是同步调用的，不会异步；等同if([NSThread isMainThread])block();
     *        APTMainACall - 如果主线程调用，block是异步调用的；等同dispatch_async(dispatch_get_main_queue(), block);
     *
     *  @param bizType      调用的业务类型，方便框架统一针对当前所处业务进行线程使用调优。无特殊的和不确定的，统一填0。
     *  @param tag          调用的标识串，方便跟进调用方，跟进性能、线程资源消耗等问题。目前统一填__FUNCTION__。
     *  @param delayTime    延迟执行时间，单位：秒。不延迟填0即可。
     *  @param priority     优先级，方便排队管理。系统定义的5级优先级＋扩展优先级。
     *                      扩展优先级（10000:最高优先执行，不排队；后面扩展优先级，支持各种策略）。
     *                      原则：先管理，然后内部消化。默认填0优先级。
     */
    void APTMainCall(APTBizType bizType, const char* tag, double delayTime, NSOperationQueuePriority priority, dispatch_block_t block);
    void APTMainACall(APTBizType bizType, const char* tag, double delayTime, NSOperationQueuePriority priority, dispatch_block_t block);
    
    void APAsyncCall(NSOperationQueuePriority priority, dispatch_block_t block);
    void APMainCall(dispatch_block_t block);
    
#ifdef __cplusplus
}
#endif // __cplusplus

#pragma mark APThreadPool.h

typedef NS_ENUM (NSInteger, APTaskPriority) {
    APTaskPriorityVeryLow = -8L,
    APTaskPriorityLow = -4L,
    APTaskPriorityNormal = 0,
    APTaskPriorityHigh = 4,
    APTaskPriorityVeryHigh = 8
};

/**
 *  线程池
 */
@interface APThreadPool : NSObject

@property NSInteger maxConcurrentTaskCount;

@property (getter = isSuspended) BOOL suspended;

/**
 *  默认线程池，有10个线程同时处理任务。
 *
 *  @return 默认的线程池对象。
 */
+ (APThreadPool *)defaultThreadPool;

/**
 *  添加任务到当前的线程池。
 *
 *  @param taskId   字符串，用于标识要添加到线程池中的任务。
 *  @param priority 优先级
 *  @param block    block
 */
- (void)addTask:(NSString *)taskId priority:(APTaskPriority)priority block:(void (^)(void))block;

@end
