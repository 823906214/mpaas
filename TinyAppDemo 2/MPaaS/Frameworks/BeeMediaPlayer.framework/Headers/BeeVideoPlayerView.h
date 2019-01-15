//
//  BeeVideoPlayerView.h
//  BeeMediaPlayer
//
//  Created by manyi.zsf on 2017/3/29.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IBeeVideoPlayer.h"
#import "BeeVideoPlayerControlView.h"

typedef NS_ENUM(NSInteger, BeeVideoBarShowMode) {
    BeeVideoBarShowMode_InitShow,       //初始显示，自动隐藏，点击后可显示/隐藏
    BeeVideoBarShowMode_AlwaysHide,     //一直隐藏
    BeeVideoBarShowMode_InitHide,       //初始隐藏，点击后可显示/隐藏
    BeeVideoBarShowMode_AlwaysShow,     //一直显示，不会隐藏
};

typedef NS_ENUM(NSInteger, BeeVideoPlayerControlMode) {
    BeeVideoPlayerControlMode_None,
    BeeVideoPlayerControlMode_CenterPlay,       //居中play按钮模式
    BeeVideoPlayerControlMode_ToolBar,          //工具条模式
};

typedef NS_ENUM(NSInteger, BeeVideoPlayMode) {
    BeeVideoPlayMode_PlayWhenDownloading,       //边下边播，default
    BeeVideoPlayMode_PlayAfterDownloaded,       //下载完再播放
};

@class BeeVideoPlayerView;
@protocol BeeVideoPlayerViewDelegate <NSObject>

@optional
/**
 AutoPlay的时候，播放前给业务方一个干涉的机会

 @param videoPlayer
 @return YES - 正常开始播放；NO - 不播放
 */
- (BOOL)BeeVideoCanAutoPlay:(BeeVideoPlayerView *)videoPlayer;

/**
 playMode == BeeVideoPlayMode_PlayAfterDownloaded时，下载前给业务方一个干涉的机会

 @param videoPlayer
 @return YES - 开始下载；NO - 不下载
 */
- (BOOL)BeeVideoCanDownload:(BeeVideoPlayerView *)videoPlayer;

/**
 播放开始
 */
- (void)BeeVideoPlayerViewDidStartPlay:(BeeVideoPlayerView *)videoPlayer;

/**
 播放结束
 */
- (void)BeeVideoPlayerViewDidFinishPlay:(BeeVideoPlayerView *)videoPlayer;

/**
 播放进度的回调

 @param videoPlayer
 @param playedTime 当前已播放时间
 */
- (void)BeeVideoPlayerView:(BeeVideoPlayerView *)videoPlayer playedTime:(NSTimeInterval)playedTime;

/**
 缓存进度的回调

 @param videoPlayer
 @param cachedTime 当前已缓存的时间
 */
- (void)BeeVideoPlayerView:(BeeVideoPlayerView *)videoPlayer cachedTime:(NSTimeInterval)cachedTime;

/**
 播放状态变化的回调

 @param videoPlayer
 @param newState @see BEEVideoPlayerState
 */
- (void)BeeVideoPlayerView:(BeeVideoPlayerView *)videoPlayer willChangeState:(BEEVideoPlayerState)newState;

/**
 发生错误时的回调

 @param videoPlayer
 @param error error信息
 @return YES - 业务层已处理，组件不再处理错误信息；NO - 按组件默认方式处理错误信息
 */
- (BOOL)BeeVideoPlayerView:(BeeVideoPlayerView *)videoPlayer failedWithError:(NSError *)error;

/**
 按钮点击回调

 @param videoPlayer
 @param tag 按钮标签 @see BeeVideoPlayerToolBarBtnTag
 */
- (void)BeeVideoPlayerView:(BeeVideoPlayerView *)videoPlayer ClickedBtn:(BeeVideoPlayerBtnTag)tag;

@end

@interface BeeVideoPlayerView : UIView

//视频控制UI，可以添加自定义的view到这个view上
@property (nonatomic, strong) BeeVideoPlayerControlView *controlView;
//回调代理，@see BeeVideoPlayerViewDelegate
@property (nonatomic, weak) id<BeeVideoPlayerViewDelegate> delegate;

//当前播放状态
@property (nonatomic, assign, readonly) BEEVideoPlayerState state;
//视频对应的url
@property (nonatomic, copy, readonly) NSString *videoUrl;
//播放器当前的缩略图view
@property (nonatomic, strong, readonly) UIImageView *thumbnailView;

//@see BeeVideoPlayMode, 需要在setVideoUrl:withBusiness:方法前设置
@property (nonatomic, assign) BeeVideoPlayMode playMode;
//@see BeeVideoPlayerControlMode, default is BeeVideoPlayerControlMode_None
@property (nonatomic, assign) BeeVideoPlayerControlMode ctrlMode;
//@see BeeVideoBarShowMode default is BeeVideoBarShowMode_InitShow
@property (nonatomic, assign) BeeVideoBarShowMode topBarShowMode;
//@see BeeVideoBarShowMode default is BeeVideoBarShowMode_InitShow
@property (nonatomic, assign) BeeVideoBarShowMode toolBarShowMode;
//bottomBar包含了toolbar、静音按钮等
@property (nonatomic, assign) BeeVideoBarShowMode bottomBarShowMode;
//自动播放，default is YES
@property (nonatomic, assign) BOOL isAutoPlay;
//循环播放，default is YES
@property (nonatomic, assign) BOOL isAutoReplay;
//静音模式，default is YES
@property (nonatomic, assign) BOOL isMuted;
//视频填充模式，default is YES, 填满全屏
@property (nonatomic, assign) BOOL isFillScreen;
//@see BeeVideoType, default is BeeVideoType_ShortVideo
@property (nonatomic, assign) BeeVideoType videoType;
//在缩略图下载下来之前的占位图像
@property (nonatomic, strong) UIImage *placeholder;
//当前的屏幕旋转方向
@property (nonatomic, assign) UIInterfaceOrientation currentInterfaceOrientation;
//视频总时长
@property (nonatomic, assign) NSTimeInterval duration;
//视频渲染特效
@property (nonatomic, assign) BeeVideoPlayerRenderEffect renderEffect;
//重复播放时间区间
@property (nonatomic, assign) NSTimeInterval replayStartTime;
@property (nonatomic, assign) NSTimeInterval replayEndTime;
//页面不动，旋转视频
@property (nonatomic, assign) BOOL rotateVideo;

//播放
- (void)play;
//暂停
- (void)pause;
//停止
- (void)stop;
//是否正在播放
- (BOOL)isPlaying;

/**
 设置视频源

 @param url
 @param business
 */
- (void)setVideoUrl:(NSString *)url withBusiness:(NSString *)business;

/**
 显示/隐藏指定tag的button

 @param isShow
 @param tag @see BeeVideoPlayerBtnTag
 */
- (void)showBtn:(BOOL)isShow byTag:(BeeVideoPlayerBtnTag)tag;

@end
