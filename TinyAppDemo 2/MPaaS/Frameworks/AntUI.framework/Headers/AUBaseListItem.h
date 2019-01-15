#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_Tableview//程序自动生成
//
//  AUBaseListItem.h
//  AntUI
//
//  Created by sara on 16/9/30.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "AUListItemModel.h"
#import "AUListItemProtocols.h"
#import "TTTAttributedLabel.h"


#define MARGIN_CONTENT_EDGE   AUI_THEME_FLOAT(@"LIST_LEFT_RIGHT_MARGIN") //16//cell内容到左右边界间的留白
#import "AUListLeftAccessorViewProtocol.h"

@interface AUBaseListItem : UITableViewCell <AUListItemLeftAccessorViewProtocol>

@property(nonatomic, strong) UILabel *titleLabel;     // 标题
@property(nonatomic, strong) TTTAttributedLabel *attributelabel;    // 富文本样式，目前主要支持副标题的富文本样式

/**
 返回默认的cell高度
 @return             返回默认的cell高度
 */
+ (CGFloat)cellHeight;

#pragma mark - 左边扩展区域

// 左边的扩展区域，可以通过设置leftAccessorType和leftAccessorView来展示
// 设置了leftAccessorType，可以获取leftAccessorType对应的leftAccessorView
@property (nonatomic, assign) AUListItemLeftAccessorType leftAccessorType;

@property (nonatomic, strong) UIView *leftAccessorView;




#pragma mark - 红点

/**
 红点显示位置
 */
@property (nonatomic, assign) AUListItemBadgeAreaType badgeAreaType;

/**
 设置红点
 
 @param wedgetId 红点的wedgetId
 @param badgeNumber @"."   显示红点
 @"new" 显示new
 @"数字" 显示数字，大于99都显示图片more（...）
 @"惠"/"hui"  显示“惠”字
 @"xin" 显示"新"字
 nil    清除当前显示
 */
- (void)setBadgeView:(NSString *)wedgetId badgeNumber:(NSString *)badgeNumber;


@end

/**
 
 业务方一般调用AUBaseListItem子类的【initWithReuseIdentifier:model:】方法即可满足需求
 
 这里提供单独的 针对title等参数方法
 除title外，都放在子类实现，访问隔断
 
 */
@interface AUBaseListItem (Extensions)

/**
 设置主标题
 
 @param title 主标题字符串
 */
- (void)setTitle:(NSString* )title __deprecated_msg("废弃，业务请勿继续使用");

/**
 主标题get方法
 
 @return 返回主标题字符串
 */
- (NSString*)title ;

/**
 设置展示勾勾（目前实现是系统的accessoryType = UITableViewCellAccessoryCheckmark）
 */
- (void)setShowMark:(BOOL)showMark;

/**
 当前cell是否有展示checkmark
 
 @return 返回当前cell是否有展示checkmark
 
 */
- (BOOL)showMark;

/**
 设置展示箭头（目前实现是系统的accessoryType = UITableViewCellAccessoryDisclosureIndicator）
 
 @param showAccessory 是否设置展示箭头
 */
- (void)setShowAccessory:(BOOL)showAccessory;

/**
 当前cell是否有展示箭头
 
 @return 返回 当前cell是否有展示箭头
 */
- (BOOL)showAccessory;

@end


#endif//程序自动生成
