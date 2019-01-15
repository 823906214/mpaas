//
//  APPhotoCountLabel.h
//  BeeHive
//
//  Created by Yanzhi on 15/5/6.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

#define kPhotoCountLabelSize CGSizeMake(22, 22)

@interface BEEPhotoCountLabel : UIView
{
    UILabel *_countLabel;
    UIView  *_bgView;
}

@property (nonatomic, assign) NSUInteger countNumber;

- (void)setCountNumber:(NSUInteger)countNumber animated:(BOOL)animated;

@end
