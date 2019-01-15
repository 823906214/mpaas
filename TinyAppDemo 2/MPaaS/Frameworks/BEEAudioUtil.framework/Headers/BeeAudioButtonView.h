//
//  BeeAudioButtonView.h
//  BEEAudioUtil
//
//  Created by 莜阳 on 17/2/22.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "BeeAudioView.h"

#define BeeAudioName        @"title"
#define BeeAudioDescribe    @"audioDescribe"
#define BeeSingerName       @"desc"
#define BeeAudioLogoURL     @"image"
#define BeeCoverImgUrl      @"coverImgUrl"
#define BeeBusinessName     @"business"                 // business -- 业务标识 (必须)
#define BeeAppName          @"appName"
#define BeeAppIcon          @"appIcon"

@class BeeAudioButtonView;
@protocol BeeAudioButtonViewDelegate <NSObject>

@optional
- (void)downloadLogoImageFinished:(BeeAudioButtonView *)buttonView error:(NSError *)error;

@end

@interface BeeAudioButtonView : BeeAudioView

@property (nonatomic, weak) id <BeeAudioButtonViewDelegate> delegate;
@property (nonatomic, strong) UIImageView *logoImageView; // 音频 logo 图
@property (nonatomic, strong) UIImageView *stateImageView; // 音频状态图，标志 播放/暂停

// songIdentify -- 歌曲id，还需要 business -- 业务标识 (必须)
- (void)setSongIdentify:(NSString *)songIdentify extensionDic:(NSDictionary *)extensionDic;

// 停止音乐播放
+ (void)stopAudioIdentify:(NSString *)songIdentify;

@end
