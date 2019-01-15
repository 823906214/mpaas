#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_keyboards_AUNumKeyboards//程序自动生成
//
//  AUNumKeyboards.h
//  AntUI
//
//  Created by QiXin on 2016/9/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>


//#########################################################
//文档地址 : http://aui.alipay.net/develop/ios/aunumkeyboards
//#########################################################


#define UI_AUNumKeyboards

typedef NS_ENUM(NSInteger, AUNumKeyboardMode) {
    AUNumKeyboardModeCommon,  //通用键盘
    AUNumKeyboardModeChat,    //聊天键盘
    AUNumKeyboardModePhone,      //电话号码键盘
    AUNumKeyboardModeInvalid,  //无效键盘，目前不可用
    
    APNumericKeyboardModeCommon  __attribute__((deprecated))    = AUNumKeyboardModeCommon,  //通用键盘
    APNumericKeyboardModeChat    __attribute__((deprecated))    = AUNumKeyboardModeChat,    //聊天键盘
    APNumericKeyboardModeInvalid __attribute__((deprecated))    = AUNumKeyboardModeInvalid //无效键盘，目前不可用
};


/**
 支付宝自定义数字键盘
 文档:http://idoc.alipay.net/article/57fb366e22ec746a420304dd
 */
@interface AUNumKeyboards : UIView

/**
 *  创建键盘组件，默认为通用键盘
 *
 *  @return 初始化的键盘组件
 */
+ (AUNumKeyboards *)sharedKeyboard;

/**
 *  创建键盘组件
 *
 *  @param mode 键盘模式
 *
 *  @return 初始化的键盘组件
 */
+ (AUNumKeyboards *)sharedKeyboardWithMode:(AUNumKeyboardMode)mode;

/**
 *  手动设置textinput，外部需要设置keyboard的y轴
 */
@property (nonatomic, weak) id<UITextInput> textInput;

/**
 *  身份证x
 */
@property (nonatomic, assign) BOOL idNumber;

/**
 *  设置键盘模式
 */
@property (nonatomic, assign, readonly) AUNumKeyboardMode mode;

/**
 *  小数点，是否隐藏
 */
@property (nonatomic, assign) BOOL dotHidden;

/**
 *  是否收起键盘
 */
@property (nonatomic, assign) BOOL dismissHidden;

/**
 *  提交按钮是否可点
 */
@property (nonatomic, assign) BOOL submitEnable;

/**
 *  提交按钮文案
 *  注意：根据视觉要求，此文案最多显示三个汉字，国际化时请注意英文文案长度
 */
@property (nonatomic, strong) NSString *submitText;


@end

#endif//程序自动生成
