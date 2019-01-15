//
//  BCVideoRecordViewController.h
//  BeeCapture
//
//  Created by noahlu on 16/4/25.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "define_public.h"
#import <APMultimedia/APVideoRecorder.h>

typedef NS_ENUM(NSInteger, BEETouchArea) {
    BEETouchAreaNone,           // 用户当前什么都没有按着
    BEETouchAreaRecording,      // 用户当前按着录制区域
    BEETouchAreaCancelRecord    // 用户当前按着取消录制区域
};


@interface APVideoInfo (BeeCapture)

@property CGFloat recordProgress;  // 视频录制结束时的进度
@property BEETouchArea touchArea;  // 视频录制结束时的用户按着的区域

@end

@interface UIImage (BeeCapture)

// 特殊场景接口，通常请不要使用
- (NSString *)BEE_imageKey;

@end


/*!
 @brief 视频录制结束回调
 
 @param info 视频信息
 */
typedef void(^videoCallback)(APVideoInfo *info);

/*!
 @brief 拍照结束回调
 
 @param imageOrAsset 图片或者ALAsset
 */
typedef void(^imageCallback)(id image);

/*!
 @brief 取消按钮点击事件
 */
typedef void(^cancelCallback)(void);


// 图片保存成功通知，object为image对象，
// userInfo：保存成功@{@"identifier" : xxxxx}
//           保存失败@{@"error" : xxxxx}
#define kImageSaveToAlbumCompletionNotification (@"kImageSaveToAlbumCompletionNotification")




@interface BCVideoRecordViewController : DTViewController

/**
 *  业务标识
 */
@property (nonatomic, copy) NSString *business;

/*!
 @brief 采集组件配置
 @param options
     @{
        @"videoCallback" : <videoCallback> block,
        @"imageCallback" : <imageCallback> block,
        @"cancelCallback" : <cancelCallback> block,
        @"bizId" : <NSString *> bizId,
        @"faceEnabled" : @YES/@NO,
        @"cameraSwitchEnabled" : @YES/@NO,
        @"maxRecordedSeconds" : @(6),
        @"recordType" : [NSNumber numberWithInt:<BCMovieRecordViewType>type]
     }
 */
- (instancetype)initWithOptions:(NSDictionary *)options;

/**
 *   支持添加额外的行为
 *
 *  @param name 名称
 *  @param icon 图标
 *  @param actionBlock 点击事件回调block
 */
- (void)setExtAction:(NSString *)name icon:(UIImage *)icon cornerRadius:(CGFloat)cornerRadius block:(dispatch_block_t)actionBlock;

- (void)updateExtAction:(NSString *)name icon:(UIImage *)icon;

/**
 *  屏幕提示
 *
 *  @param tips 提示
 */
- (void)showTips:(NSString *)tips;

/**
 *  还原录制状态
 */
- (void)resetRecording;



@end
