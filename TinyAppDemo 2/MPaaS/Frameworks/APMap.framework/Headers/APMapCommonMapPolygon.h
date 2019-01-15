//
//  APMapCommonMapPolygon.h
//  APMap
//
//  Created by 去疾 on 17/4/6.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>



@interface APMapCommonMapPolygon : NSObject<MAOverlay>

@property (nonatomic,strong) NSArray<NSDictionary*> * points;
@property (nonatomic,strong) UIColor * color;
@property (nonatomic,assign) CGFloat width;
@property (nonatomic,strong) UIColor * fillColor;
//@property (nonatomic,assign) BOOL dottedLine;

-(id)initWithPoints:(NSArray*)points;

@end
