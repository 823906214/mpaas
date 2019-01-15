//
//  APTextFieldCell.h
//  APCommonUI
//
//  Created by WenBi on 14-2-8.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import "APTableViewCell.h"

@class APTextField;
/**
 *  用于cell中的输入框场景
 */
@interface APTextFieldCell : APTableViewCell

@property(nonatomic, strong, readonly) APTextField *textField;//输入框
@property(nonatomic, assign) CGFloat textLabelWidth;//左侧主标题宽度

@end
