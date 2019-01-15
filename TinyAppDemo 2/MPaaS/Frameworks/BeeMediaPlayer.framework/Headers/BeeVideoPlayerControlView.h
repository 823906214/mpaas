//
//  BeeVideoPlayerControlView.h
//  BeeMediaPlayer
//
//  Created by manyi.zsf on 2017/4/10.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "IBeeVideoPlayer.h"
#import "BeeVideoPlayerToolBar.h"
#import "BeeVideoProgressView.h"
#import "BeeVideoPlayerTopBar.h"

@protocol BeeVideoPlayerControlViewDelegate <NSObject>

- (BOOL)loadingViewCanShow;
- (void)controlViewBtnClicked:(BeeVideoPlayerBtnTag)tag;

@end

@interface BeeVideoPlayerControlView : UIView

@property (nonatomic, weak) id<BeeVideoPlayerControlViewDelegate> delegate;
@property (nonatomic, strong) BeeVideoPlayerTopBar *topBar;
@property (nonatomic, strong) UIView *bottomBar;
@property (nonatomic, strong) BeeVideoPlayerToolBar *toolBar;
@property (nonatomic, strong) UIButton *centerPlayBtn;
@property (nonatomic, strong) BeeVideoProgressView *progressView;
@property (nonatomic, strong) UIButton *mutedButton;

- (void)showCenterPlay:(BOOL)isShow;
- (void)showErrorWithInfo:(NSString *)info;
- (void)showTopBar:(BOOL)isShow;
- (void)showMutedButton:(BOOL)isShow;
- (void)updateUIWithState:(BEEVideoPlayerState)state;
- (void)resetUI;
- (void)showCustomBtn:(BOOL)isShow byTag:(BeeVideoPlayerBtnTag)tag;

@end
