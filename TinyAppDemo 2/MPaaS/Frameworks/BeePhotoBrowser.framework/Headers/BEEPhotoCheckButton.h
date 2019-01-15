//
//  APPhotoCheckButton.h
//  BeeHive
//
//  Created by Yanzhi on 15/5/6.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

#define kCheckImageViewSize   CGSizeMake(26, 26)

@interface BEEPhotoCheckButton : UIButton
{
    UIImage *_checkedImage;
    UIImage *_uncheckedImage;
    UIImageView *_checkImageView;
    UILabel *_indexLabel;
}

@property (nonatomic, assign) BOOL checked;
@property (nonatomic, assign) NSUInteger index;

- (void)setChecked:(BOOL)checked animated:(BOOL)animated;
- (void)setIndex:(NSUInteger)index animated:(BOOL)animated;
@end
