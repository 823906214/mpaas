//
//  IBeeVideoPlayer.h
//  BeeMediaPlayer
//
//  Created by manyi.zsf on 2017/3/29.
//  Copyright © 2017年 Alipay. All rights reserved.
//

typedef NS_ENUM(NSInteger, BeeVideoType) {
    BeeVideoType_ShortVideo,        //小视频
    BeeVideoType_AssetVideo,        //相册视频
};

typedef NS_ENUM(NSInteger, BEEVideoPlayerState) {
    BEEVideoPlayerState_Stop,
    BEEVideoPlayerState_Playing,
    BEEVideoPlayerState_Pause,
    BEEVideoPlayerState_Loading,
};

typedef NS_ENUM(NSInteger, BeeVideoPlayerBtnTag) {
    BeeVideoPlayerBtnTag_CenterPlay = 1 << 0,
    BeeVideoPlayerBtnTag_Play = 1 << 1,
    BeeVideoPlayerBtnTag_Asset = 1 << 2,
    BeeVideoPlayerBtnTag_Retry = 1 << 3,
    BeeVideoPlayerBtnTag_Close = 1 << 4,
    BeeVideoPlayerBtnTag_Muted = 1 << 5,
};

// 视频渲染特效
typedef NS_OPTIONS(NSUInteger, BeeVideoPlayerRenderEffect) {
    BeeVideoPlayerRenderEffectNone        = 0,       // 原始
    BeeVideoPlayerRenderEffectTransparent = 1 << 0,  // 透明视频效果，需要播放透明视频的id
};

typedef NS_ENUM(NSInteger, BeeVideoError) {
    BeeVideoError_Unknown = 1001,      //未知错误
    BeeVideoError_Network = 1002,      //网络错误
};

#pragma mark - protocol BeeVideoPlayer

@protocol BeeVideoPlayerDelegate <NSObject>

- (void)BeeVideoPlayerStarted;
- (void)BeeVideoPlayerFinished;
- (void)BeeVideoPlayerDidReadyToPlay:(NSTimeInterval)totalTime;
- (void)BeeVideoPlayerPlayedTime:(NSTimeInterval)playedTime;
- (void)BeeVideoPlayerCachedTime:(NSTimeInterval)cachedTime;
- (void)BeeVideoPlayerWillChangeState:(BEEVideoPlayerState)newState;
- (void)BeeVideoPlayerFailedWithError:(NSError *)error;

@end

@protocol IBeeVideoPlayer <NSObject>

@required

@property (nonatomic, assign) BeeVideoType videoType;               //default is BeeVideoType_ShortVideo
@property (nonatomic, assign) BOOL isMuted;
@property (nonatomic, assign) BOOL isFillScreen;
@property (nonatomic, strong) UIImage *placeholder;         //在缩略图下载下来之前的占位图像
@property (nonatomic, strong, readonly) UIImageView *thumbnailView; //播放器当前的缩略图view
@property (nonatomic, assign) UIInterfaceOrientation currentInterfaceOrientation;
@property (nonatomic, assign, readonly) BOOL isCached;      //是否已缓存
@property (nonatomic, assign) BeeVideoPlayerRenderEffect renderEffect;

/**
 *  通过进度回调播放当前播放时长的间隔，单位为秒，默认为0.5s
 *  注意：必须在播放前设置才有用
 */
@property (nonatomic, assign) NSTimeInterval durationWatchedInterval;

- (void)setDelegate:(id<BeeVideoPlayerDelegate>)aDelegate;
- (void)play;
- (void)pause;
- (void)stop;
- (void)seekToTime:(NSTimeInterval)time;
- (void)seekEnd;
- (UIView *)displayView;
- (void)setVideoUrl:(NSString *)url withBusiness:(NSString *)business;
- (void)rotateVideo:(BOOL)isRotate withViewBounds:(CGRect)bounds;
//- (CGPoint)getVideoPointWithPoint:(CGPoint)ptView inView:(UIView *)view;

@end

