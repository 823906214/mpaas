//
//  APMapCommonMapView.h
//  APMap
//
//  Created by 去疾 on 17/3/27.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <APMap/APMapCommonMapMarker.h>
#import <APMap/APMapCommonMapPolyline.h>
#import <APMap/APMapCommonMapCircle.h>
#import <APMap/APMapCommonMapControl.h>
#import <APMap/APMapCommonMapPolygon.h>

typedef void(^APMapCommonMapViewBlock)(NSDictionary* data);


/**
 *
 *  支持小程序的通用地图组件
 *
 */

@interface APMapCommonMapView : UIView

@property(nonatomic, assign) CGFloat scale;
@property(nonatomic, assign) CLLocationDegrees latitude;
@property(nonatomic, assign) CLLocationDegrees longitude;
@property(nonatomic, assign) BOOL showLocation;

@property(nonatomic, strong) NSArray<APMapCommonMapMarker*> *markers;
@property(nonatomic, strong) NSArray<APMapCommonMapPolyline*> *polyline;
@property(nonatomic, strong) NSArray<APMapCommonMapCircle*> *circles;
@property(nonatomic, strong) NSArray<APMapCommonMapControl*> *controls;
@property(nonatomic, strong) NSArray<APMapCommonMapPolygon*> *polygon;


@property(nonatomic, strong) NSArray<NSDictionary*> *incluePoints;

@property(nonatomic, copy) APMapCommonMapViewBlock markerTappedBlock;
@property(nonatomic, copy) APMapCommonMapViewBlock controlTappedBlock;
@property(nonatomic, copy) APMapCommonMapViewBlock regionChangedBlock;
@property(nonatomic, copy) APMapCommonMapViewBlock tappedBlock;

@property(nonatomic, copy) APMapCommonMapViewBlock calloutTappedBlock;


-(id)initWithFrame:(CGRect)frame longitude:(CLLocationDegrees)longitude latitude:(CLLocationDegrees)latitude;


-(void)moveToLocation;


-(CLLocationCoordinate2D)getCenterLocation;

/**
 *  为支持fallback异步加载marker的icon，需要得到icon后逐个setIcon，直接修改Icon在mapview上不生效
 *
 *  @param marker annotation
 */
- (void)setMarker:(APMapCommonMapMarker *)marker;

/**
 *  清除所有markers，在每次产生新的markers前调用
 */
- (void)clearMarkers;

@end
