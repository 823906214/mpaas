//
//  Header.h
//  TBDecodeSDK
//
//  Created by satyso on 2017/7/10.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#ifndef Header_h
#define Header_h

/**
 配置算法的key
 */

//是否需要缩放帧.默认不缩放
static NSString* const kNeedZoomFrame               = @"kNeedZoomFrame";
//扩大长宽比容错
static NSString* const kEnlargeWidthHeightRate      = @"kEnlargeWidthHeightRate";
//长宽比容错阈值
static NSString* const kMaxWidthHeightDifferRate    = @"kMaxWidthHeightDifferRate";
//枚举三点找二维码时，使用对角线检查
static NSString* const kUseXCrossCheckInTriangle    = @"kUseXCrossCheckInTriangle";
//枚举三点找二维码时，使用基于Logistic回归的高级过滤规则
static NSString* const kUseExtCheckFunction         = @"kUseExtCheckFunction";
//在没有找到可以桩点时，扫描粒度，默认3
static NSString* const kCenterModulsSize            = @"kCenterModulsSize";
//使用 151比例的模式识别方案
static NSString* const kEnable151Marker             = @"kEnable151Marker";
//忽略那些极小的11311忽略边界的桩点
static NSString* const kSkipSmall131Marker          = @"kSkipSmall131Marker";


#endif /* Header_h */
