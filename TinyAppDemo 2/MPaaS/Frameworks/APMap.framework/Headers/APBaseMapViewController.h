//
//  APBaseMapViewController.h
//  APMap
//
//  Created by WenBi on 13-9-25.
//  Copyright (c) 2013年 WenBi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <MAMapKit/MAMapKit.h>
//#import <AMapMpaasSearchKit/AMapMpaasSearchAPI.h>

@interface APBaseMapViewController : DTViewController <MAMapViewDelegate>
//, AMapMpaasSearchDelegate>

@property(nonatomic, strong) MAMapView *mapView;
//@property(nonatomic, strong) AMapMpaasSearchAPI *search;//高德数据搜索
@property(nonatomic, assign) CLLocationCoordinate2D currentCoordinate;
@property(nonatomic, strong) CLLocation *currentLocation;
@property(nonatomic, strong) NSDictionary *launchOptions;
@property(nonatomic, strong) UIButton *baseLocalBtn;

//搜过orgin到destination的path
//- (void)searchPathFromCoordinate:(CLLocationCoordinate2D)origin toCoordinate:(CLLocationCoordinate2D)destination;
//
////根据coordinate搜索逆地理信息
//- (void)searchReGeocodeWithCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 *  初始化地图
 */
- (void)initMapView;



//埋点统计使用
//行为ID
-(NSString*)actionID;


//appID
-(NSString*)appID;

//埋点id
-(NSString*)seed;

//用例编号
-(NSString*)ucID;
@end
