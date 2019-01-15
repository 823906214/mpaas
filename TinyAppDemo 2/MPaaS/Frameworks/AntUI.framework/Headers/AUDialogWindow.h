#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_alert//程序自动生成
//
//  AUDialogWindow.h
//  AntUI
//
//  Created by QiXin on 2016/9/27.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol AUDialogWindowViewProtocol

@property (nonatomic, assign) CGFloat    animationDuration;
@property (nonatomic, assign) BOOL    backgroundMark;
@property (nonatomic, weak) id    delegate;


@optional
- (void)forceHidden;
- (UIView *)alertContainer; // autolayout需提供此参数
@property (nonatomic, assign) BOOL    useUnifyShowAnimation;
@property (nonatomic, assign) BOOL    isSupportAutorotate;

@end

@class AUDialogBaseView;
@interface AUDialogWindow : UIWindow

+ (instancetype)window;
+ (BOOL)dialogWindowShowing;

- (void)showDialogView:(id<AUDialogWindowViewProtocol>)dialog;
- (void)dismissDialogView:(id<AUDialogWindowViewProtocol>)dialog completion:(dispatch_block_t)completion;
- (void)dismissAllDialogView;

- (void)hideDialogInBackground;
- (void)showDialogEnterForground;

@end

#endif//程序自动生成
