//
//  APShareAnnotation.h
//  APMap
//
//  Created by liangbao.llb on 4/30/15.
//  Copyright (c) 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

@interface APShareAnnotation : NSObject

@property (nonatomic, assign) CLLocationCoordinate2D coordinate;
@property (nonatomic, assign) BOOL isCurrentUser;
@property (nonatomic, strong) UIImage *portrait;


/**
 * 分享地理位置标识
 *
 * @param coordinate 地理位置
 * @param portrait 头像
 *
 * @return 分享地理位置标识对象
 */
- (id)initWithCoordinate2D:(CLLocationCoordinate2D)coordinate
                  portrait:(UIImage *)portrait;

/**
 * 分享地理位置标识
 *
 * @param longitude 经度
 * @param latitude 维度
 * @param portrait 头像
 *
 * @return 分享地理位置标识对象
 */
- (id)initWithLongitude:(CLLocationDegrees)longitude
               latitude:(CLLocationDegrees)latitude
               portrait:(UIImage *)portrait;

@end
