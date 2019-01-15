//
//  APMapCommonMapMarker.h
//  APMap
//
//  Created by 去疾 on 17/3/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <APMap/APMapCommonMapCallout.h>

@interface APMapCommonMapMarker : NSObject

@property (nonatomic,strong) NSString * identifier;
@property (nonatomic,assign) CLLocationDegrees latitude;
@property (nonatomic,assign) CLLocationDegrees longitude;

@property (nonatomic,strong) NSString * title;
@property (nonatomic,strong) NSString * subtitle;

@property (nonatomic,strong) UIImage * icon;

@property (nonatomic,assign) CGFloat rotate;
@property (nonatomic,assign) CGFloat alpha;
@property (nonatomic,assign) CGFloat width;
@property (nonatomic,assign) CGFloat height;

@property (nonatomic,assign) CGFloat anchorX;
@property (nonatomic,assign) CGFloat anchorY;

@property (nonatomic,strong) UIImage * imageForAnnotation;

@property (nonatomic,strong) APMapCommonMapCallout * callout;

-(id)initWithLongitude:(CLLocationDegrees)longitude latitude:(CLLocationDegrees)latitude andIcon:(UIImage*)icon;

-(void)prepareForAnnotation;

@end
