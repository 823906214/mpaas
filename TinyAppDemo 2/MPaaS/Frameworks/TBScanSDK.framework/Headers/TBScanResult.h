//
//  TBScanResult.h
//  TBScanSDK
//
//  Created by Tom on 15/7/29.
//  Copyright (c) 2015年 Taobao.com. All rights reserved.
//
#import <CoreGraphics/CoreGraphics.h>

@class TBDecodeResult;

TBScanSDK_EXPORT NSString * const TBScanResultTypeGoodsBarcode; // 商品条码
TBScanSDK_EXPORT NSString * const TBScanResultTypeExpressCode; // 快递单
TBScanSDK_EXPORT NSString * const TBScanResultTypeITFCode; // ITF条码(水电煤码)
TBScanSDK_EXPORT NSString * const TBScanResultTypeQRCode; // QR码
TBScanSDK_EXPORT NSString * const TBScanResultTypeDataMatrixCode; // DM码
TBScanSDK_EXPORT NSString * const TBScanResultTypeVLGen3Code; // 视觉码三代码
TBScanSDK_EXPORT NSString * const TBScanResultTypeTB4GCode; // 手淘4G码
TBScanSDK_EXPORT NSString * const TBScanResultTypeARCode; // AR码
TBScanSDK_EXPORT NSString * const TBScanResultTypeAPXCode; // AP码

typedef enum : NSUInteger {
    APPROACH_CAMERA = 0,//通过摄像头取帧识别
    APPROACH_LOCALPHOTO = 1,//通过扫描本地图库识别
} TBScanApproachOfAchieving;

@interface TBScanResult : NSObject
@property (nonatomic, strong) NSString *resultType; // 码类型
@property (nonatomic, assign) int subType; // 码子类型，一般情况下忽略
@property (nonatomic, strong) NSString* data; // 码包含的信息
@property (nonatomic, assign) TBScanApproachOfAchieving approach; // 识别的途径

@property (nonatomic, strong) NSString* hiddenData; // 隐藏码的隐藏信息
@property (nonatomic, assign) CGRect    rect;//码在预览帧里的位置
@property (nonatomic, strong) NSMutableDictionary *extData; // 额外信息

- (instancetype)initWithTBDecodeResult:(TBDecodeResult *)decodeResult;

@end
