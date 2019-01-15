//
//  TEXRecordConfig.h
//  TEX
//
//  Created by Cloud on 2017/3/13.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface TEXRecordConfig : NSObject

@property (nonatomic, assign) CGSize size; /// 默认为720x1280
@property (nonatomic, assign) int bitrate; /// 默认为2.5 * 1000 * 1000bps
@property (nonatomic, assign) int fps;     /// 默认为30fps

/**
 *  共享对象
 *
 *  @return 共享的对象
 */
+ (instancetype)sharedInstance;

/**
 *  使用sharedInstance，别用init
 *
 *  @return 对象
 */
- (instancetype)init __attribute__((unavailable("init not available")));

@end
