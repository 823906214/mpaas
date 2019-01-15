//
//  TBScanViewController.h
//  TBScanSDK
//
//  Created by Tom on 15/7/24.
//  Copyright (c) 2015 Taobao.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreMedia/CMSampleBuffer.h>
#import <TBDecodeSDK/tbItf.h>
#import <TBScanSDK/ScanSDKDefine.h>
#import <TBScanSDK/ScanSDKProtocol.h>

@class TBScanResult;
@class TBScanPlugin;

@interface TBScanViewController : UIViewController <UIAlertViewDelegate>

- (instancetype)init;
- (instancetype)initWithAnimationRect:(CGRect)animationRect delegate:(id<TBScanViewControllerDelegate>)delegate;

//停止扫描并关闭摄像头，一般情况下不要直接调用该方法
-(void)exitScan;
//暂停扫码
-(void)pauseScan;
//继续扫码
-(void)resumeScan;
//暂停扫码,并停止相机(预览停止)
-(void)pauseCaptureSession;
//继续扫码，并恢复相机
-(void)resumeCaptureSession;
//扫描本地图库，会调起本地相册
-(void)scanPhotoLibrary;
//从相册选择的流程
-(void)scanPhotoImage:(UIImage*)image;
//点击闪光灯，之后会调用代理接口setTorchState返回闪光灯状态
-(void)onTorch;
//返回闪光灯的状态
-(TorchState)torchMode;

@property (nonatomic,weak) id<TBScanViewControllerDelegate> delegate;
//动画框大小
@property (nonatomic,assign) CGRect animationRect;
//设置底层解码时的裁剪区域，如果不设置，会根据动画框设置
@property (nonatomic,assign) CGRect rectOfInterest;
//支持本次识别的码类型.默认ScanType_All_Code
@property (nonatomic,assign) ScanType scanType;
//设置屏幕中默认显示摄像头内容的百分比，设值有效范围大约为0.4~1.0，默认为0.74
@property (nonatomic,assign) CGFloat cameraWidthPercent;
//设置识别成功后是否播放声音，YES播放，NO不播放，默认是YES
@property (nonatomic,assign) BOOL bPlaySound;
//是否支持自动根据屏幕内疑似二维码size做放大缩小，默认是YES
@property (nonatomic,assign,setter=setBAutoZoomEnable:) BOOL bAutoZoomEnable;
//是否支持手势缩放,默认YES
@property (nonatomic,assign) BOOL bGestureEnable;
//提示打开闪光灯的阈值,有默认值
@property (nonatomic,assign) CGFloat flashOnBrightnessThreshold;
//提示关闭闪光灯的阈值,有默认值
@property (nonatomic,assign) CGFloat flashOffBrightnessThreshold;

////////////////////////////自定义UIAlertView的文案/////////////////////////////////
// 无摄像头权限时的AlertView的title
@property (nonatomic,strong) NSString *cameraPermissionDeniedTitle;
// 无摄像头权限时的AlertView的提示信息
@property (nonatomic,strong) NSString *cameraPermissionDeniedMsg;
// 无摄像头权限时的AlertView取消按钮的title
@property (nonatomic,strong) NSString *cameraPermissionDeniedCancelTitle;
// 相册识别失败时的AlertView的提示信息
@property (nonatomic,strong) NSString *scanPhotoFailedMsg;
// 相册识别失败时AlertView取消按钮的title
@property (nonatomic,strong) NSString *scanPhotoFailedCancelTitle;
@end

@interface TBScanViewController(pad)
/**
 *
 * @discussion 对iPad相册取图弹出框有定制要求的可以使用这个接口来替换通用的相册取图scanPhotoLibrary接口
 *
 * @param rect 指定相册取图弹出框的区域
 *
 * @param arrowDirections 指定相册取图弹出框的箭头方向
 *
 * @param arrowColor 指定相册取图弹出框的背景色，nil为白色
 *
 */
-(void)scanPhotoLibrary:(CGRect)rect permittedArrowDirections:(UIPopoverArrowDirection)arrowDirections with:(UIColor*)arrowColor;
@end

@interface TBScanViewController(plugin)
//针对预留ScanType可以注册自定义的Plugin
-(void)registerPlugin:(TBScanPlugin*)inPlugin withType:(ScanType)type;
@end

@interface TBScanViewController(CaptureManager)
/**
 *
 * @discussion 判断摄像头是否支持该SessionPreset
 *
 */
-(BOOL)canSetSession:(NSString *)sessionPreset;

// 判断当前是否在使用前置摄像头
-(BOOL)isUsingFrontCamera;
@end
