#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_textfields_AUTextCodeInputBox//程序自动生成
//
//  AUTextCodeInputBox.h
//  AntUI
//
//  Created by QiXin on 2016/9/29.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "AUSecurityCodeBox.h"


//#########################################################
//文档地址 : http://aui.alipay.net/develop/ios/autextcodeinputbox
//#########################################################


#define UI_AUTextCodeInputBox

/**
 短信验证码输入框，带倒计时按钮
 文档：http://idoc.alipay.net/article/57fb3fa522ec746a420304e9
 */
@interface AUTextCodeInputBox : AUSecurityCodeBox

/**
 发送短信前的等待时间
 */
@property (nonatomic, assign) NSTimeInterval interval;

/**
 *  创建短信验证码输入框
 *  @param frame    在父类的位置和大小
 *  @param interval 发送短信前的等待时间
 *  @return         短信验证码输入框
 */
- (AUTextCodeInputBox *)initWithFrame:(CGRect)frame
                             interval:(NSTimeInterval)interval;

/**
 *  创建短信验证码输入框
 *  @param originY  组件的y坐标
 *  @param interval 发送短信前的等待时间
 *  @return         短信验证码输入框
 */
- (AUTextCodeInputBox *)initWithOriginY:(CGFloat)originY
                               interval:(NSTimeInterval)interval;

/**
 *  设置倒计时结束时执行的block
 *  @param block  执行的block
 */
- (void)setCountdownDidCompleteBlock:(void (^)(void))block;

@end

#endif//程序自动生成
