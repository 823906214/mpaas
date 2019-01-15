//
//  APExceptionView.h
//  APCommonUI
//
//  Created by Yuanchen on 14-1-20.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    APExceptionEnumNetworkError,   //网络错误，完全无法连接
    APExceptionEnumEmpty,          //内容为空
    APExceptionEnumAlert,          //警示
    APExceptionEnumLimit,          //限流，注意：此类型只在插图版中存在，初始化时请指定 APExceptionStyle 为APExceptionStyleIlustration
    APExceptionEnumNetworkFailure  //网络不给力
} APExceptionEnum;

typedef enum {
    APExceptionStyleIlustration,  //插图版
    APExceptionStyleMinimalist    //简单版
} APExceptionStyle;

@interface APExceptionView : UIView

/**
 *  行为按钮，通过设置他来修改按钮的样式
 *  注意：用initWithFrame方法初始化异常控件后，行为按钮默认不显示，需调get方法才会显示
 */
@property(nonatomic, strong) UIButton *actionButton;

/**
 *  主文案说明
 */
@property(nonatomic, strong) NSString *infoTitle;

/**
 *  辅助文案说明
 */
@property(nonatomic, strong) NSString *detailTitle;

/**
 *  初始化异常view并设定异常风格和类型
 *
 *  @param frame view的坐标，必选
 *  @param style 异常的风格，插画版or极简版，必选
 *  @param type  异常类型，必选
 *
 *  @return APExceptionView
 */
- (id)initWithFrame:(CGRect)frame style:(APExceptionStyle)style exceptionType:(APExceptionEnum)type;

/**
 *  初始化异常视图并显示在指定的视图上
 *
 *  @param parent view的superView，必选
 *  @param style  异常的风格，插画版or极简版，必选
 *  @param type   异常类型，必选
 *  @param target 事件处理对象
 *  @param action 事件处理方法
 *
 *  @return APExceptionView
 */
- (id)initWithParentView:(UIView *)parent style:(APExceptionStyle)style exceptionType:(APExceptionEnum)type target:(id)target action:(SEL)action;

/**
 *  初始化异常view并设定异常类型
 *
 *  @param frame view的坐标，必选
 *  @param type  异常类型，必选
 *
 *  @return APExceptionView
 */
- (id)initWithFrame:(CGRect)frame exceptionType:(APExceptionEnum)type;

/**
 *  初始化异常视图并显示在指定的视图上
 *
 *  @param parent view的superView，必选
 *  @param type   异常类型，必选
 *  @param target 事件处理对象
 *  @param action 事件处理方法
 *
 *  @return APExceptionView
 */
- (id)initWithParentView:(UIView *)parent exceptionType:(APExceptionEnum)type target:(id)target action:(SEL)action;

/**
 * 取消异常视图的显示
 */
- (void)dismiss;

/**
 *  获取大图标的只读UIImageView
 *
 *  @return UIImageView
 */
- (UIImageView *)getIconImageView;

/**
 *  获取说明文案的只读UILabel。自定义主文案，请设置infoTitle属性
 *
 *  @return UILabel
 */
- (UILabel *)getInfoLabel;

/**
 *  获取辅助文案的只读UILabel。默认为nil，若需自定义辅助文案，请设置detailTitle属性
 *
 *  @return UILabel
 */
- (UILabel *)getDetailLabel;

/**
 *  获取行动按钮，建议使用actionButton属性
 *
 *  @return UIButton
 */
- (UIButton *)getActionButton;

/**
 *  倒计时 仅限限流使用
 *  如果 completeBlock == nil 且 业务没有设置actionButton的点击响应事件 则倒计时功能不生效；
 *  如果 completeBlock != nil, 倒计时结束直接执行 completeBlock，同时隐藏 actionButton
 *  如果使用 getActionButton 来添加button的响应事件，要确保在该方法之前添加 actionButton 的响应事件
 */
- (void)setCountdownTimeInterval:(NSInteger)startTime  // 倒计时起始时间
                   completeBlock:(void (^)(void))completeBlock; // 倒计时结束后

@end
