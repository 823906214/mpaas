//
//  BCMediaRecordBtnView.h
//  BeeCapture
//
//  Created by noahlu on 16/4/25.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@class BCMediaRecordBtnView;

@protocol BCMediaRecordBtnViewDelegate <NSObject>

@optional

// 单击事件被触发
- (void)didMovieBtnPressed:(BCMediaRecordBtnView *)view;

- (void)didPhotoBtnPressed:(BCMediaRecordBtnView *)view;

// 长按动作结束
- (void)runRrogress:(CGFloat)progress view:(BCMediaRecordBtnView *)view;

// 视频录制结束(6s)
- (void)didMovieRecordFinish:(BCMediaRecordBtnView *)view;

// 视频录制取消
- (void)didMovieRecordCanceled:(BCMediaRecordBtnView *)view;

#pragma mark - 供社交

//
- (void)didLongPressedBeganInView:(BCMediaRecordBtnView *)view;

//
- (void)didLongPressedEndInView:(BCMediaRecordBtnView *)view;

@end

typedef enum {
    BCMediaRecordStatusPhoto = 0,
    BCMediaRecordStatusMedia,
}BCMediaRecordStatus;

typedef NS_ENUM(NSInteger, BCMediaRecordTouchArea) {
    BCMediaRecordTouchAreaNone,           // 用户当前什么都没有按着
    BCMediaRecordTouchAreaRecording,      // 用户当前按着录制区域
    BCMediaRecordTouchAreaCancelRecord    // 用户当前按着取消录制区域
};

#define kRecordBtnSize (65)

@interface BCMediaRecordBtnView : UIView

@property (nonatomic, weak) id<BCMediaRecordBtnViewDelegate> delegate;
@property (nonatomic, assign) CGFloat progress;
@property (nonatomic, assign) BCMediaRecordStatus recordSatus;
@property (nonatomic, assign) BOOL enable;

- (id)initWithFrame:(CGRect)frame delegate:(id)delegate;

- (void)cancelRecording;

- (BOOL)isRecording;

- (BCMediaRecordTouchArea)touchArea;

@end
