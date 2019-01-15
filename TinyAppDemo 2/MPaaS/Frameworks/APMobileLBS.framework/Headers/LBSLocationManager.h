//
//  LBSLocationManager.h
//  APMobileLBS
//
//  Created by 去疾 on 17/1/18.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "LBSAddressInfo.h"

@class LBSLocationRequest;
@class APLBSLocation;

typedef NS_ENUM(NSInteger, APCoreLocationReasonErrorCode) {
    APCoreLocationReasonErrorCodeAuthNotOpen = 0,
};

//当定位失败的时候，具体的原因，比如是权限问题等等，在NSError里面的userInfo字段中
extern NSString * const LBSLocationFailedReasonInErrorKey;


/**获取经纬度的回调
 *error=100 时，定位超时*/
typedef void(^APCoreLocationBlock)(BOOL success, CLLocation *location, NSError *error);

/**逆地理的回调
 *error=100 时，定位超时*/
typedef void(^APCoreLocationWithReversingGeocodeBlock)(BOOL success, CLLocation *location, LBSAddressInfo *addressInfo, NSError *error);

/**设置请求参数的回调*/
typedef void(^APRequestBlock)(LBSLocationRequest *request);


@interface LBSLocationRequest : NSObject

/**期望精度，单位米，建议结合业务场景传入一个可接受正数，如500，即500m以内的范围*/
@property(nonatomic,assign)CLLocationAccuracy desiredAccuracy;

/**业务的类型，如果是native的话传类名，h5的话传url，埋点用，必传*/
@property(nonatomic,strong)NSString *bizType;

/**从当前时间往前推，多长时间内的缓存是有效的，推荐设置30s以上的缓存时间*/
@property(nonatomic,assign)APCoreLocationCacheAvaliable cacheTimeInterval;

/**定位超时的时间，单位秒，默认和最小设置为2s*/
@property(nonatomic,assign)NSTimeInterval timeOut;

/**wifi定位的时候需要用到的appKey，可选*/
@property(nonatomic,strong)NSString *appKey;

/**
 *  如果是调用的有逆地理的接口的话，需要传此type，默认APCoreLocationReGeoTypeReverse; 10.0.3后请换用含义更清晰的reGeoLevel字段
 */
@property(nonatomic,assign)APCoreLocationReGeoType reGeoType;

/**
 *  如果是调用的有逆地理的接口的话，需要传此Level，默认APCoreLocationReGeoLevelDistrict
 */
@property(nonatomic,assign)LBSLocationReGeoLevel reGeoLevel;


/**
 *  需要进行逆地理查询的位置信息，在其中指定经纬度坐标
 */
@property(nonatomic,strong)CLLocation *location;


/**
 *  location 字段有值时，代表是否坐标系已经转到高德坐标系, 默认YES
 */
@property(nonatomic,assign)BOOL coordinateConverted;

/*
 *  H5专用，非H5的不要设置
 */
@property(nonatomic,assign)BOOL isH5;

@end


/**
 *
 *
 *  10.0.2版本之前的历史遗留方法已迁移至LBSLocationManager (Legacy)，新业务不建议再使用
 */

@interface LBSLocationManager : NSObject


/**
 *  定位，通过获取经纬度信息。
 *
 *  @param requestBlock     定制LBSLocationRequest对象，设置参数的block，参数通过设置的property来完成：
 *                              bizType为业务场景标识；
 *                              cacheTimeInterval为可接受之前多长时间之内的缓存数据，单位秒；
 *                              desiredAccuracy为期望精确度，单位米；
 *                              timeOut为发起主动定位后可接受的定位超时时长，单位秒，默认和最小值为2s；
 *  @param locatingBlock    定位结果回调block，回调参数如下：
 *                              success表明定位调用是否成功；
 *                              location为定位结果，经纬度已转换为国内的GCJ02坐标系坐标，可直接在地图上使用；
 *                              error为错误信息；
 *
 *  例子
 *  [LBSLocationManager locationWithRequestBlock:^(LBSLocationRequest *request) {
 *                request.bizType = NSStringFromClass([self class]);
 *                request.cacheTimeInterval = APCoreLocationCacheAvaliableDefault;
 *            } onFinishedLocating:^(BOOL success, CLLocation *location, NSError *error) {
 *
 *            }];
 */
+ (void)locationWithRequestBlock:(APRequestBlock)requestBlock
              onFinishedLocating:(APCoreLocationBlock)locatingBlock;



/**
 *  定位和逆地理，通过获取经纬度信息。
 *
 *  @param requestBlock             定制LBSLocationRequest对象，设置参数的block，参数通过设置的property来完成：
 *                                      bizType为业务场景标识；
 *                                      cacheTimeInterval为可接受之前多长时间之内的缓存数据，单位秒；
 *                                      desiredAccuracy为期望精确度，单位米；
 *                                      timeOut为发起主动定位后可接受的定位超时时长，单位秒，默认和最小值为2s；
 *                                      reGeoLevel为逆地理级别，除非必要否则不要选择带有poi的级别；
 *                                      reGeoType（deprecated since10.0.2,请使用reGeoLevel），默认为APCoreLocationReGeoTypeReverse
 *  @param locatingBlock            定位结果回调block，回调参数如下：
 *                                      success表明定位调用是否成功；
 *                                      location为定位结果，经纬度已转换为国内的GCJ02坐标系坐标，可直接在地图上使用；
 *                                      error为错误信息；
 *  @param reversingGeocodeBlock    定位结果回调block，回调参数如下：
 *                                      success表明逆地理调用是否成功；
 *                                      location为定位结果；
 *                                      addressInfo为逆地理结果；
 *                                      error为错误信息；
 *
 *  例子
 *  [LBSLocationManager locationWithRequestBlock:^(LBSLocationRequest *request) {
 *      request.desiredAccuracy = kCLLocationAccuracyBest;
 *      request.bizType = NSStringFromClass([self class]);
 *      request.cacheTimeInterval = APCoreLocationCacheAvaliableDefault;
 *      request.reGeoType  = APCoreLocationReGeoTypeReverse;
 *      request.reGeoLevel  = APCoreLocationReGeoLevelCity;
 *  } onFinishedLocating:^(BOOL success, CLLocation *location, NSError *error) {
 *
 *  } onFinishedReversingGeocode:^(BOOL success, CLLocation *location, LBSAddressInfo *addressInfo, NSError* error) {
 *
 *  }];
 */
+ (void)locationWithRequestBlock:(APRequestBlock)requestBlock
              onFinishedLocating:(APCoreLocationBlock)locatingBlock
      onFinishedReversingGeocode:(APCoreLocationWithReversingGeocodeBlock)reversingGeocodeBlock;


/**
 *  已知经纬度，直接获取逆地理编码信息。
 *
 *  @param requestBlock             定制LBSLocationRequest对象，设置参数的block，参数通过设置的property来完成：
 *                                      bizType为业务场景标识；
 *                                      location为要做逆地理编码的已知经纬度信息；
 *                                      coordinateConverted标识是否是经过坐标系转换，即是否是国内的GCJ02标准的坐标，默认YES；
 *                                      reGeoLevel为逆地理级别，除非必要否则不要选择带有poi的级别；
 *                                      reGeoType（deprecated since10.0.2,请使用reGeoLevel），默认为APCoreLocationReGeoTypeReverse
 *  @param reversingGeocodeBlock    定位结果回调block，回调参数如下：
 *                                      success表明逆地理调用是否成功；
 *                                      location为定位结果；
 *                                      addressInfo为逆地理结果；
 *                                      error为错误信息；
 *
 */
+ (void)locationWithRequestBlock:(APRequestBlock)requestBlock
      onFinishedReversingGeocode:(APCoreLocationWithReversingGeocodeBlock)reversingGeocodeBlock;


/**
 *
 *  按bizType取消已发起的定位请求，要求bizType与locationWithRequestBlock...方法中的参数一致
 *
 */
+ (void)cancelWithBizType:(NSString *)bizType;



@end



@interface LBSLocationManager (Unrecommended)

/**
 *  为了兼容之前的APLBSLocation，需要提供一个CLLocation到APLBSLocation的方法
 */
+ (APLBSLocation *)converToAPLBSLocationWithCLLocation:(CLLocation *)location;

/**
 *  CLLocation对象转为NSDictionary对象，目前只有扫码业务使用，其它业务不要再调用
 */
+ (NSDictionary *)locationToDict:(CLLocation *)location;

/**
 *
 *  只有客户端启动后，需要马上知道是否之前有定位数据的场景才允许使用此方法
 *  此方法为同步获取上次位置信息的，此数据从磁盘获取
 *  !!!注意：其它场景请不要使用此方法!!!
 */
+ (APLBSLocation *)loadLastLocationData;

@end
