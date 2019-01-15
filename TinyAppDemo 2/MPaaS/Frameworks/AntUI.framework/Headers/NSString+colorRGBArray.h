//
//  NSString+colorRGBArray.h
//  APCommonUI
//
//  Created by 孟嵩 on 15/12/4.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (colorRGBArray)

/**
 *  将Color字符串转化为RGBArray
 *
 *  @return RGBArray，如[150,33,40]
 */
- (NSArray *)colorRGBArray;

/**
 *  该字符串是否可转化为RGBArray
 *
 *  @return 是否可以转换
 */
- (BOOL)isValidColor;

@end
