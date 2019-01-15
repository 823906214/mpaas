//
//  ScanSDKDefine.h
//  TBScanSDK
//
//  Created by satyso on 2017/10/17.
//  Copyright © 2017年 Taobao.com. All rights reserved.
//

#ifndef ScanSDKDefine_h
#define ScanSDKDefine_h

#ifdef __OBJC__
#import <Foundation/Foundation.h>
#endif

#import <TBDecodeSDK/tbItf.h>

#if defined(__cplusplus)
#define TBScanSDK_EXPORT extern "C"
#else
#define TBScanSDK_EXPORT extern
#endif

// 扫描到结果后会停止扫描等待接入方处理，如果处理方式是跳出扫码界面则返回时可以继续扫，如果没有跳出扫码界面、处理完成后想要继续扫码，就可以发这个通知
extern NSString* TBScanContinueNotification;
// 扫码摄像头start通知
extern NSString* TBScanCameraDidStartNotification;
// 扫码摄像头stop通知
extern NSString* TBScanCameraDidStopNotification;

typedef enum : NSUInteger {
    TorchState_On = 1,//闪光灯开
    TorchState_Off,//闪光灯关闭
    TorchState_Disable,//没有闪光灯（ipad,ipod）
} TorchState;// 闪光灯状态

typedef enum : NSUInteger {
    ScanType_Null = 0,
    ScanType_GoodsBarcode = EAN13|EAN8|UPCA|UPCE|EAN14,//商品条码
    ScanType_FASTMAIL = CODE39|CODE128,//快递单条码
    ScanType_PrivateBarCode_ITF = ITF,//水电煤条码
    ScanType_Barcode = ScanType_GoodsBarcode|ScanType_FASTMAIL|ScanType_PrivateBarCode_ITF,//商品条码+快递单条码+水电煤条码
    ScanType_QRCode = QRCODE,//二维码
    ScanType_DATAMATRIX = DATAMATRIX,//彩票二维码
    ScanType_4G = HY_4G,//4G码
    ScanType_GEN3 = GEN3,//视觉码-三代码
    ScanType_ARCode = APCODE,//AR个性码
    ScanType_All_Code = ScanType_Barcode|ScanType_QRCode|ScanType_DATAMATRIX|ScanType_4G|ScanType_GEN3 | ScanType_ARCode,//商品条码+快递单条码+水电煤条码+二维码+彩票二维码+4G码 + arcode
    ScanType_Net_Logo = HYSDK_NET_LOGO,//海报识别
    ScanType_CLOTHES = HYSDK_RESERVED1,//扫衣服
    ScanType_OCR = HYSDK_RESERVED2,//OCR
    ScanType_OtherReserved3 = HYSDK_RESERVED3,//预留
    ScanType_OtherReserved4 = HYSDK_RESERVED4,//预留
    ScanType_OtherReserved5 = HYSDK_RESERVED5,//预留
    ScanType_OtherReserved6 = HYSDK_RESERVED6,//预留
    ScanType_OtherReserved7 = HYSDK_RESERVED7,//预留
} ScanType;

#endif /* ScanSDKDefine_h */
