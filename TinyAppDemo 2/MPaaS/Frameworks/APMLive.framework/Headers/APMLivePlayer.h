//
//  APLivePlayer.h
//  APMultimedia
//
//  Created by Monster on 15/10/23.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>
#import <APMUtils/APMNetworkStatusManager.h>

#pragma mark - 状态定义

// 当状态返回MPMovieFinishReasonPlaybackError时，userInfo的key，其值为APLivePlayerErrorStatus
extern NSString* const APLivePlayerErrorStatusKey;

// 直播播放器状态
typedef enum : NSUInteger {
    APLivePlayerIDNotSet,                      // 视频id未设置
    APLivePlayerLiveNotExist,                  // 视频源不存在
    APLivePlayerNetworkIsUnreachable,          // 网络无法连接
    APLivePlayerConnectionTimedout,            // 连接超时
    APLivePlayerCreatedFailed,                 // 创建播放器失败
    APLivePlayerUndefinedError,                // 未知错误
}APLivePlayerErrorStatus;

// 直播播放状态
typedef enum : NSUInteger {
    APLivePlayerLoading,
    APLivePlayerPrepareToPlay,                 // 完成加载可以直播
    APLivePlayerStopped,                       // 停止
    APLivePlayerPlaying,                       // 播放中
    APLivePlayerPaused,                        // 暂停
    APLivePlayerInterrupted,                   // 播放中断
}APLivePlayerState;

//埋点各状态
typedef NS_ENUM(NSUInteger,APMPlayerTraceLogType){
    APMPlayerTraceLogPlayerLoading = 0,
    APMPlayerTraceLogPlayerPreparedToPlay,
    APMPlayerTraceLogPlayerPlaying,
    APMPlayerTraceLogPlayerStopped,
    APMPlayerTraceLogPlayerPaused,
    APMPlayerTraceLogPlayerInterrupted,
    APMPlayerTraceLogPlayerDidFinishToEnd,
    APMPlayerTraceLogPlayerConnectionTimedout,
    APMPlayerTraceLogPlayerFailedWithError,
    APMPlayerTraceLogPlaythroughOK
};
//埋点block定义
typedef void (^APMPlayerTraceLogHandler)(APMPlayerTraceLogType type,NSError *error) ;
#pragma mark - 视频播放器事件代理

@class APMLivePlayer;

/**
 *   视频播放器事件代理
 */
@protocol APMLivePlayerDelegate <NSObject>
@optional

//播放失败
- (void)APMLivePlayer:(APMLivePlayer *)player failedWithError:(NSError *)error;
// 当前播放时长，单位为秒
- (void)APMLivePlayer:(APMLivePlayer *)player playedCurrentTime:(NSTimeInterval)time;
// 整个视频播放完成
- (void)APMLivePlayerDidFinishToEnd:(APMLivePlayer *)player;
// 视频状态变化
- (void)APMLivePlayerStateChangedTo:(APLivePlayerState)newState oldStatus:(APLivePlayerState)oldState;
// 加载状态变化
- (void)APMLivePlayer:(APMLivePlayer *)player loadStateDidChange:(MPMovieLoadState)state;
//网络变化通知
- (void)APMLivePlayerNetStatusChangedFromStatus:(APMNetworkReachabilityStatus)oldStatus toStatus:(APMNetworkReachabilityStatus)newStatus;
@end

#pragma mark - 直播、回看 播放器控件

/**
 *   小视频播放器控件
 */
@interface APMLivePlayer : UIView

#pragma mark - 属性

/**
 *  delegate
 */
@property (nonatomic, weak) id<APMLivePlayerDelegate> playerDelegate;


/**
 *  是否自动播放，默认YES
 */
@property (nonatomic) BOOL shouldAutoplay;

/**
 *  当前已播放时间，单位为秒
 */
@property (nonatomic, readonly,getter=getDurationWatched) NSTimeInterval durationWatched;

/**
 *  总可播时间，单位为秒  直播情况下为-1
 */
@property (nonatomic, readonly,getter=getTotalDuration) NSTimeInterval totalDuration;

/**
 *  当前网络状态
 */
@property (nonatomic, assign,readonly) APMNetworkReachabilityStatus netStatus;

/**
 *  播放连接超时时间，此值在setIdentifier调用之前生效
 */
@property (nonatomic, assign) NSTimeInterval connectTimeOut;
/**
 * 缓冲耗时
 */
@property (nonatomic, assign, readonly) NSTimeInterval bufferingCostTime;
/**
 * 播放器开始播放时间，每次创建新播放器时刷新
 */
@property (nonatomic, strong, readonly) NSDate *playerFirstStartedDate;

/**
 *  获取加载进度
 */
@property (nonatomic, readonly,getter=getBufferingProgress) NSInteger bufferingProgress;
//用于日志等特殊用途的block
@property (nonatomic, strong) APMPlayerTraceLogHandler traceLogHandler;
//直播还是点播，YES表示直播.在setIdentifier之后查询才有效，否则结果不准。
@property (nonatomic, assign,readonly,getter=isLiveStreaming) BOOL liveStreaming;
//美颜等级
@property (nonatomic, assign,readonly) CGFloat beautyLevel;

#pragma mark - 方法

/**
 *  设置Live identifier
 *
 *  @param identifier 直播、点播URL地址
 */
- (void)setIdentifier:(NSString *)identifier;
/**
 *  获取Live identifier
 *
 */
- (NSString*)getIdentifier;

/**
 *  开始播放
 */
- (void)play;

/**
 *  停止播放
 */
- (void)stop;

/**
 *  暂停
 */
- (void)pause;

/**
 *  是否正在播放
 *
 *  @return BOOL
 */
- (BOOL)isPlaying;

/**
 *  seek到某一时间
 *
 *  @param  time        NSTimeInterval，单位为秒
 *
 *  @return seek的时间点字串 例如：02:32
 */
- (NSString*)seekToTime:(NSTimeInterval)time;

/**
 *  seek结束 (用于后开始播放)
 */
- (void)seekEnd;

/**
 *  重试连接播放
 */
- (void)retryToPlay;

/**
 *  是否支持直播播放功能
 *
 *  @return BOOL
 */
+ (BOOL)isLivePlaySupported;

/**
 *  设置加密算法
 *  需要在开始播放之前调用
 *
 *  @param key    加密的key
 *  @param method 加密算法
 */
- (void)setEncryptKey:(NSString *)key method:(NSString *)method;

@end
