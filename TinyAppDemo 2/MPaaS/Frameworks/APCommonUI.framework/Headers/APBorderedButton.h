//
//  APBorderedButton.h
//  APCommonUI
//
//  Created by liangbao.llb on 7/3/14.
//  Copyright (c) 2014 Alipay. All rights reserved.
//

typedef NS_ENUM(NSInteger, APBorderedButtonType) {
    APBorderedButtonTypeCustom,
    APBorderedButtonTypeDefault,
    APBorderedButtonTypeSecondary,
};

@interface APBorderedButton : UIButton

/**
 *  一个方法的辅助方法，用于创建并初始化一个按钮的对象
 *
 *  @param buttonType 按钮类型，必须是定义在<code>APBorderedButtonType</code>中的其中一个值
 *  @param title      铵钮标题
 *  @param target     响应按钮点击事件的对象
 *  @param action     响应按钮点击事件的函数
 *
 *  @return 新创建并经过初始化的按钮对象
 *
 *  使用这个方法创建的按钮对象，其默认的frame为<code>CGRectMake(0.0, 0, 标题宽度+20, 26.0)</code>，
 *  对于指定的target和action所对应事件为<code>UIControlEventTouchUpInside</code>
 */
+ (APBorderedButton *)buttonWithType:(APBorderedButtonType)buttonType
                               title:(NSString *)title
                              target:(id)target
                              action:(SEL)action;

/**
 *  用于创建并初始化一个按钮的对象
 * 
 *  @param title      按钮标题
 *  @param buttonType 按钮类型，必须是定义在<code>APBorderedButtonType</code>中的其中一个值
 *
 *  @return 新创建并经过初始化的按钮对象
 */
- (id)initWithButtonTitle:(NSString *)title buttonType:(APBorderedButtonType)buttonType;

@end
