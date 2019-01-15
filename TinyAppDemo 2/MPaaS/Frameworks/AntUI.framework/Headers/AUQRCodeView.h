#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_QRCode_AUQRCodeView//程序自动生成
//
//  AUQRCodeView.h
//  AntUI
//
//  Created by niki on 2017/5/18.
//  Copyright © 2017年 Alipay. All rights reserved.
//


//#########################################################
//文档地址 : http://aui.alipay.net/develop/ios/auqrcodeview
//#########################################################


AntUI_dependency(AULabel)


// 数据模型对象
@interface QRDataModel : NSObject

@property (nonatomic, strong) id topLeftIcon;   // 可以传 image 或者 url 或者 cloudID
@property (nonatomic, strong) NSString *topTitle; // 可以传 image 或者 url 或者 cloudID
@property (nonatomic, strong) id qrCodeIcon;    // 二维码图
@property (nonatomic, strong) NSString *bottomTitle;
@property (nonatomic, strong) NSString *bottomMessage;
@property (nonatomic, strong) id actionButtonIcon;  // 可以传 image 或者 url 或者 cloudID
@property (nonatomic, strong) NSString *actionButtonTitle; // 底部行动按钮主文案
@property (nonatomic, strong) NSString *actionButtonMessage; // 底部行动按钮辅助文案

@end

// 二维码底部行动按钮
@interface QRActionButton : UIControl

@end


// 二维码组件
@interface AUQRCodeView : UIView

@property (nonatomic, strong) UIView *maskView;
@property (nonatomic, strong) UIView *containerView;            // 二维码容器
@property (nonatomic, strong) UIImageView *topLeftImageView;  // 左上角图片   默认 size:(54,54) 1p
@property (nonatomic, strong) AULabel *topTitleLabel;   // 顶部 title 描述文案
@property (nonatomic, strong) UIImageView *qrCodeView;  // 二维码图  默认 size:(260,260) 1p
@property (nonatomic, strong) AULabel *bottomTitleLabel;    // 底部主说明文案
@property (nonatomic, strong) AULabel *bottomMessageLabel;    // 底部辅助说明文案
@property (nonatomic, strong) QRActionButton *actionButton;         // 底部行为按钮

// frame 即控件 frame;  block 初始化数据模型
- (instancetype)initWithFrame:(CGRect)frame model:(void(^)(QRDataModel *model))block;

// 转菊花
- (void)startLoading;

// 停止菊花
- (void)stopLoading;

@end
#endif//程序自动生成
