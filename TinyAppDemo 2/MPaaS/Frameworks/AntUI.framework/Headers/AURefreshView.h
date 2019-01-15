#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_refreshLoadingView_AURefreshView//程序自动生成
//
//  AURefreshView.h
//  AntUI
//
//  Created by 莜阳 on 2017/11/7.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>



//#ifdef DEBUG
//#import "Lottie.h"
//#endif


typedef NS_ENUM(NSUInteger, AURefreshViewType) {
    AURefreshViewDefault,       // 页面内的刷新样式
    AURefreshViewTypeFeature1  // 用在带有一定背景的titlebar 如首页或者财富tab
};

@protocol AURefreshViewDelegate;

/**
 支付宝下拉刷新动画View
 */

@interface AURefreshView : UIView

// 刚刚下拉到默认位置即(Lottie)View的高度时开始出发当前block
//@property (nonatomic, copy)   void(^beginLoadingBlock)(void);

@property (nonatomic, weak) id <AURefreshViewDelegate> delegate;

/**
 下拉刷新动画Lottie控件
 */
@property (nonatomic, strong) UIView /*LOTAnimationView */ *lottieAnimationView;

/* 指定下拉刷新所在的父view，下拉刷新初始默认高度是scrollView的高度；默认将refreshView添加到父scrollView上
 * 默认初始frame为(0, 0 - scrollView.height, scrollView.width, scrollView.height)) */
- (instancetype)initWithSuperView:(UIScrollView *)scrollView
                             type:(AURefreshViewType)type
                          bizType:(NSString *)bizType;

// 下拉刷新文案
- (void)setupLabelText:(NSString *)text;

// UIScrollView的delegate里面回调以下方法
- (void)auRefreshScrollViewWillBeginDragging:(UIScrollView *)scrollView;
- (void)auRefreshScrollViewDidScroll:(UIScrollView *)scrollView;
- (void)auRefreshScrollViewDidEndDragging:(UIScrollView *)scrollView;

// 结束动画收起列表请调用以下方法
- (void)auRefreshScrollViewDidFinishedLoading:(UIScrollView *)scrollView;

@end

@protocol AURefreshViewDelegate <NSObject>

@optional
// 刚刚下拉到默认位置即(Lottie)View的高度时触发该协议
- (void)auRefreshViewDidTriggerloading:(AURefreshView *)view;
// 在触发了loading状态且动画结束前，用户再次往下拽控件默认不再触发Triggerloading协议，业务也可以自行控制动画的loading状态
- (BOOL)auRefreshViewIsLoading:(AURefreshView*)view;
@end

#endif//程序自动生成
