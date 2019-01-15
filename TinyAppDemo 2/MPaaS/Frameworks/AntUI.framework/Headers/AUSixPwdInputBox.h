#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_textfields_AUSixPwdInputBox//程序自动生成
//
//  AUSixPwdInputBox.h
//  AntUI
//
//  Created by QiXin on 2016/9/29.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>


//#########################################################
//文档地址 : http://aui.alipay.net/develop/ios/ausixpwdinputbox
//#########################################################


#define UI_AUSixPwdInputBox

@class AUSixPwdInputBox, AUTextField;

@protocol AUSixPwdInputBoxDelegate <NSObject>

- (void)onPasswordDidChange:(AUSixPwdInputBox *)sender;

@end

/**
 密码输入框控件
 文档:http://idoc.alipay.net/article/57fb3e1d22ec746a420304e6
 */
@interface AUSixPwdInputBox : UIView <UITextFieldDelegate>

/** 用户输入的密码 */
@property (nonatomic, strong, readonly) NSString *password;
@property (nonatomic, readonly) UILabel *titleLabel;    // 密码输入的提示文字
@property (nonatomic, readonly) AUTextField *textField;
@property (nonatomic, weak) id<AUSixPwdInputBoxDelegate> delegate;

/**
 * 是否是6位数字密码控件。如果是NO，则显示为普通的密码输入框。
 */
@property (nonatomic, assign, getter = isNumericPassword) BOOL numericPassword;

/**
 * 初始化不带默认密码的控件
 *
 * quadWidth:单个方格宽度
 * quadHeight:单个方格高度
 */
- (id)initWithQuadWidth:(CGFloat)quadWidth quadHeight:(CGFloat)quadHeight;

/**
 * 初始化带默认密码的控件
 *
 * quadWidth:单个方格宽度
 * quadHeight:单个方格高度
 * password:初始密码
 */
- (id)initWithQuadWidth:(CGFloat)quadWidth quadHeight:(CGFloat)quadHeight password:(NSString*)password;

/**
 * 清空密码框，不会触发delegate回调
 */
- (void)reset;

/**
 展示键盘
 
 @return 是否展示成功的标识
 */
- (BOOL)showKeyBoard;

/**
 隐藏键盘
 
 @return 是否隐藏成功的标识
 */
- (BOOL)hideKeyBoard;

/**
 设置背景图片
 
 @param image  背景图片
 */
- (void)setBackgroundImage:(UIImage *)image;

@end

#endif//程序自动生成
