//
//  APTableViewRightTextCell.h
//  APCommonUI
//
//  Created by Gao Jing on 1/21/14.
//  Copyright (c) 2014 Gao Jing. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "APTableViewCell.h"


@interface APTableViewTwoTextCell : APTableViewCell

@property(nonatomic, readonly) UILabel *leftLabel;
@property(nonatomic, readonly) UILabel *rightLabel;
@property(nonatomic, assign) CGFloat imageSize;                 //图片大小，不设置会使用默认值29

/**
 *  初始化cell，cell两侧有显示文本
 *
 *  @param style           UITableViewCellStyle
 *  @param reuseIdentifier cell重用ID
 *  @param leftText        左侧显示文本
 *  @param rightText       右侧显示文本
 *
 *  @return 返回初始化的实例
 */
- (id)initWithStyle:(UITableViewCellStyle)style
    reuseIdentifier:(NSString *)reuseIdentifier
           leftText:(NSString*)leftText
          rightText:(NSString*)rightText;

/**
 *  返回cell的默认高度，默认49，6plus的高度为47
 *
 *  @return cell的高度
 */
+ (float)cellHeight;

@end
