//
//  BeeVideoPlayerToolBar.h
//  BeeMediaPlayer
//
//  Created by manyi.zsf on 2017/3/29.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IBeeVideoPlayer.h"
#import "BeeVideoSlider.h"

@protocol BeeVideoPlayerToolBarDelegate <NSObject>

- (void)progressValueChanged:(NSTimeInterval)current;
- (void)progressEndChange;
- (void)toolBarBtnClicked:(BeeVideoPlayerBtnTag)tag;

@end

@interface BeeVideoPlayerToolBar : UIView

@property (nonatomic, weak) id<BeeVideoPlayerToolBarDelegate> delegate;

@property (nonatomic, strong) UIImageView *backgroundImageView;
@property (nonatomic, strong) UILabel *currentTimeLabel;
@property (nonatomic, strong) UILabel *totalTimeLabel;
@property (nonatomic, strong) BeeVideoSlider *progressView;
@property (nonatomic, strong) UIButton *playerButton;
@property (nonatomic, strong) UIButton *assetButton;
@property (nonatomic, assign) CGFloat marginRight;

- (void)setTotalTime:(NSTimeInterval)totalTime;
- (void)setPlayedTime:(NSTimeInterval)playedTime;
- (void)setCachedTime:(NSTimeInterval)cachedTime;
- (void)setPlayerState:(BEEVideoPlayerState)state;
- (void)showCustomBtn:(BOOL)isShow withTag:(BeeVideoPlayerBtnTag)tag;

@end
