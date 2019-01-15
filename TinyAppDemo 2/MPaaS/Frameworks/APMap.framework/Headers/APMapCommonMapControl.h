//
//  APMapCommonMapControl.h
//  APMap
//
//  Created by 去疾 on 17/3/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface APMapCommonMapControl : UIButton

@property (nonatomic,strong) NSString * identifier;
@property (nonatomic,strong) UIImage * icon;
@property (nonatomic,assign) BOOL clickable;

-(id)initWithFrame:(CGRect)frame andIcon:(UIImage*)icon;

@end
