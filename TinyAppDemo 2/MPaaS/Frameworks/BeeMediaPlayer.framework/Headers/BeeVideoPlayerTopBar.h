//
//  BeeVideoPlayerTopBar.h
//  BeeMediaPlayer
//
//  Created by manyi.zsf on 2017/6/5.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BeeVideoPlayerTopBar : UIView

@property (nonatomic, strong) UIImageView *backgroundImageView;
@property (nonatomic, strong) UIButton *closeBtn;
@property (nonatomic, strong) UILabel *tipLabel;

- (void)showTopTip:(NSString *)tipString withDuration:(NSTimeInterval)duration;
- (void)hiddenTopTip;

@end
