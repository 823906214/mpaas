//
//  UIImage+ChangeColor.h
//  APCommonUI
//
//  Created by 孟嵩 on 15/11/30.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (ChangeColor)
/**
 *  图片变色函数
 *
 *  @param colorString 16进制字符串，支持0x开头（0xffffff），#开头(#ffffff)，以及直接rgb数字(ffffff)
 *
 *  @return 返回变色后的图片
 */
- (UIImage *)changeToHexColorString:(NSString *)colorString;
@end
