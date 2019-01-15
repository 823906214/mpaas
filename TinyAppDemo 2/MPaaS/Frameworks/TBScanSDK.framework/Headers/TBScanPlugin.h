//
//  TBScanPlugin.h
//  TBScanSDK
//
//  Created by Tom on 15/7/27.
//  Copyright (c) 2015年 Taobao.com. All rights reserved.
//

#import "TBScanViewController.h"

TBScanSDK_EXPORT NSString * const TBScanCMSampleBuffer;//传给Plugin处理的视频流CVSampleBuffer
TBScanSDK_EXPORT NSString * const TBScanBarcodeQRScanType;//传给条码二维码Plugin处理的当前scanType

@interface TBScanPlugin : NSObject

@property (nonatomic, weak) TBScanViewController *owner;

-(void)onProcess:(NSDictionary*)inParams;

@end