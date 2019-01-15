//
//  APVoiceManager.h
//  APMultimedia
//
//  Created by fuxin on 15/4/1.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APMMConst.h"
#import "AMMAudioMessage.h"
#import "APVoiceRequest.h"
#import "APBaseUploadRequest.h"

/**
   开始录音状态
 */
typedef enum : NSUInteger {
    APMMAudioStartRecord,                       //准备录音
    APMMAudioRecording,                         //录音开始
    APMMAudioStartRecordFail,                   //录音发生错误
    APMMAudioStartInvalidFilePath,              //无效路径

    APMMAudioRecordUndefine
} APMMAudioStartRecordStatus;

typedef enum : NSUInteger {
    APMMAudioSpeaker = 0,                       //扬声器(扬声器模式下sensor自动生效)
    APMMAudioReciever,                          //听筒
} APMMAudioListionEnum;

/**
   结束录音状态
 */
typedef enum : NSUInteger {
    APMMAudioStopRecordError,                       //录音错误
    APMMAudioStopRecordFinish,                      //录音完成(默认自动上传)
    APMMAudioStopRecordCancel,                      //录音取消
    APMMAudioStopRecordTimerOut,                    //录制时间超过设定的最大时间而异常结束
    APMMAudioStopRecordTimeNotEnough,               //录音时间不足
    APMMAudioStopRecordUploadFail,                  //上传录音失败
    APMMAudioStopRecordUploadSuccuss,               //上传录音成功
    APMMAudioStopRecordUndefined                    //
} APMMAudioStopRecordStatus;

/**
   播放(包括下载动作)状态
 */
typedef enum : NSUInteger {
    APMMAudioStartDownLoad,                     //开始下载
    APMMAudioFinishDownLoad,                    //下载结束
    APMMAudioDownLoadFail,                      //下载失败
    APMMAudioPlayBegin,                         //开始播放
    APMMAudioPlayFinish,                        //播放结束
    APMMAudioPlayTerminal,                      //播放终止
    APMMAudioPlayFail,                          //播放失败
    APMMAudioPlayLowVolume,                     //音量过低
    APMMAudioPlayNormalVolume,                  //音量恢复正常(APMMAudioPlayLowVolume后出现)
    APMMAudioPlayUndefined
} APMMAudioPlayStatus;

/**
 *  开始录音Block
 *
 *  @param status  开始录音状态
 *  @param message 音频对象(包含wav路径、时长、音频数据)
 *  @param cloudId 云ID，上传成功后会获取到该ID
 *  @param error   异常信息
 */
typedef void (^APMultiMediaAudioStartRecordHandler)(APMMAudioStartRecordStatus status, NSError* error);


/**
 *  录音计时
 *
 *  @param time
 */
typedef void (^APMultiMediaAudioRecordTime)(NSTimeInterval time);

/**
 *  结束录音Block
 *
 *  @param status  结束录音状态
 *  @param localId LocalId, 录音结束后会获取到该ID
 *  @param cloudId CloudID，上传成功后会获取到该ID
 *  @param error   异常信息
 */
typedef void (^APMultiMediaAudioStopRecordHandler)(APMMAudioStopRecordStatus status,NSString* localId,NSString* cloudId,NSError* error);

/**
 *  Mic输入音量分贝值
 *
 *  @param power (-120 ~ -1)
 */
typedef void (^APMultiMediaAudioMicPower)(CGFloat power);

/**
 *  音频下载状态block
 *
 *  @param status  音频下载状态值
 *  @param cloudId cloudId
 *  @param error   异常信息
 */
typedef void (^APMultiMediaAudioDownLoadHandler)(APMMAudioPlayStatus status,
                                                 NSString* cloudId,
                                                 NSError* error);


typedef void (^APMultiMediaAudioPlayLocalIdHandler)(NSString* localId, APMMAudioPlayStatus status);


typedef void (^APMultiMediaAudioPlayCloudIdHandler)(NSString* cloudId, APMMAudioPlayStatus status);


typedef void (^APMultiMediaAudioGetCacheHandler)(NSData* response, NSError* error);
/**
 *  听筒、扬声器切换通知
 */
extern NSString *const APVoiceListionStateDidChangeNotification;


@interface APVoiceUploadRequest : APBaseUploadRequest

@property(nonatomic, copy)APMultiMediaAudioStopRecordHandler uploadHandler;

@end


@interface APVoiceManager : NSObject

//实例
+ (instancetype)sharedManager;

#pragma mark -- 获取麦克风权限
/**
 *  mic访问权限
 *
 *  @param block YES:NO
 */
+ (void)requestMicrophonePermission:(void (^)(BOOL granted))block;


#pragma mark -- 语音播放模式切换
/**
 *  切换语音播放模式
 *
 *  @param mode 听筒/扬声器/恢复为以sensior检测来切换
 */
+ (void)changeListionMode:(APMMAudioListionEnum)mode;


/**
 *  获取收听模式
 *
 *  @return 听筒、扬声器
 */
+ (APMMAudioListionEnum)getListionMode;

#pragma mark -- 语音录制
/**
 *  开始录音
 *
 *  @param maxSec       最大录音时长
 *  @param minSec       最小录音时长
 *  @param active       录音结束时是否恢复session的active状态
 *  @param business     业务存储标识
 *  @param powerHandler mic检测音量分贝
 *  @param handler      APMultiMediaAudioStartRecordHandler
 *  @param stopHandler  APMultiMediaAudioStopRecordHandler
 */
- (void)startRecordWithMaxSec:(double)maxSec
                       minSec:(double)minSec
                 resumeActive:(BOOL)active
            thirdAudioPlaying:(BOOL)thirdPlaying
                     business:(NSString *)business
                     micPower:(APMultiMediaAudioMicPower)powerHandler
                 recordedTime:(APMultiMediaAudioRecordTime)recordTime
           recordStartHandler:(APMultiMediaAudioStartRecordHandler)handler
            recordStopHandler:(APMultiMediaAudioStopRecordHandler)stopHandler;

#pragma mark -- 语音上传
/**
 *  重新上传录音(对于录音完成上传失败的情况，重新上传录音)
 *
 *  @param message  音频对象(包含wav路径、时长、音频数据)
 *  @param business 业务存储标识
 *  @param progress 上传进度block
 *  @param handler  上传完成block
 */
- (void)uploadAudioWithLocalId:(NSString*)LocalId
                      business:(NSString *)business
                      progress:(APMMProcessiveBlock)progress
                 uploadHandler:(APMultiMediaAudioStopRecordHandler)handler;

- (void)uploadAudioWithLocalId:(NSString*)LocalId
                 request:(APVoiceUploadRequest *)uploadRequest;

#pragma mark -- 语音停止、取消录制
/**
 *  结束录音
 *
 *  @param handler 结束录音block
 */
- (void)stopRecord;


/**
 *  取消录音
 */
- (void)cancelRecord;

#pragma mark -- 语音下载
/**
 *  下载录音
 *
 *  @param cloudId cloudID
 *  @param business 业务存储标识
 *  @param handler 下载完成block
 */
- (void)downLoadAudioWithCloudId:(NSString*)cloudId
                        business:(NSString *)business
                 downLoadHandler:(APMultiMediaAudioDownLoadHandler)handler;

/**
 *  下载录音
 *
 *  @param identifier cloudId
 *  @param request    APVoiceRequest
 *
 *  @return 任务id用于取消任务
 */
- (NSString *)getAudio:(NSString*)identifier
               request:(APVoiceRequest*)request;

#pragma mark -- 语音播放
/**
 *  通过cloudId播放音频
 *
 *  @param CloudId
 *  @param downLoadHandler
 *  @param playHandler
 */

- (void)playAudioWithCloudId:(NSString*)CloudId
                    business:(NSString *)business
             downLoadHandler:(APMultiMediaAudioDownLoadHandler)downLoadHandler
                 playHandler:(APMultiMediaAudioPlayCloudIdHandler)playHandler;



/**
 *  通过cloudId播放音频
 *
 *  @param CloudId            音频数据cloudId
 *  @param active             播放结束时是否恢复session的active状态
 *  @param downLoadHandler    downLoadHandler
 *  @param playHandler        playHandler
 */

- (void)playAudioWithCloudId:(NSString*)CloudId
                    business:(NSString *)business
                resumeActive:(BOOL)active
             downLoadHandler:(APMultiMediaAudioDownLoadHandler)downLoadHandler
                 playHandler:(APMultiMediaAudioPlayCloudIdHandler)playHandler;



/**
 *  播放录音
 *
 *  @param mesage  音频message
 *  @param handler 播放block
 */
- (void)playAudioWithLocalId:(NSString*)localId
                 playHandler:(APMultiMediaAudioPlayLocalIdHandler)handler;


/**
 *  播放录音
 *
 *  @param mesage  音频message
 *  @param handler 播放block
 */
- (void)playAudioWithLocalId:(NSString*)localId
                resumeActive:(BOOL)active
                 playHandler:(APMultiMediaAudioPlayLocalIdHandler)handler;


/**
 *  获取播放时长
 *
 *  @return NSTimeInterval
 */
- (NSTimeInterval)getCurrentPlayTime;


/**
 *  暂停播放
 *
 *  @return 当前播放时间
 */
- (NSTimeInterval)pausePlay;


/**
 *  恢复播放
 */
- (void)resumePlay;

/**
 *  停止播放
 */
- (void)stopAudioPlay;



/**
 *  通过LocalId获取音频信息
 *
 *  @param localId
 *
 *  @return message
 */
+ (AMMAudioMessage*)getMessageWithLocalId:(NSString*)localId;


/**
 *  是否正在录音
 *
 *  @return BOOL
 */
- (BOOL)isRecording;


/**
 *  是否正在播放
 *
 *  @return BOOL
 */
- (BOOL)isPlaying;

#pragma mark - cache
/**
 *  获取音频缓存
 *
 *  @param cloudId
 *
 *  @return NSData
 */
- (NSData *)getCacheVoiceForCloudId:(NSString *)cloudId;

#pragma mark - 阅后即焚删除接口
/**
 *  清除缓存语音
 *
 *  @param identifier localId/cloudId
 */
- (void)clearCacheForIdentifier:(NSString *)identifier;
@end
