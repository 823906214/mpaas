//
// Created by yinhai.tyh on 2017/7/10.
//

#ifndef MA_SDK_CORE_DECODEDEBUG_H_H
#define MA_SDK_CORE_DECODEDEBUG_H_H

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import "TBDecoder.h"


typedef struct _DecodeInfo{
    NSInteger triedLength,possibleLength,guessLength;
    CGPoint triedCorners[200],possibleCorners[200],guessCorners[200];
}_DecodeInfo;


@interface TBDecoder (DecodeDebug)

+ (_DecodeInfo *)getDecodeInfo:(_DecodeInfo*) info;

@end
#endif //MA_SDK_CORE_DECODEDEBUG_H_H

