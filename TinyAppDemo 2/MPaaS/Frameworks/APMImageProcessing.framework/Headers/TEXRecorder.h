//
//  TEXRecorder.h
//  TEX
//
//  Created by Cloud on 2017/3/3.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#import "TEXSource.h"
#import "TEXRecordFunctor.h"

// 视频录制相关状态
typedef enum : NSUInteger {
    TEXRecordStarted,                     // 录制开始
    TEXRecording,                         // 正在录制
    TEXRecordCanceled,                    // 录制取消
    TEXRecordFinished,                    // 录制完成
    TEXRecordInterupted,                  // 录制被中断
    TEXRecordUndefine                     // 未知错误
} TEXRecordStatus;

/**
 *  录屏Block
 *
 *  @param status       录制状态
 *  @param path         视频路径
 *  @param thumbnail    视频首帧图
 *  @param error        异常信息
 */
typedef void (^TEXRecordHandler)(TEXRecordStatus status, NSString *path, UIImage *thumbnail, NSError* error);

/**
 *  截屏Block
 *
 *  @param image   截屏的图片
 *  @param error   异常信息
 */
typedef void (^TEXSnapshotHandler)(UIImage *image, NSError* error);


@interface TEXRecorder : NSObject

@property (nonatomic, assign) CGSize outputSizeInPixels; // 以像素为单位
@property (nonatomic, copy)   NSString *outputPath; // 视频生成路径
@property (nonatomic, assign) TEXRecorderAudioSource audioSource; // 录制声音源
#if ANT3D_RENDER_SYNTHESIZED_TEXTURE
@property (nonatomic, weak)   UIView *view;
#endif

#pragma mark - 录屏/截屏

/**
 *  增加录制源，最终会将这些源合成到视频中
 *
 *  @param source 录制源
 */
- (void)addRecorderSource:(TEXSource *)source;

/**
 *  开始录屏
 *
 *  @param  handler     异步开始录制回调，回调位于主线程
 */
- (void)startRecording:(TEXRecordHandler)handler;

/**
 *  取消录制
 *  会在startRecording的回调中返回相应的事件
 */
- (void)cancelRecording;

/**
 *  结束录制
 *  会在startRecording的回调中返回相应的事件
 */
- (void)stopRecording;

/**
 *  截屏
 *
 *  @param  handler     截屏完成回调，回调位于主线程
 */
- (void)snapshot:(TEXSnapshotHandler)handler;

@end
