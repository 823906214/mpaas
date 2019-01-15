//
//  TBDecodeResult.h
//  sdk_gen3_3g
//
//  Created by Tom on 15/6/24.
//  Copyright (c) 2015年 Taobao.com. All rights reserved.
//
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

#import <TBDecodeSDK/tbItf.h>

TBEXTERN_C NSString * const TBDecodeResultTypeGoodsBarcode; // 商品条码
TBEXTERN_C NSString * const TBDecodeResultTypeExpressCode; // 快递单
TBEXTERN_C NSString * const TBDecodeResultTypeITFCode; // ITF条码(水电煤码)
TBEXTERN_C NSString * const TBDecodeResultTypeQRCode; // QR码
TBEXTERN_C NSString * const TBDecodeResultTypeDataMatrixCode; // DM码
TBEXTERN_C NSString * const TBDecodeResultTypeVLGen3Code; // 视觉码三代码
TBEXTERN_C NSString * const TBDecodeResultTypeTB4GCode; // 手淘4G码

TBEXTERN_C NSString * const TBDecodeExtDataTB4GCodeBitstream; // 手淘4G码的bitstream
TBEXTERN_C NSString * const TBDecodeExtDataQRMarkerCoordinates; //QR码的Marker坐标

TBEXTERN_C NSString * const TBDecodeResultTypeAPARCode; // AR码
TBEXTERN_C NSString * const TBDecodeResultTypeAPXCode; // AP码

@interface TBDecodeResult : NSObject

@property (nonatomic, strong, readonly) NSString *resultType; // 码类型
@property (nonatomic, assign, readonly) int subType; // 码子类型
@property (nonatomic, strong, readonly) NSString* data; // 码包含的信息
@property (nonatomic, strong, readonly) NSString* hiddenData; // 隐藏码的隐藏信息
@property (nonatomic, assign, readonly) CGRect bounds; // 码在图中的位置

@property (nonatomic, strong, readonly) NSMutableDictionary *extData; // 存储某些码的额外信息

- (instancetype)initWithType:(int)type subType:(int)subType data:(NSString *)data hiddenData:(NSString *)hiddenData bounds:(CGRect)bounds;

- (void)addExtDataWithKey:(NSString *)key value:(id)value;

@end
