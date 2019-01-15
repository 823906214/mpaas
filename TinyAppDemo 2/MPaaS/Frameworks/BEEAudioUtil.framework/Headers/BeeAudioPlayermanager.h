//
//  BeeAudioPlayermanager.h
//  BeeViews
//
//  Created by 莜阳 on 17/1/10.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "BeeAudioItemInfo.h"
#import "BeeAudioPlayerDelegate.h"

@class BeeAudioView;

@interface BeeAudioPlayermanager : NSObject <APAudioPlayerDelegate>
{
    BeeAudioItemInfo *_currentAudioItemInfo;
    NSMutableArray *_audioDetailArray;
}

// 当前播放歌曲的状态
@property (nonatomic, assign) BeeAudioPlayerState currentAudioState;
@property (nonatomic, strong) APAudioPlayer *multimediaPlayer;
@property (nonatomic, weak)   id <BeeAudioPlayerDelegate>delegate;

+ (BeeAudioPlayermanager *)shareInstance;

// 获取当前播放歌曲信息
- (BeeAudioItemInfo *)currentPlayingAudioItemInfo;

// 设置当前播放歌曲信息
- (void)setCurrentPlayingAudioItemInfo:(BeeAudioItemInfo *)itemInfo;

/*  播放音频
 *  @param identifier  歌曲标识，URL 或 songId
 *  @param business    业务标识
 */
- (void)playWithIdentifier:(NSString *)identifier business:(NSString *)business;

// 暂停
- (void)pauseAudio;

// 停止
- (void)stopAudio;

//
- (void)seekToTime:(NSTimeInterval)time;

//
- (void)seekFinished;

// 判断是否当前是否有歌曲在播放，YES -- 播放， NO -- 没有歌曲在播放
//- (BOOL)hasAudioPlaying;

//
- (void)addAudioDetailViews:(BeeAudioView *)detailViews;

//
- (void)removeAudioDetailViews:(BeeAudioView *)detailViews;

//
- (NSMutableDictionary *)currentStateInfoWithTime:(NSTimeInterval)playTime;

@end
