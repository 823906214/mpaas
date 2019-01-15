//
//  APLiveBroadcaster.h
//  APMultimedia
//
//  Created by Monster on 15/10/22.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <APMUtils/APMNetworkStatusManager.h>
#import "APMLiveConfig.h"

#pragma mark - 状态定义

// 闪光灯以及手电筒模式
typedef enum : NSUInteger {
    APLiveFlashModeOff,                      // 关闭
    APLiveFlashModeOn,                       // 打开
    APLiveFlashModeNotSupported,             // 不支持
} APLiveFlashMode;


typedef NS_ENUM (NSInteger, APLiveCameraState)
{
    APLiveCameraStateFront,
    APLiveCameraStateBack
};

// 摄像头数据采集相关状态
typedef enum : NSUInteger {
    APLiveRunningStarting,                   // 采集准备启动
    APLiveRunningStarted,                    // 采集完成启动
    APLiveRunning,                           // 正在采集
    APLiveNoCameraPermission,                // 无摄像头权限
    APLiveRunningStopped,                    // 采集结束
    APLiveRunningError,                      // 采集错误
} APLiveRunningStatus;

// 视频录制相关状态
typedef enum : NSUInteger {
    APLiveBroadcastStarted,                     // 开始直播
    APLiveBroadcasting,                         // 正在直播
    APLiveBroadcastFinished,                    // 直播结束
    APLiveBroadcastErrFinished,                 // 直播异常结束
    APLiveBroadcastCameraNotStarted,            // 摄像头未启动
    APLiveBroadcastInterupted,                  // 录制被打断
    APLiveBroadcastInteruptEnded,               // 录制被打断已恢复
    APLiveBroadcastRetryStart,                  // 重试开始
    APLiveBroadcastRetryTimeOut,                // 在超时时间内重试失败
    APLiveBroadcastRTMPTimeOut,                 // rtmp connect timeout
    APLiveBroadcastParamError,                  // 参数错误
    APLiveBroadcastRTMPCongestionStart,         // RTMP推流拥塞
    APLiveBroadcastRTMPCongestionResume,        // RTMP推流拥塞恢复
    APLiveBroadcasterErrorHappened,             // 底层遇到错误
    APLiveBroadcastUndefine                     // 未知错误
} APLiveBroadcastStatus;


#pragma mark - handler定义

/**
 *  开始采集Block
 *
 *  @param status  开始采集状态
 *  @param error   异常信息
 */
typedef void (^APLiveRunningHandler)(APLiveRunningStatus status, NSError* error);

/**
 *  开始直播制Block
 *
 *  @param status     直播状态
 *  @param identifier 直播源描述
 *  @param error      异常信息
 */
typedef void (^APLiveStartHandler)(APLiveBroadcastStatus status, NSString* identifier, NSError* error);

/**
 *  结束直播制Block
 *
 *  @param status  结束直播状态
 *  @param identifier 直播源描述
 *  @param error   异常信息
 */
typedef void (^APLiveStopHandler)(APLiveBroadcastStatus status, NSString* identifier, NSError* error);

/**
 *  摄像头操作Block
 *
 *  @param result  成功与否
 */
typedef void (^APLiveCameraOperationHandler)(BOOL result);

/**
 * 直播状态变化block
 * @param status 当前状态
 * @param liveID 直播ID
 * @param error  错误信息
 */
typedef void (^APMLiveStatusChangedHandler)(APLiveBroadcastStatus status,NSString* liveID,NSError* error);


#pragma mark - APLiveBroadcasterDelegate

@protocol APMLiveBroadcasterDelegate <NSObject>
@optional
/**
 * 当前直播时长
 *** 不保证在主线程 **
 */
- (void)APMLiveBroadcast:(NSString*)identifier livedCurrentTime:(NSTimeInterval)time;
/**
 *  网络变化通知
 *
 *  @param fromStatus 变化之前的网络
 *  @param toStatus   变化之后的网络
 */
- (void)APMLiveBroadcastNetStatusChangedFromStatus:(APMNetworkReachabilityStatus)fromStatus toStatus:(APMNetworkReachabilityStatus)toStatus;
//用户单击直播预览view
- (void)APMLiveBroadcastPreviewFocusTap:(CGPoint)point;

//应用压后台
- (void)APMLiveBroadcastOnEnterBackground;

//应用后台返回前台
- (void)APMLiveBroadcastOnEnterForeground;
//直播状态改变，业务层可以在收到这个变化通知时处理譬如埋点等动作
- (void) APMLiveBroadcastStatusChangedTo:(APLiveBroadcastStatus)status liveID:(NSString*)liveID error:(NSError*)error;
@end


#pragma mark - APMLiveBroadcaster
@interface APMLiveBroadcaster : UIView

/**
 *  录制APLiveRunning前加载图片
 */
@property (nonatomic, strong) UIImage* loadingImage;

/**
 *  美颜模式开关，默认为关
 */
@property (nonatomic, assign) BOOL enableBeautyMode;

/**
 *  美颜程度，范围为[0,1],如果超过这个范围时，向边界0或1靠拢
 */
@property (nonatomic, assign) CGFloat beautyLevel;

/**
 *  静音属性，为YES时，表示静音，否则未静音。默认是静音
 */
@property (nonatomic, assign, getter = isMuted) BOOL muted;

/**
 * 闪光灯
 */
@property (nonatomic, assign, readonly) APLiveFlashMode flashMode;

/**
 * 摄像头状态
 */
@property (nonatomic, assign, readonly) APLiveCameraState cameraState;

/**
 *  直播建连超时时间设置, 默认为10s
 *  单位：s
 */
@property (nonatomic, assign) int rtmpTimeOut;
/**
 * rtmp建链耗时
 */
@property (nonatomic, assign, readonly) NSTimeInterval rtmpConnectedCost;
/**
 * 直播开始时间，只在调用startBroadcasting:urlPath:handler:接口时刷新
 */
@property (nonatomic, strong, readonly) NSDate *liveFirstStartedDate;

/**
 *  直播异常中断重试超时时间, 默认为10s
 *  单位：s
 */
@property (nonatomic, assign) int retryTimeOut;

/**
 *  delegate
 */
@property (nonatomic, weak) id<APMLiveBroadcasterDelegate> liveDelegate;


/**
 * 单击手势
 */
@property (nonatomic, strong) UITapGestureRecognizer *tapGesture;

/**
 *  当前已直播时间
 */
@property (nonatomic, readonly,getter = getDurationLived) NSTimeInterval durationLived;


/**
 *  当前网络状态
 */
@property (nonatomic, assign) APMNetworkReachabilityStatus netStatus;

/**
 * 当前直播状态
 */
@property (nonatomic, assign) APLiveBroadcastStatus liveStatus;

/**
 * 是否支持可切换摄像头
 */
@property (nonatomic, assign,readonly) BOOL canSwitchCamera;


//bias 曝光
@property (nonatomic, readonly) float minExposureTargetBias NS_AVAILABLE_IOS(8_0);
@property (nonatomic, readonly) float maxExposureTargetBias NS_AVAILABLE_IOS(8_0);
@property (nonatomic, assign)   float exposureTargetBias NS_AVAILABLE_IOS(8_0);

#pragma mark - init
/**
 * a designated initializer
 * @param frame 
 * @param config 直播相关配置，分辨率 码率 fps  以及一些网络相关的配置
 */
-(instancetype)initWithFrame:(CGRect)frame liveConfig:(APMLiveConfig*)config;
#pragma mark - 摄像头属性设置

/**
 *  切换摄像头
 *
 *  @param  handler     切换完成回调，回调位于主线程
 */
- (void)switchCamera:(APLiveCameraOperationHandler)handler;


/**
 *  设置手电和闪光灯模式
 *  录制过程中设置无效
 *
 *  @param  mode        闪光灯模式
 *  @param  handler     设置完成回调， 回调位于主线程
 */
- (void)setFlashMode:(APLiveFlashMode)flashMode handler:(APLiveCameraOperationHandler)handler;

#pragma mark - 采集与拍摄

/**
 *  开始采集摄像头的数据
 *
 *  @param  handler     异步开始采集回调，回调位于主线程
 */
- (void)startRunning:(APLiveRunningHandler)handler;

/**
 *  结束采集
 *  会在startRunning的回调中返回相应的事件，一定要在对象销毁前调用此方法
 *
 */
- (void)stopRunning;

/**
 *  开始直播
 *  @param  liveId      直播id
 *  @param  urlPath     直播url地址
 *  @param  handler     异步开始录制回调，回调位于主线程
 */
- (void)startBroadcasting:(NSString*)liveId urlPath:(NSString*)urlPath handler:(APLiveStartHandler)handler;

/**
 * 在收到重试超时的状态后，可手动调用重试
 * @param  handler     异步开始录制回调，回调位于主线程
 */
- (void)retryBroadcasting:(APLiveStartHandler)handler;

/**
 *  结束录制
 *  会在startBroadcasting的回调中返回相应的事件，回调位于主线程
 */
- (void)stopBroadcasting:(APLiveStopHandler)handler;

/**
 *  暂停录制
 */
- (void)pauseBroadcasting;
/**
 * 获取对应状态的representation String
 */
-(NSString*)getRepresentationString:(APLiveBroadcastStatus)status;

@end
