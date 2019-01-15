//
//  DTImageUtils.h
//  MobileFoundation
//
//  Created by 朱建 on 13-4-9.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum
{
	// 图片质量
	LOW     = 0,
	MID     = 1,
	HIG     = 2
} ImageQuality;

/*!
 @class         DTImageUtils
 @abstract      图片数据工具类
 */
@interface DTImageUtils : NSObject

/*!
 @function      isLocalResourceImage
 @abstract      URL是否指向本地资源中的图片
 @param         urlOrigin   图片URL
 @return        URL是否指向本地资源中的图片
 */
//+ (BOOL)isLocalResourceImage:(NSString *)urlOrigin;

/*!
 @function      imageOfLocalResource
 @abstract      获得本地资源中的图片对象
 @param         urlOrigin   图片URL，指向本地资源图片名
 @return        图片对象，失败返回nil
 */
//+ (UIImage *)imageOfLocalResource:(NSString *)urlOrigin;

/*!
 @function      preferImageUrl
 @abstract      判断优选的图片URL
 @discussion    根据屏幕分辨率、网络类型、SD缓存情况，判断选择最适合的质量图片的URL
 @param         urlOrigin   图片URL，含占位符
 @param         width       图片宽度
 @param         height      图片高度
 @return        优选的图片URL
 */
+ (NSString *)preferImageUrl:(NSString *)urlOrigin width:(int)width height:(int)height;

/*!
 @function      preferImageUrl
 @abstract      判断优选的图片URL
 @discussion    根据屏幕分辨率、网络类型、SD缓存情况，判断选择最适合的质量图片的URL
 @param         urlOrigin   图片URL，含占位符
 @param         width       图片宽度
 @param         height      图片高度
 @param         checkHigerQualityCache 是否检查缓存中是否已经有更高分辨率的该图片
 @return        优选的图片URL
 */
+ (NSString *)preferImageUrl:(NSString *)urlOrigin width:(int)width height:(int)height checkHigerQualityCache:(Boolean)checkHigerQualityCache;

/*!
 @function      removeImageFromCacheOfUrl
 @abstract      删除各个质量的缓存图片，包括内存缓存和SD缓存
 @param         urlOrigin   图片URL，含占位符
 @param         width       图片宽度
 @param         height      图片高度
 */
+ (void)removeImageFromCacheOfUrl:(NSString *)urlOrigin width:(int)width height:(int)height;


/**
 *  某些情况即使在2g或3g网络下也需要提供高清图片，故公开此方法
 *  add by 田俊杰
 *  @param urlOrigin 图片URL，含占位符
 *  @param width     宽
 *  @param height    高
 *  @param quality   图片质量
 *
 *  @return 设置后的图片url
 */
+ (NSString *)preferImageUrl:(NSString *)urlOrigin width:(int)width height:(int)height quality:(ImageQuality)quality;

/**
 *  在wifi或3g网络下需要提供高清图片，故公开此方法
 *  add by 田俊杰
 *  @param urlOrigin 图片URL，含占位符
 *  @param width     宽
 *  @param height    高
 *  @param wifiOr3g  wifi或3g网络
 *
 *  @return 设置后的图片url
 */
+ (NSString *)preferImageUrl:(NSString *)urlOrigin width:(int)width height:(int)height wifiOr3g:(BOOL)wifiOr3g;

@end
