//
//  APMapShareLocationView.h
//  APMap
//
//  Created by liangbao.llb on 4/28/15.
//  Copyright (c) 2015 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import "APMapLocation.h"
@class APShareAnnotation;

// 定义当前用户位置改变回调block
typedef void(^APMapUserLocationUpdateBlock)(APMapLocation *location);

@interface APMapShareLocationView : UIView

@property (nonatomic, copy) APMapUserLocationUpdateBlock userLocationUpdateBlock;
@property (nonatomic, strong) UIImage *currentUserPortrait; // 当前用户的头像

/**
 * 新增一个共享实时位置
 *
 * @param annotation 共享实时位置
 *
 * @return 无
 */
- (void)insertSharedLocation:(APShareAnnotation *)annotation;

/**
 * 指定的共享实时位置显示在前面
 *
 * @param annotation 指定的共享实时位置
 *
 * @return 无
 */
- (void)bringAnnotationToFront:(APShareAnnotation *)annotation;

/**
 * 删除指定的共享实时位置
 *
 * @param annotation 被删除共享实时位置
 *
 * @return 无
 */
- (void)removeSharedLocation:(APShareAnnotation *)annotation;

/**
 * 删除所以共享实时位置
 *
 * @param 无
 *
 * @return 无
 */
- (void)removeAllSharedLocations;

/**
 * 将指定的地理位置显示在地图的中心
 *
 * @param centerCoordinate 指定的地理位置
 * @param animated 是否有动画
 *
 * @return 无
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate animated:(BOOL)animated;

@end
