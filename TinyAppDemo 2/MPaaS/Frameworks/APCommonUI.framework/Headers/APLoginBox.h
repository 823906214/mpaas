//
//  APLoginBox.h
//  APCommonUI
//
//  Created by yang.zy on 14-1-17.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import <UIKit/UIKit.h>

@class APTextField;
@class APAuthCodeBox;
@class APLinkButton;
@class APInputBox;

@protocol APLoginBoxDelegate;

/**
 * 登录框控件
 */
@interface APLoginBox : UIView

/**
 * 帐号输入框
 */
@property(nonatomic, readonly) UITextField *usernameField;
/**
 * 密码输入框
 */
@property(nonatomic, readonly) UITextField *passwordField;
/**
 * 验证码输入框
 */
@property(nonatomic, readonly) APAuthCodeBox *authCodeBox;
/**
 * 忘记密码"链接"
 */
@property(nonatomic, readonly) APLinkButton *forgotButton;
/**
 * 注册按钮
 */
@property(nonatomic, readonly) UIButton *registerButton;
/**
 * 登录按钮
 */
@property(nonatomic, readonly) UIButton *loginButton;

/**
 * 历史登录账号
 *
 * 数组，每个元素为一个NSString，将显示在历史帐号列表上
 */
@property(nonatomic, copy) NSArray *historyItems;
/**
 * 历史账号列表是否可见
 */
@property(nonatomic, assign) BOOL historyTableVisible;
/**
 * 验证码控件是否可见
 */
@property(nonatomic, assign) BOOL authCodeBoxVisible;
/**
 * 代理
 */
@property(nonatomic, weak) id<APLoginBoxDelegate> delegate;

/**
 *  输入框与密码框
 */
- (APInputBox *)usernameInputBox;
- (APInputBox *)passwordInputBox;

/**
 * 构造函数
 *
 * @param originY 指定frame.origin.y
 * @param flag 是否带注册按钮
 * @return 返回登录组件
 *
 */
+ (APLoginBox *)loginBoxWithOriginY:(CGFloat)originY registerButton:(BOOL)flag;


#pragma mark -
#pragma mark 信用卡账单邮箱登陆定制方法
/**
 *  设置下拉框提示内容,并且直接显示下拉列表
 *
 *  @param  historyItems    下拉框中提示的内容
 *  @return 调整后需要增加的高度
 */
- (NSInteger)setHistoryItemsAndDisplayHistory:(NSArray *)historyItems;

/**
 *  设置文本框变更,修改通知逻辑
 */
- (void)setupDidBeginEditNotification;


@end



@protocol APLoginBoxDelegate <NSObject>

/**
 * 用户选中一个历史登录帐号
 */
- (void)loginBox:(APLoginBox *)loginBox didSelectHistoryItemAtIndex:(NSUInteger)index;
/**
 * 用户删除一个历史登录帐号
 *
 * 界面上删除了一个Cell, historyItems已更新。delegate应该执行真正的历史数据删除操作
 */
- (void)loginBox:(APLoginBox *)loginBox didDeleteHistoryItemAtIndex:(NSUInteger)index;

@optional

/*
 * 展开按钮点中回调
 */
- (void)didExpandButtonClicked:(APLoginBox *)loginBox;

@optional

/**
 * 界面高度发生变化
 *
 * 可能会在以下情况下触发：
 *  1. 展开/收起历史登录帐号
 *  2. 显示/隐藏验证码输入框
 *  3. 用户删除一个历史登录帐号
 */
- (void)loginBoxDidChangeHeight:(APLoginBox *)loginBox;



@end

