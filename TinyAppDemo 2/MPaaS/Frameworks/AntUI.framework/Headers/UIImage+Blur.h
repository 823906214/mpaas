//
//  UIImage+Blur.h
//  APCommonUI
//
//  Created by liangbao.llb on 7/17/14.
//  Copyright (c) 2014 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Blur)

/**
 *  图片毛玻璃效果
 *  @param  image 原始图片
 *  @param  blur  效果程度：[0.0, 1.0]
 *  @return 返回毛玻璃效果后的图片
 */
+ (UIImage *)blurryImage:(UIImage *)image withBlurLevel:(CGFloat)blur;

/**
 *  图片毛玻璃效果
 *  @param  blur  效果程度：[0.0, 1.0]
 *  @return 返回毛玻璃效果后的图片
 */
- (UIImage *)blurryImageWithBlur:(CGFloat)blur;

@end
