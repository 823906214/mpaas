//
//  BEECamVideo.h
//  BeeHive
//
//  Created by Yanzhi on 15/8/18.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BEECamVideo : NSObject

@property (nonatomic, copy)   NSString  *url;
@property (nonatomic, assign) unsigned long long size;
@property (nonatomic, assign) int64_t   duration;
@property (nonatomic, strong) UIImage   *firstFrameImage;
@property (nonatomic, assign) CGSize    dimensions;

@property (nonatomic, assign) BOOL      isCliped;
@property (nonatomic, assign) int64_t   clipFromTime;
@property (nonatomic, assign) int64_t   clipToTime;
@end
