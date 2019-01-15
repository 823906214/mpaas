#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_PopMenu_AUPopMenu//程序自动生成
//
//  AUPopItemView.h
//  AntUI
//
//  Created by niki on 2017/6/14.
//  Copyright © 2017年 Alipay. All rights reserved.


#import "AUPopItemBaseView.h"

@interface AUPopItemView : AUPopItemBaseView

@property (nonatomic, strong) AUIconView *iconView; // 支持iconfont图标
//@property (nonatomic, strong) UIView *badgeView     // 红点支持

- (instancetype)initWithModel:(AUPopItemModel *)model position:(CGPoint )position;

@end

#endif//程序自动生成
