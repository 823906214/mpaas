//
//  BeeAudioItemInfo.h
//  BeeViews
//
//  Created by 莜阳 on 17/1/10.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <APMultimedia/APAudioPlayer.h>

@interface BeeAudioItemInfo : NSObject

@property (nonatomic, strong) NSString *songIdentifier;         // 歌曲标识，songId 或者 URL
@property (nonatomic, strong) NSString *songName;               // 歌曲名称
@property (nonatomic, strong) NSString *singerName;             // 艺人名字
@property (nonatomic, strong) NSString *songDescText;           // 歌曲描述
@property (nonatomic, assign) NSTimeInterval totalDuration;     // 歌曲总时长
@property (nonatomic, assign) NSTimeInterval playingDuration;   // 歌曲当前播放时长
@property (nonatomic, strong) NSString *songlogoURL;            // 歌曲logo来源
@property (nonatomic, strong) NSString *coverImgUrl;            // 歌曲封面 URL
@property (nonatomic, strong) NSString *appName;                // 音频来源程序名称
@property (nonatomic, strong) NSString *appLogo;                // 音频来源程序logo
@property (nonatomic, strong) NSString *appType;                // 音频来源程序类型
@property (nonatomic, strong) NSString *business;               // 音频业务标识
@property (nonatomic, copy) NSDictionary *extraDic;           // 扩展字段

@end


typedef enum : NSUInteger {
    BeeAudioPlayerStateStopped = APAudioPlayerStateStopped,                              // 停止
    BeeAudioPlayerStatePlaying = APAudioPlayerStatePlaying,                             // 播放中
    BeeAudioPlayerStatePaused = APAudioPlayerStatePaused,                              // 暂停
    BeeAudioPlayerStateLoading = APAudioPlayerStateLoading,                           // 数据加载中
    BeeAudioPlayerStateReadyToPlay /*= APAudioPlayerStateReadyToPlay*/ ,                 // 资源可以播放
    BeeAudioPlayerStateError,                                                       // 播放错误
} BeeAudioPlayerState;

