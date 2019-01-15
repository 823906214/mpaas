//
//  define_public.h
//  BeeCapture
//
//  Created by noahlu on 16/4/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#ifndef define_public_h
#define define_public_h

#define BeeCaptureAPPID @"20000911"
#define BeeCaptureBizId @"BeeCapture"

/*!
 视频/拍照 采集类型
 */
typedef enum {
    BCMovieRecordViewTypePhoto = 0,
    BCMovieRecordViewTypeMovie,
    BCMovieRecordViewTypeMovieAndPhoto,
}BCMovieRecordViewType;

typedef enum {
    BCMovieRecordStatusNone = 0,
    BCMovieRecordStatusRuning,
    BCMovieRecordStatusCancel
}BCMovieRecordStatus;

typedef enum {
    BCMovieRecordSendStatusNormal = 0,
    BCMovieRecordSendStatusCancel,
    BCMovieRecordSendStatusProgressFinish,
    BCMovieRecordSendStatusProgressFinishCancel
}BCMovieRecordSendStatus;

typedef enum {
    BCMovieRecordRecentStatusShowAndStore = 0,  //显示14天小视频 入口，且写入小视频
    BCMovieRecordRecentStatusHidenAndStore,     //不显示14天小视频 入口，写入小视频
    BCMovieRecordRecentStatusHidenUnStore,      //不显示14天小视频 入口，不写入小视频
}BCMovieRecordRecentStatus;

/*!
 视频/拍照 当前切换控件状态
 */
typedef enum {
    BCRecordSwitchStatusNone = 0,
    BCRecordSwitchStatusCameraMain,         // 视频和拍照模式都有，默认选中视频模式
    BCRecordSwitchStatusPhotoMain,          // 视频和拍照模式都有，默认选中拍照模式
    BCRecordSwitchStatusCameraOnly,         // 只显示视频模式
    BCRecordSwitchStatusPhotoOnly           // 只显示拍照模式
}BCRecordSwitchStatus;


NS_INLINE UIImage * BC_IMG(NSString *name) {
    return [UIImage imageNamed:[NSString stringWithFormat:@"BeeCapture.bundle/%@", name]];
}


#define BC_TEXT(text) __TEXT(@"BeeCapture",@"BeeCapture:"text,text)

#define BCLogError(fmt, ...) \
NSLog(fmt, ##__VA_ARGS__); \
APLogToFile(@"[BeeCapture]", kAPLogLevelError, fmt, ##__VA_ARGS__);

#define BCLogInfo(fmt, ...) \
NSLog(fmt, ##__VA_ARGS__); \
APLogToFile(@"[BeeCapture]", kAPLogLevelInfo, fmt, ##__VA_ARGS__);

#define BCLogWarn(fmt, ...) \
NSLog(fmt, ##__VA_ARGS__); \
APLogToFile(@"[BeeCapture]", kAPLogLevelWarn, fmt, ##__VA_ARGS__);

#define BCLogDebug(fmt, ...) \
NSLog(fmt, ##__VA_ARGS__);


#define WS(weakSelf) __weak typeof (self) weakSelf = self;


#endif /* define_public_h */
