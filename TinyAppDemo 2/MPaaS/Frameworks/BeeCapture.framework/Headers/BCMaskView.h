//
//  BCMaskView.h
//  BeeCapture
//
//  Created by manyi.zsf on 2017/9/22.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#ifndef BCMaskView_h
#define BCMaskView_h

//给业务方的回调
@protocol BCMaskViewDelegate <NSObject>

@optional
- (void)sampleImageClicked;
- (void)previewImageClicked;

@end

//组件内部的回调
@protocol BCMaskViewPrivateDelegate <NSObject>

@optional
- (void)flashBtnClicked:(BOOL)isSelected;

@end

@protocol BCMaskView <NSObject>

- (void)addCaptureRect:(BOOL)needCaptureFrame;
- (CGRect)transparentRect:(BOOL)isCaptureRect;
- (void)setMaskDelegate:(id<BCMaskViewDelegate>)delgate;
- (void)setMaskPrivateDelegate:(id<BCMaskViewPrivateDelegate>)delegate;

@optional
//RectMaskView
- (void)resetRectWithPercentOfWidth:(double)widthPercent andHeight:(double)heightPercent orAspectRatio:(double)aspectRatio;

//SidesMaskView
- (void)setFocusImageUrl:(NSString *)imageUrl;
- (void)setGuideImageUrl:(NSString *)imageUrl;
- (void)setSampleImageUrl:(NSString *)imageUrl;
- (void)setPreviewImageUrl:(NSString *)imageUrl;
- (void)setSceneTextString:(NSString *)text;
- (void)setSceneTextColor:(UIColor *)color;
- (void)showBottomBar:(BOOL)isShow;
- (void)showFlashBtn:(BOOL)isShow;
- (void)switchFlashMode:(BOOL)isOn;
- (void)showScanAnimation:(BOOL)isShow;

@end

#endif /* BCMaskView_h */
