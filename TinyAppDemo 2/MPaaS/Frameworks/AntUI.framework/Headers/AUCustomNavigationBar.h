#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_TitleBar_AUCustomNavigationBar//程序自动生成
//
//  APCustomNavigationView.h
//  APExtUI
//
//  Created by yangwei on 16/6/1.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUView.h"
#import "AUButton.h"


//#########################################################
//文档地址 : http://aui.alipay.net/develop/ios/aucustomnavigationbar
//#########################################################


#define UI_AUCustomNavigationBar
#define AUCustomNavigationBarHeight (44)

/**
 自定义透明导航栏，主要用于导航栏需要透明的场景
 主要是用原生的导航栏切换会有视觉体验问题，故写此类
 */
@interface AUCustomNavigationBar : UIView

@property(nonatomic, strong) UIView *backgroundView;              // 毛玻璃背景view

@property(nonatomic, strong) NSString *backButtonTitle;           // 返回按钮title（默认无）
@property(nonatomic, strong) UIColor *backButtonTitleColor;       // 返回按钮title颜色
@property(nonatomic, strong) UIImage *backButtonImage;            // 返回按钮图片

@property(nonatomic, strong) NSString *title;                     // 标题
@property(nonatomic, strong) UIColor *titleColor;                 // 标题颜色
@property(nonatomic, strong) UIView *titleView;                   // 自定义titleview

@property(nonatomic, strong) NSString *rightItemTitle;            // 右侧item title
@property(nonatomic, strong) UIColor *rightItemTitleColor;        // 右侧item title颜色
@property(nonatomic, strong) UIImage *rightItemImage;             // 右侧item 图片

/**
 * 右侧item的VoiceOver提示文案,
 * 左侧item默认为“返回”
 * 右侧item默认是rightItemTitle，如果没有设置rightItemTitle，需要手动设置此属性来支持VoiceOver
 */
@property(nonatomic,strong) NSString *rightItemVoiceOverText;

@property(nonatomic,strong) NSString *leftItemVoiceOverText;

/**
 *  创建指定透明的导航栏View。
 *
 *  （1）此导航栏默认在左侧显示返回箭头图片，不显示返回文本。若当前页面需设置与框架逻辑一致的返回文案，请在VC中重写<code> - (UIView *)customNavigationBar </code>方法
 *  （2）如需设置标题、右侧item、毛玻璃背景，请调用相关接口
 *
 *  @param currentVC 当前VC
 *
 *  @return 透明的导航栏View
 */
+ (AUCustomNavigationBar *)navigationBarForCurrentVC:(UIViewController *)currentVC;

/*  调用navigationBarForCurrentVC方法自带默认的返回样式以及点击事件响应，提供以下方式重置返回item的点击事件
 *  @param target 自定义LeftItem的target
 *  @param action 自定义LeftItem的action
 */
- (void)resetNaviBarLeftItemTarget:(id)target action:(SEL)action;

/**
 *  设置毛玻璃背景View，默认透明度为0
 */
- (void)setNavigationBarBlurEffective;

/**
 *  创建导航栏右侧item
 *
 *  @param rightItemTitle    显示的文本
 *  @param target            target
 *  @param action            action
 *
 */
- (void)setNavigationBarRightItemWithTitle:(NSString *)rightItemTitle target:(id)target action:(SEL)action;

/**
 *  创建导航栏右侧item
 *
 *  @param rightItemImage    显示的图片
 *  @param target            target
 *  @param action            action
 *
 */
- (void)setNavigationBarRightItemWithImage:(UIImage *)rightItemImage target:(id)target action:(SEL)action;


/**
 *  创建导航栏左侧item
 *
 *  @param leftItemTitle     显示的文本
 *  @param target            target
 *  @param action            action
 *
 */
- (void)setNavigationBarLeftItemWithTitle:(NSString *)leftItemTitle target:(id)target action:(SEL)action;

/**
 *  创建导航栏左侧item
 *
 *  @param leftItemImage     显示的图片
 *  @param target            target
 *  @param action            action
 *
 */
- (void)setNavigationBarLeftItemWithImage:(UIImage *)leftItemImage target:(id)target action:(SEL)action;

/**
 * 展示title边上的小菊花
 * 注意：标题字数少于5个使用
 */
- (void)startTitleLoading;

/**
 * 消失title边上的小菊花
 * 注意：标题字数少于5个使用
 */
- (void)stopTitleLoading;

/**
 * 修改title边上菊花色值
 * @param trackColor 修改的是
 */
- (void)updateTitleLoadingTrackColor:(UIColor *)trackColor
                       progressColor:(UIColor *)progressColor;

@end



#endif//程序自动生成
