//
//  QRCodeEncoder.h
//  sdk_gen3_3g
//
//  Created by Tom on 15/6/10.
//  Copyright (c) 2015年 Taobao.com. All rights reserved.
//
// 为减少包大小，支付宝钱包不用这个类生成二维码，也没有对应方法实现。输出该头文件仅为兼容淘宝

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, QRCodeEncodeType) {
    QRCodeEncodeTypeGen0 = 0, // 普通黑白二维码
    QRCodeEncodeTypeGen1, // 在背景图片上生成二维码，背景图片比较模糊，生成的二维码其它APP均可以扫描
    QRCodeEncodeTypeGen2, // 在背景图片上生成二维码，背景图片相对清晰，生成的二维码其它APP均可以扫描
    QRCodeEncodeTypeGen3, // 在背景图片上生成二维码，背景图片上除四个角外其它地方没有点阵信息，最美观但只有使用手淘提供的SDK才能解析
    QRCodeEncodeTypeLogoInCenter, // 在黑白二维码中间增加小的Logo图片
};

@interface QRCodeEncodeHints : NSObject

// 只有在生成三代码时才需要设置domainIndex
@property (nonatomic, assign) char domainIndex_gen3;

// 只有在生成三代码时才需要设置originContent，指明三代码的原始内容用于失败时生成普通黑白二维码
@property (nonatomic, copy) NSString *originContent_gen3;

// 此参数声明黑白二维码中间logo图片的size，此size最好小于二维码size的1/3，不指定时SDK会使用默认的size
@property (nonatomic, assign) int logoSize;

// 二维码的margin
@property (nonatomic, assign) int margin;

// 二维码的version
@property (nonatomic, assign) int version;

// 三代码的format
@property (nonatomic, assign) int gen3Format;

@end

@interface QRCodeEncoder : NSObject

/**
 *  生成二维码图片，生成除gen0以外的二维码失败时会尝试生成gen0二维码。使用背景图片时如果背景图大小与最终二维码图片大小不一致则会进行等比缩放，
 *  超出范围的部分会被裁剪掉。使用Logo图片时Logo图片会根据hints参数里的logoSize进行缩放，不指定logoSize时SDK会自动将Logo图片缩放到合适大小。
 *
 *  @param content 二维码的内容，可以是文本也可以是URL
 *  @param image 二维码背景图片或者Logo图片，如果背景图片的长或宽小于124px则会拉伸到124px再生成二维码
 *  @param size 最终生成的二维码图片大小，一般直接传入图片显示到屏幕上的大小
 *  @param type 生成的二维码类型
 *  @param hints 辅助生成二维码的信息
 *
 *  @return 返回生成的二维码图片
 */
+ (UIImage *)encode:(NSString *)content image:(UIImage *)image qrImageSize:(CGFloat)size type:(QRCodeEncodeType)type hints:(QRCodeEncodeHints *)hints;

@end
