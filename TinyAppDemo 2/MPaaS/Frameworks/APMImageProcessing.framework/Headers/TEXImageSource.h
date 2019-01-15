//
//  TEXImageSource.h
//  TEX
//
//  Created by Cloud on 2017/4/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "TEXSource.h"

@interface TEXImageSource : TEXSource

@property (nonatomic, strong) UIImage *image; // 图像大小必须一致，否则结果未知
@property (nonatomic, assign) CGRect frame; // image在整个图像中的位置，背景部分透明。单位为【点】

- (instancetype)initWithImage:(UIImage *)image;
- (instancetype)initWithImage:(UIImage *)image frame:(CGRect)frame;

@end
