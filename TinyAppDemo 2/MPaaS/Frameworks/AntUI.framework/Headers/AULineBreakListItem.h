#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview_AULineBreakListItem//程序自动生成
//
//  AULineBreakListItem.h
//  AntUI
//
//  Created by sara on 17/3/10.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AUBaseListItem.h"

@interface AULineBreakListItem : AUBaseListItem

//@property(nonatomic,strong) UILabel *titleLabel;                                                        //标题一

@property(nonatomic,strong) UILabel *subtitleLabel;                                                     //标题二

+ (CGFloat)cellHeightForModel:(AUListItemModel<AULineBreakListItemModelDelegate> *)model;

- (void)setModelBlock:(void(^)(AUListItemModel<AULineBreakListItemModelDelegate>*model))block;


@end

#endif//程序自动生成
