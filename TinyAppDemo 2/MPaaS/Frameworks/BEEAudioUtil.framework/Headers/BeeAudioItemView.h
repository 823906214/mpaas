//
//  BeeAudioItemView.h
//  BEEAudioUtil
//
//  Created by 莜阳 on 17/1/11.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "BeeAudioView.h"

// 音频 view 状态 发生变更后 需要发出的通知 userInfo :@{kBeeAudioViewClass:@"BeeAudioItemView"}
#define kNotificationBeeAudioPlayerStateDidChange    @"kNotificationBeeAudioPlayerStateDidChange"
#define kPluginViewClass                             @"kPluginViewClass"
// 音频状态 key
#define kBeeAudioViewState                           @"BeeAudioViewState"
// 音频状态值
#define kBeeAudioPlayerStateStopped                  @"BeeStop"
#define kBeeAudioPlayerStatePlaying                  @"BeePlaying"
#define kBeeAudioPlayerStatePaused                   @"BeePause"
#define kBeeAudioPlayerStateLoading                  @"BeeLoading"
#define kBeeAudioPlayerStateReadyToPlay              @"BeeReadyToPlay"
#define kBeeAudioPlayerStateError                    @"BeeError"


@interface BeeAudioItemView : BeeAudioView

// 是否需要展示当前view，返回值 YES 则需要展示，NO 则不需要展示 
+ (BOOL)shouldShow;

- (void)updateSongInfo;

@end
