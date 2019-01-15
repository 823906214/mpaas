//
//  TEXSource.h
//  TEX
//
//  Created by Cloud on 2017/4/27.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "TEXOutput.h"
#import "TEXFramebuffer.h"

@interface TEXSource : TEXOutput

@property (nonatomic, assign) CGSize outputSizeInPixels; // 单位为像素，如果未设置则与输入一样大

- (void)start;
- (void)stop;

@end
