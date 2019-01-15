//
//  UIImage+Scale.h
//  WealthTally
//
//  Created by Yanzhi on 15/2/5.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Scale)

/**
 * @desc 计算图片的字节大小
 *
 * @param image 原始图片
 *
 * @return NSInteger 图片的字节大小
 */
- (NSInteger)bytesSize;

/**
 * @desc 计算图片的宽高比
 *
 * @param image 原始图像
 *
 * @return CGFloat 宽高比例
 */
- (CGFloat)aspectRatio;

/**
 * @desc 将UIImage按照宽高比，压缩成JPEG格式数据
 *
 * @param image 原始图像
 * @param quality 压缩后的图像质量 0.0~1.0
 *
 * @return
 */
- (NSData *)compressToJPEGWithQuality:(CGFloat)quality;

/**
 * @desc 缩放图片到指定尺寸。size宽高比不与图片宽高比一致，图片会被拉伸
 *
 * @param image 原始图像
 * @param size  目标尺寸
 *
 * @return
 */
- (UIImage *)scaleToSize:(CGSize)size;

/**
 * @desc 获取图片缩放后的最佳尺寸，针对“天顶盖”和“金箍棒”型的图片进行特殊处理
 * @param maxWidth NSUInteger 缩放之后的最大边长
 */
- (CGSize)sizeAfterShrinkedWithMaxWidth:(NSUInteger)maxWidth;

/**
 * @desc 截取UIImage指定区域的图像
 * @param rect 指定区域
 * @return
 */
- (UIImage *)cropImageInRect:(CGRect)rect;

@end
