//
//  UIContext.h
//  APCommonUI
//
//  Created by WenBi on 14-1-23.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class APVisualStyleFactory;

@interface UIContext : NSObject

@property(nonatomic, strong) APVisualStyleFactory *visualStyleFactory;

+ (UIContext *)sharedContext;

@end
