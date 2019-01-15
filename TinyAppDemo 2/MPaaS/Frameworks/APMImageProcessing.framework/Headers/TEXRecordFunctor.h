//
//  TEXRecordFunctor.h
//  TEX
//
//  Created by Cloud on 2017/4/27.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "TEXFunctor.h"
#import <AVFoundation/AVFoundation.h>

// 录制音频的模式
typedef enum : NSUInteger {
    TEXRecorderAudioSourceNone = 0,       // 不录制任何声音
    TEXRecorderAudioSourceMic = 1,        // 录制麦克风的声音
} TEXRecorderAudioSource;

@class TEXRecordFunctor;
@protocol TEXRecordFunctorDelegate <NSObject>

- (void)recorder:(TEXRecordFunctor *)recorder didFailWithError:(NSError *)error;
- (void)recorderDidFinishWriting:(TEXRecordFunctor *)recorder;
- (void)recorder:(TEXRecordFunctor *)recorder snapshot:(UIImage *)image;

@end

@interface TEXRecordFunctor : NSObject <TEXInput>

@property (nonatomic, assign) AVCaptureVideoOrientation orientation; // 默认是LandscapeLeft
@property (nonatomic, copy)   NSString *outputPath; // 视频生成路径
@property (nonatomic, strong) UIImage *thumbnail; // 视频首帧图
@property (nonatomic, weak)   id<TEXRecordFunctorDelegate> delegate;
@property (nonatomic, assign) CGSize inputSize; // 视频输入尺寸，不考虑方向
@property (nonatomic, assign) CGSize outputSizeInPixels; // 视频输出尺寸，方向校正之后的尺寸
@property (nonatomic, assign) int bitrate;
@property (nonatomic, assign) int fps;
@property (nonatomic, assign) TEXRecorderAudioSource audioSource; // 声音源

- (void)startRecording;
- (void)cancelRecording;
- (void)stopRecording;
- (void)snapshot;

@end
