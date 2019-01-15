//
//  APMapCommonMapPolyline.h
//  APMap
//
//  Created by 去疾 on 17/3/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MAMapKit/MAMapKit.h>

@interface APMapCommonMapPolyline : NSObject<MAOverlay>

@property (nonatomic,strong) NSArray<NSDictionary*> * points;
@property (nonatomic,strong) UIColor * color;
@property (nonatomic,assign) CGFloat width;
@property (nonatomic,assign) BOOL dottedLine;

-(id)initWithPoints:(NSArray*)points;

@end
