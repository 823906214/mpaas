#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_TitleBar_AUCustomNavigationBar//程序自动生成
//
//  AUCustomNavigationBar+Extend.h
//  AntUI
//
//  Created by 莜阳 on 2017/10/18.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AUCustomNavigationBar.h"
#import "AULoadingIndicatorView.h"

@interface AUCustomNavigationBar()
{
    __weak id _target;
    SEL _action;
    __weak id _leftItemtarget;
    SEL _leftItemaction;
}
@property(nonatomic, strong) UIImageView *backImageView;              // 返回图片
@property(nonatomic, strong) UILabel     *backTitleLabel;             // 返回文案
@property(nonatomic, strong) UIButton *leftItem;                      // 左侧item
@property(nonatomic, strong) UILabel *titleLabel;;                    // 设置标题
@property(nonatomic, strong) AUButton *rightItem;                     // 右侧item

@property(nonatomic, weak) UIViewController *currentVC;
@property(nonatomic, strong) AULoadingIndicatorView *titleLoading;     // 菊花

- (void)resetLeftItem;

@end

#endif//程序自动生成
