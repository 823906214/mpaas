//
//  TBDecoder.h
//  sdk_gen3_3g
//
//  Created by Tom on 15/6/24.
//  Copyright (c) 2015年 Taobao.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreVideo/CoreVideo.h>

#import <TBDecodeSDK/tbItf.h>
#import <TBDecodeSDK/TBDecodeResult.h>

#define MAX_HOT_NUM 4


@interface TBDecoder : NSObject

/**
 *  解析视频中的码，先将图片根据rect裁剪，然后resample为YES时将剪裁后的图片缩放到360x360再解析，解析时的通用配置参见@TBDecodeConfig
 *
 *  @param buffer   待解析的CVPixelBufferRef
 *  @param rect     解析的图片范围，传入CGRectZero或CGRectNull时解析整张图片
 *  @param resample YES：将裁剪后的图片缩放到360x360，提高识别速度；NO：不做缩放，识别率更高但识别速度下降明显，一般情况下推荐使用YES。
 *  @param type     解析类型，可以是多种解析类型的或值，例如条形码ONED = ( EAN13 | EAN8 | UPCA | UPCE | CODE39 | CODE128 | ITF )
 *  @param codeProportion  疑似二维码的宽度所占比例，用于上层放大zoom.value ＝ 0代表没找到
 *
 *  @return 解析结果，解析失败或者没有解析到数据时返回nil
 */
+ (NSArray<TBDecodeResult*> *)decodeCVPixelBuffer:(CVPixelBufferRef)buffer
                         rectOfInterest:(CGRect)rect
                               resample:(BOOL)resample
                                   type:(int)type
                         codeProportion:(float*)codeProportion;

/**
 传入Y通道图片数据， 原图片高宽，解析途中二维码
 
 @param data Y通道图片数据
 @param imgWidth 原图宽度
 @param imgHeight 原图高度
 @param rect 解析的图片范围，传入CGRectZero或CGRectNull时解析整张图片
 @param resample YES：将裁剪后的图片缩放到360x360，提高识别速度；NO：不做缩放，识别率更高但识别速度下降明显，一般情况下推荐使用YES。
 @param type 解析类型，可以是多种解析类型的或值，例如条形码ONED = ( EAN13 | EAN8 | UPCA | UPCE | CODE39 | CODE128 | ITF )
 @param codeProportion 疑似二维码的宽度所占比例，用于上层放大zoom.value ＝ 0代表没找到
 @return 解析结果，解析失败或者没有解析到数据时返回nil
 */
+ (NSArray<TBDecodeResult*> *)decodeBufferData:(NSData *)data
                                    imageWidth:(CGFloat)imgWidth
                                   imageHeight:(CGFloat)imgHeight
                                rectOfInterest:(CGRect)rect
                                      resample:(BOOL)resample
                                          type:(int)type
                                codeProportion:(float*)codeProportion;
/**
 *  解析照片中的二维码和GEN3码，目前不支持解隐藏码
 *
 *  @param image 待解析的UIImage
 *
 *  @return 解析结果，解析失败或者没有解析到数据时返回nil
 */
+ (TBDecodeResult *)decodeUIImage:(UIImage *)image;

//算法配置。没有则默认算法
+ (void)startCameraWithConfig:(NSDictionary*)config;

@end
