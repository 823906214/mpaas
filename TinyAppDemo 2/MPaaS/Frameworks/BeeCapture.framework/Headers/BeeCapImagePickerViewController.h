//
//  BeeCapImagePickerViewController.h
//  BeeCapture
//
//  Created by manyi.zsf on 2017/5/2.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "BCMaskView.h"

/*!
 @brief 拍照结束回调
 
 @param 一张或多张image localId
 */
typedef void(^imagesCallback)(NSArray *images);

/*!
 @brief 拍照结束回调
 
 @param images 一张或多张image localId
 @param info 辅助信息，如裁切区域（cropRect）
 */
typedef void(^imagesWithInfoCallback)(NSArray *images, NSDictionary *info);

/*!
 @brief 取消按钮点击事件
 */
typedef void(^cancelCallback)(void);

/*!
 @brief 拍摄控件初始化完成回调
 
 @param data 
 @param error 错误信息
 */
typedef void(^onReadyCallback)(NSDictionary *data, NSError *error);


@interface BeeCapImagePickerViewController : DTViewController

/**
 *  业务标识
 */
@property (nonatomic, copy) NSString *business;

@property (nonatomic, weak) id<BCMaskViewDelegate> maskDelegate;

/*!
 @brief 采集组件配置
 @param options
 @{
 @"landscape" : <BOOL> landscape,                   //横屏拍摄，default is NO
 @"captureTip" : <NSString *>captureTip,            //拍摄页面提示文案
 @"continueShooting" : <BOOL> continueShooting,     //支持多次拍摄, default is NO
 @"widthPercent" : <CGFloat> widthPercent,          //框框宽度的比例，0.0～1.0
 @"heightPercent" : <CGFloat> heightPercent,        //框框高度的比例，0.0～1.0
 @"previewActions" : <NSArray *> previewActions,    //@see PreviewAction
 @"imagesWithInfoCallback" : <imagesWithInfoCallback> block,        //拍照结果回调
 @"cancelCallback" : <cancelCallback> block,        //取消关闭回调
 @"bizId" : <NSString *> bizId,                     //业务标识，@see business
 @"needCrop" : <BOOL> needCrop,                     //是否需要按照取景框比例裁切
 }
 
 PreviewAction:{
 actionType:("done"|"recapture"|"addOneMore")//只支持这三种行为
 actionText:"Your text"//最多展示4个汉字
 specialColor:true|false //为true的时候使用蓝色背景，突出重点
 }
 */
- (instancetype)initWithOptions:(NSDictionary *)options;
//更新页面的方法
- (void)updateUIWithOptions:(NSDictionary *)options;
//退出
- (void)quit;
//拍摄照片
- (void)takePhotoWithCallback:(imagesWithInfoCallback)callback;

@end
