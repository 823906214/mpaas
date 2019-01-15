#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview_AUCouponsItem//程序自动生成
//
//  AUCouponsItem.h
//  AntUI
//
//  Created by 莜阳 on 17/3/9.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AUBaseListItem.h"
#import "AUListItemModel.h"

typedef NS_ENUM(NSInteger, AUCouponsItemStyle)
{
    AUCouponsItemStyleText,
    AUCouponsItemStyleLittleTitle,
    AUCouponsItemStyleLittleTitleWithfooter,
};

@interface AUCouponsItem : AUBaseListItem

@property (nonatomic, assign) AUCouponsItemStyle style;
@property (nonatomic, strong) UIImageView *leftImageView;
@property (nonatomic, strong) UILabel *subTitleLabel;     // 副标题非必填
@property (nonatomic, strong) UILabel *assistDescLabel;   // 底部说明文案

//
- (void)setDataModel:(void(^)(AUListItemModel<AUCouponsItemDelagate> *model))modelBlock;

//
+ (CGFloat)cellHeightWithStyle:(AUCouponsItemStyle)style;

@end

#endif//程序自动生成
