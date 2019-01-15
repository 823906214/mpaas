#TBScanSDK Release Notes

##1.1.0.X

* 支持bitcode。
* 支持通过scanRect设置扫码框UI的frame，支持通过rectOfInterest设置识别范围。
* 不再暴漏头文件TBScanViewController+Private.h，增加头文件TBScanSDK.h可引入全部依赖。
* 移除exit方法和exitCallBack回调，增加没有摄像头访问权限的回调cameraPermissionDenied和摄像头启动回调cameraDidStart。@all
  + 正常退出时不需要调用exit，退出逻辑也不需要在exitCallBack里实现，摄像头会在退出时自动关闭。
  + 摄像头没有权限的处理在cameraPermissionDenied回调里实现。
  + @支付宝 停止扫描的功能调用exitScan来实现。
* 增加iPad识别本地相册图片失败的回调scanPadPhotoFailed。@支付宝
* 拍照接口调整为block回调，不再使用delegate回调。@天猫
  ```
  -(void)captureStillImage:(void (^)(CMSampleBufferRef imageDataSampleBuffer, NSError *error))handler;
  ```
* TBScanResult的extData里增加条码、二维码在图片中的范围TBScanExtDataBarcodeQRRect，可能会为空。@支付宝
* 移除二维码弹层视图TBScanQRFloatView和相关图片资源。
* 所有资源文件统一到TBScanSDK.bundle中。
