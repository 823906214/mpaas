//
//  FrameRender.h
//  QupaiSDKAlipayDevApp
//
//  Created by yly on 15/11/5.
//  Copyright © 2015年 lyle. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#import <UIKit/UIKit.h>
#import <CoreMedia/CMFormatDescription.h>
#import <CoreMedia/CMSampleBuffer.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

#import <OpenGLES/ES3/gl.h>
#import <OpenGLES/ES3/glext.h>

@protocol FalconLooksFrameRenderDelegate;

@interface FalconLooks : NSObject
{
    @public NSInteger height;
    @public NSInteger width;
}

@property (nonatomic, weak) id<FalconLooksFrameRenderDelegate> delegate;

/**
 *  初始化图片处理Context，提前调用可以减少init的耗时
 */

+ (void)initImageProcessingContext;

//小视频初始化
- (instancetype)initWithSize:(CGSize)fromSize toSize:(CGSize)toSize;

//智能裁剪初始化，减少不必要的内存
- (instancetype)initForIntelligentCut;

//获取当前系统环境
- (EAGLContext *)context;

//贴素材接口
- (void)captureOutput:(AVCaptureOutput *)captureOutput didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer fromConnection:(AVCaptureConnection *)connection;

//处理单张图片
- (void)processSkinImage:(UIImage *)image value:(CGFloat)value block:(void(^)(UIImage *image))block;

//设置美颜的参数
- (void)changeFilterValue:(CGFloat)value;

//处理纹理的接口，高shader模式
- (void)processTexture:(GLuint)texture size:(CGSize)size time:(CMTime)time;

//删除内存
- (void)DeleteOpenGLMemory;

//智能裁剪，获取基于人脸检测的矩形框
- (CGRect)GetImgRectForHead:(UIImage*)Img FrameW:(NSInteger)FrameW  FrameH:(NSInteger)FrameH;

@property (nonatomic, assign) BOOL enableSkinFilter;    //美颜开关
@property (nonatomic, assign) BOOL enableStyleFilter;   //风格滤镜开关
@property (nonatomic , assign) BOOL isHighDegree;      //是否开启高美颜效果
@property (nonatomic , assign) BOOL isFalconMirror;     //是否素材镜像
@property (nonatomic , assign) BOOL isCaptureStillImage; //是否拍照
@property (nonatomic , strong) NSString* materialpath;  //贴素材接口，nil为不贴
@property (nonatomic , assign) NSInteger filtertype;    //滤镜类型，<=0不进行滤镜
@property (nonatomic , assign) AVCaptureVideoOrientation VideoOrientation;  //视频帧方向

@end

@protocol FalconLooksFrameRenderDelegate <NSObject>

- (void)FalconLooksframeRenderForVideo:(FalconLooks *)FalconLooksframeRender texture:(GLuint)texture  renderinfo:(NSDictionary*)renderinfo  time:(CMTime)time;

@end