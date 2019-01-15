#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_NetError_AUNetErrorView//程序自动生成
//
//  APExceptionView.h
//  APCommonUI
//
//  Created by Yuanchen on 14-1-20.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import <UIKit/UIKit.h>


//#########################################################
//文档地址 : http://aui.alipay.net/develop/ios/auneterrorview
//#########################################################


#define UI_AUNetErrorView

typedef NS_ENUM(NSInteger, AUNetErrorType) {
    AUNetErrorTypeError,        //网络错误，完全无法连接
    AUNetErrorTypeEmpty,        //内容为空
    AUNetErrorTypeAlert,        //警示

    // 注意：如下类型只在插图版中存在，
    // 初始化时请指定 APExceptionStyle 为APExceptionStyleIlustration

    AUNetErrorTypeLimit,        //限流
    AUNetErrorTypeFailure,      //网络不给力
    AUNetErrorTypeNotFound,     // 404找不到
    AUNetErrorTypeSystemBusy    // 系统繁忙
};


typedef NS_ENUM(NSInteger, AUNetErrorStyle) {
    AUNetErrorStyleMinimalist,    //简单版
    AUNetErrorStyleIlustration,  //插图版
};



/**
 空页面异常视图显示控件

 包括两种提示风格：
    1、简单版风格（默认），包含3种类型样式
    2、插图版风格，包含7种类型样式
 
 两种风格和类型主要是图片不一样。
 */
@interface AUNetErrorView : UIView

@property(nonatomic, strong, readonly) UIButton *actionButton;      // 默认文案是刷新
@property(nonatomic, strong, readonly) UIImageView *iconImageView;  // icon视图
@property(nonatomic, strong, readonly) UILabel *infoLabel;          // 主提示文案Label
@property(nonatomic, strong, readonly) UILabel *detailLabel;        // 详细提示文案Label

@property(nonatomic, strong) NSString *infoTitle;                   // 主文案说明
@property(nonatomic, strong) NSString *detailTitle;                 // 辅助文案说明

/**
 *  初始化异常view并设定异常风格和类型
 *  （target和action为空时，刷新按钮不显示）
 *
 *  @param origin   view的起始位置，必选
 *  @param style    异常的风格，插画版or极简版，必选
 *  @param type     异常类型，必选
 *  @param target   刷新事件处理对象
 *  @param action   刷新事件处理方法
 *
 *  @return APExceptionView
 */

- (id)initWithFrame:(CGRect)frame
              style:(AUNetErrorStyle)style
               type:(AUNetErrorType)type
             target:(id)target
             action:(SEL)action;

/**
 *  初始化异常视图并显示在指定的视图上，布局在 parent 视图中间
 *  （target和action为空时，刷新按钮不显示）
 *
 *  @param parent view的superView，必选，view的位置相对parent居中
 *  @param style  异常的风格，插画版or极简版，必选
 *  @param type   异常类型，必选
 *  @param target 刷新事件处理对象
 *  @param action 刷新事件处理方法
 *
 *  @return APExceptionView
 */
+ (id)showInView:(UIView *)parent
           style:(AUNetErrorStyle)style
            type:(AUNetErrorType)type
          target:(id)target
          action:(SEL)action;

/**
 * 取消异常视图的显示
 */
- (void)dismiss;

@end


#endif//程序自动生成
