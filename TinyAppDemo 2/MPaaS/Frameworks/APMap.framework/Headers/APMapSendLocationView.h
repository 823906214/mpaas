//
//  APMapSendLocationView.h
//  APMap
//
//  Created by liangbao.llb on 4/27/15.
//  Copyright (c) 2015 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

// 定义搜索结果回调block
typedef void(^APMapSearchCompletedBlock)(NSArray *result, NSInteger pageNo, NSError *error, BOOL finished);

// 定义中心位置改变回调block
typedef void(^APMapLocationChangedBlock)(CLLocationCoordinate2D coordinate, CLLocationAccuracy accuracy);

// 定义逆地理位置回调block
typedef void(^APMapReGeocodeCompletedBlock)(NSString *address, NSError *error);

// 定义超出限定距离的回调block，coordinate为用户选取坐标，distance为该坐标与当前用户位置之间的距离
typedef void(^APMapExceedDistanceBlock)(CLLocationCoordinate2D coordinate, CLLocationDistance distance);

@interface APMapSendLocationView : UIView

@property (nonatomic, strong) UIImage *curUserLocationImage; // 标示当前用户位置图片
@property (nonatomic, copy) APMapLocationChangedBlock locationChangedBlock; // 当前中心位置发生改变回调
@property (nonatomic, assign) CLLocationCoordinate2D customInitCoordinate; // 初始化中心位置

/**
 * 根据关键字搜索相关的地理位置
 *
 * @param keywords   搜索关键字
 * @param pageNo     搜索页号
 * @param pageOffset 页记录数
 * @param completedBlock 搜索结果回调block
 *
 * @return 无
 */
- (void)search:(NSString *)keywords
        pageNo:(NSInteger)pageNo
    pageOffset:(NSInteger)pageOffset
     completed:(APMapSearchCompletedBlock)completedBlock;

/**
 * 逆地理搜索附近POI地理信息
 *
 * @param coordinate 当前位置
 * @param pageNo     搜索页号
 * @param pageOffset 页记录数
 * @param completedBlock 搜索结果回调block
 *
 * @return 无
 */
- (void)reGeocodeSearch:(CLLocationCoordinate2D)coordinate
                 pageNo:(NSInteger)pageNo
             pageOffset:(NSInteger)pageOffset
              completed:(APMapSearchCompletedBlock)completedBlock;

/**
 * 逆地理查询地理信息
 *
 * @param coordinate     位置
 * @param completedBlock 查询结果回调block
 *
 * @return 无
 */
- (void)searchReGeocodeWithCoordinate:(CLLocationCoordinate2D)coordinate
                            completed:(APMapReGeocodeCompletedBlock)completedBlock;

/**
 * 将指定的地理位置显示在地图的中心
 *
 * @param centerCoordinate 指定的地理位置
 * @param animated 是否有动画
 *
 * @return 无
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate animated:(BOOL)animated;

/**
 *  与上面的接口不同在于增加了needCallback字段
 *
 *  @param centerCoordinate <#centerCoordinate description#>
 *  @param needCallback     <#needCallback description#>
 *  @param animated         <#animated description#>
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate
               needCallback:(BOOL)needCallback
                   animated:(BOOL)animated;

/**
 * 获取当前用户所在位置的快照
 *
 * @param 无
 *
 * @return 返回当前用户所在位置的快照
 */
- (UIImage *)getUserLocationSnapshot;

/**
 * 获取当前用户所在位置的快照
 *
 * @param size 大小
 *
 * @return 返回当前用户所在位置的快照
 */
- (UIImage *)getUserLocationSnapshotInSize:(CGSize)size;



/**
 * 设置可选取的位置与当前用户位置的距离限制和超出距离时的回调block
 *
 * @param limitDistance 距离，单位：米
 * @param exceedDistanceBlock 超出距离后的回调，回调block参数coordinate为用户选取坐标, distance为与当前所在位置的距离
 *
 */
-(void)setLimitDistance:(CLLocationDistance)limitDistance exceedCallback:(APMapExceedDistanceBlock)exceedDistanceBlock;


@end

