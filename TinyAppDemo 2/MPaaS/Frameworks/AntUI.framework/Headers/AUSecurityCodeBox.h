#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_textfields_AUSecurityCodeBox//程序自动生成
//
//  AUSecurityCodeBox.h
//  AntUI
//
//  Created by QiXin on 2016/9/29.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>


#define UI_AUSecurityCodeBox

@protocol AUSecurityCodeBoxDelegate;
@class AUTextField;

@interface AUSecurityCodeBox : UIView

@property (nonatomic, readonly) UILabel     *titleLabel;        // 验证码标题
@property(nonatomic, assign)    CGFloat      titleLabelWidth;   // 验证码标题宽度
@property (nonatomic, readonly) AUTextField *textField;         // 验证码输入框
@property (nonatomic, readonly) UIButton    *actionButton;      // 右侧执行按钮
@property (nonatomic, assign)   BOOL         waiting;           // 倒计时等待状态
@property (nonatomic, assign)   BOOL         bShowBorder;       // 默认是显示边框
@property (nonatomic, weak) id<AUSecurityCodeBoxDelegate> delegate;

/**
 *  开始倒计时
 *  应用场景1：   对于图片验证码，开始转菊花
 *  应用场景2：   对于短信验证码，按钮变为不可用，开始倒计时
 */
- (void)startCountdown;

/**
 *  停止倒计时
 *  应用场景1：   对于图片验证码，停止转菊花
 *  应用场景2：   对于短信验证码，按钮恢复可用，按钮文字变为”重复校验码“；倒计时结束以后stopCountdown后被自动调用
 */
- (void)stopCountdown;

/**
 *  控件默认高度
 *  @return     返回固定高度：45.0
 */
+ (float)heightOfControl;

@end


@protocol AUSecurityCodeBoxDelegate <NSObject>

@optional
- (void)onAuthTimerout:(AUSecurityCodeBox *)securityCodeBox;

@end

#endif//程序自动生成
