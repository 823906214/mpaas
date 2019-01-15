#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_alert_AUListDialog//程序自动生成
//
//  AUOptionsDialog.h
//  AntUI
//
//  Created by QiXin on 2016/9/20.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "AUDialogBaseView.h"


//#########################################################
//文档地址 : http://aui.alipay.net/develop/ios/aulistdialog
//#########################################################


#define UI_AUListDialog

/**
 选项 Dialog, 支持多个选项按钮垂直排列
 文档：http://idoc.alipay.net/article/57fb0e8f22ec746a420304d3
 */
@interface AUListDialog : AUDialogBaseView

/**
 该实例是否在展示，适用于有指针指向该实例的情况。
 如果有其他 dialog 盖住此 dialog, 属性值也为 YES 不会发生变化。
 */
@property (nonatomic, assign, readonly) BOOL isDisplay;

/**
 * 标题
 */
@property (nonatomic, strong) NSString *title;

/**
 * 文本消息
 */
@property (nonatomic, strong) NSString *message;

/**
 不带按钮标题的初始化方法。
 
 @param title 标题
 @param message 消息内容
 @return AUListDialog 实例
 */
- (instancetype)initWithTitle:(NSString *)title
                      message:(NSString *)message;

/**
 带按钮标题的初始化方法。
 
 @param title 标题
 @param message 消息内容
 @param delegate 协议对象（遵循 AUDialogDelegate）
 @param optionTitle 选项按钮标题列表
 @return AUListDialog 实例
 */
- (instancetype)initWithTitle:(NSString *)title
                      message:(NSString *)message
                     delegate:(id<AUDialogDelegate>)delegate
                  optionTitle:(NSString *)optionTitle, ... NS_REQUIRES_NIL_TERMINATION;

/// 禁用的初始化方法
- (instancetype)init NS_UNAVAILABLE;

/**
 Dialog 展示方法。
 */
- (void)show;

/**
 Dialog 消失方法, 如果监听 will/didDismissWithButtonIndex: 回调 index 值为默认的 0
 */
- (void)dismiss;

/**
 隐藏 Dialog Window 上全部 dialog 视图
 */
+ (void)dismissAll;

/**
 描述文本置为灰色, Default is YES
 */
- (void)setGrayMessage:(BOOL)grayMessage;

/**
 设置文本对齐
 
 @param alignment 对齐参数
 */
- (void)setMessageAlignment:(NSTextAlignment)alignment;

/**
 添加选项按钮以及其回调方法。

 @param title 按钮标题
 @param callback 按钮点击回调
 */
- (void)addOption:(NSString *)title callback:(AUDialogActionBlock)callback;

@end

#endif//程序自动生成
