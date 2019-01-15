//
//  ScanSDKPortocol.h
//  TBScanSDK
//
//  Created by satyso on 2017/10/17.
//  Copyright © 2017年 Taobao.com. All rights reserved.
//

#ifndef ScanSDKPortocol_h
#define ScanSDKPortocol_h

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@class TBScanResult;

@protocol TBScanViewControllerDelegate <NSObject>
@required
//识别出来的码值，可能多码。相机识别分线程返回，相册识别主线程返回。
-(void)didFind:(NSArray<TBScanResult*>*)resultArray;
@optional
//摄像头没有访问权限的回调
-(void)cameraPermissionDenied;
//码值识别过滤，返回no为忽略
-(BOOL)canHandleScanResult:(TBScanResult*)result;
//摄像头启动后的回调
-(void)cameraDidStart;
//摄像头启动失败的回调
-(void)cameraStartFail;
//因为收到内存警告，而释放摄像头的回调
-(void)releaseByMemoryWarning;
//闪光灯当前的状态，闪光灯初始化、状态变更都会调用这个方法，可以在这里实现闪光灯的UI
-(void)setTorchState:(TorchState)bState;
///////////////////////////////埋点接口//////////////////////////////
//用接入方自己的埋点接口实现
-(void)userTrack:(NSString*)name;
//用接入方的埋点接口实现,可以上传数据
-(void)userTrack:(NSString*)name args:(NSDictionary*)data;
//Alipay用于关键路径记录，目前主要用于研究主线程切换耗时
-(void)userAlipayLog:(NSString*)name;
///////////////////////////////iPad相关回调/////////////////////////
//iPad识别本地相册图片失败时会调用该方法
-(void)scanPadPhotoFailed;
//popover 消失通知
-(void)dismissPopover;
////////////////////////////////定制
//自定义界面,添加在现有界面之上
-(void)buildContainerView:(UIView*)containerView;
//自定义相册,后续流程外部负责
-(void)buildCustomAlbum;
//自定义相机权限框
-(void)buildCustomCameraPermissionAlert;
@end

#endif /* ScanSDKPortocol_h */
