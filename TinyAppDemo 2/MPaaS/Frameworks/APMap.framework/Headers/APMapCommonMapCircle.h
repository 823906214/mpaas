//
//  APMapCommonMapCircle.h
//  APMap
//
//  Created by 去疾 on 17/3/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MAMapKit/MAMapKit.h>

@interface APMapCommonMapCircle : NSObject<MAOverlay>

@property (nonatomic,assign) CLLocationDegrees latitude;
@property (nonatomic,assign) CLLocationDegrees longitude;
@property (nonatomic,strong) UIColor * color;
@property (nonatomic,strong) UIColor * fillColor;
@property (nonatomic,assign) CGFloat strokeWidth;
@property (nonatomic,assign) CGFloat radius;

-(id)initWithLongitude:(CLLocationDegrees)longitude latitude:(CLLocationDegrees)latitude andRadius:(CGFloat)radius;

@end
