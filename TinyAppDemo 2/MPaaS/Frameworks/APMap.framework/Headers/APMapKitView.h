//
//  APMapKit.h
//  APMap
//
//  Created by ronghui.zrh on 16/8/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@class APMapKitAnnotationView;
@class APMapKitAnnotation;
@class APMapKitView;

@protocol APMapKitViewDelegate <NSObject>

- (void)mapKitView:(APMapKitView *)mapKitView didSelectAnnotationView:(APMapKitAnnotationView *)annotationView;

- (void)mapKitView:(APMapKitView *)mapKitView didDeselectAnnotationView:(APMapKitAnnotationView *)view;

- (void)mapKitView:(APMapKitView *)mapKitView regionWillChangeAnimated:(BOOL)animated;

- (void)mapKitView:(APMapKitView *)mapKitView regionDidChangeAnimated:(BOOL)animated;

- (void)mapKitView:(APMapKitView *)mapKitView didAddAnnotationViews:(NSArray<APMapKitAnnotationView *> *)views;

- (void)mapKitView:(APMapKitView *)mapKitView didUpdateUserLocation:(CLLocation *)userLocation;

- (void)mapKitView:(APMapKitView *)mapKitView didFailToLocateUserWithError:(NSError *)error;

- (APMapKitAnnotationView *)mapKitView:(APMapKitView *)theMapView viewForAnnotation:(APMapKitAnnotation *)annotation;

- (APMapKitAnnotationView *)mapKitView:(APMapKitView *)theMapView userLocationViewForAnnotation:(APMapKitAnnotation *)annotation;

@end

typedef struct {
    CLLocationDegrees latitudeDelta;
    CLLocationDegrees longitudeDelta;
} APMapkitCoordinateSpan;

typedef struct {
    CLLocationCoordinate2D center;
    APMapkitCoordinateSpan span;
} APMapkitCoordinateRegion;

NS_INLINE APMapkitCoordinateSpan APMapKitCoordinateSpanMake(CLLocationDegrees latitudeDelta, CLLocationDegrees longitudeDelta)
{
    APMapkitCoordinateSpan span;
    span.latitudeDelta = latitudeDelta;
    span.longitudeDelta = longitudeDelta;
    return span;
}

NS_INLINE APMapkitCoordinateRegion APMapKitCoordinateRegionMake(CLLocationCoordinate2D centerCoordinate, APMapkitCoordinateSpan span)
{
    APMapkitCoordinateRegion region;
    region.center = centerCoordinate;
    region.span = span;
    return region;
}

typedef NS_ENUM(NSInteger, APMapKitUserTrackingMode) {
    APMapKitUserTrackingModeNone = 0,
    APMapKitUserTrackingModeFollow,
    APMapKitUserTrackingModeFollowWithHeading
};

@interface APMapKitView : UIView

@property(nonatomic,weak)id<APMapKitViewDelegate>delegate;

@property(nonatomic,assign)BOOL showsCompass;
@property(nonatomic,assign)BOOL showsScale;
@property(nonatomic,assign)BOOL zoomEnabled;
@property(nonatomic,assign)BOOL scrollEnabled;
@property(nonatomic,assign)APMapKitUserTrackingMode userTrackingMode;

- (void)selectAnnotation:(APMapKitAnnotation *)annotation animated:(BOOL)animated;
- (void)deselectAnnotation:(APMapKitAnnotation *)annotation animated:(BOOL)animated;
@property (nonatomic, copy) NSArray<APMapKitAnnotation *> *selectedAnnotations;

- (void)setAnnotations:(NSArray <APMapKitAnnotationView *> *) annotations;
- (void)addAnnotation:(APMapKitAnnotation *)annotation;
- (void)addAnnotations:(NSArray<APMapKitAnnotation *> *)annotations;
- (void)removeAnnotation:(APMapKitAnnotation *)annotation;
- (void)removeAnnotations:(NSArray<APMapKitAnnotation *> *)annotations;
- (NSArray <APMapKitAnnotation * > *)getAnnotations;
- (void)showAnnotations:(NSArray <APMapKitAnnotation *> *)annotations animated:(BOOL)animated;
- (APMapKitAnnotationView *)viewForAnnotation:(APMapKitAnnotation *)annotation;
- (APMapKitAnnotationView *)dequeueReusableAnnotationViewWithIdentifier:(NSString *)identifier;
- (CLLocation *)mapKitUserLocation;

- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate animated:(BOOL)animated;

- (CLLocationCoordinate2D)centerCoordinate;

- (APMapkitCoordinateRegion)region;

- (void)setCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate
                  zoomLevel:(double)zoomLevel
                   animated:(BOOL)animated;

- (double)zoomLevel;

@end
