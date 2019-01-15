#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview_AUParallelTitleListItem//程序自动生成
//
//  AUParallelTitleListItem.h
//  AntUI
//
//  Created by sara on 17/3/7.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AUBaseListItem.h"

@interface AUParallelTitleListItem : AUBaseListItem

//@property(nonatomic,strong) UILabel *titleLabel;                                                        //标题一
@property(nonatomic,strong) UILabel *subtitleLabel;                                                     //标题二
@property(nonatomic,strong) UILabel *desLabel;                                                          //描述一
@property(nonatomic,strong) UILabel *subDesLabel;                                                       //描述二

- (void)setModelBlock:(void(^)(AUListItemModel<AUParallelTitleListItemModelDelegate>*model))block;

@end

#endif//程序自动生成
