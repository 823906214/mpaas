//
//  APUtils.h
//  APCommonUI
//
//  Created by WenBi on 14-1-16.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_INLINE NSString * _Nullable AUBundleImageName(NSString * _Nonnull imageName) {
    return [NSString stringWithFormat:@"APCommonUI.bundle/%@", imageName];
}

NS_INLINE UIImage * _Nullable AUBundleImage(NSString * _Nonnull imageName) {
    return [UIImage imageNamed:AUBundleImageName(imageName)];
}

NS_INLINE NSString * _Nullable AUBundleResourcePath(NSString * _Nonnull resName, NSString * _Nullable resType) {
    return [[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"APCommonUI.bundle/%@", resName] ofType:resType];
}

NS_INLINE CGFloat AUSystemVersion() {
    return ([[[UIDevice currentDevice] systemVersion] floatValue]);
}

NS_INLINE BOOL AUDeviceIsIphone6Plus() {
    return (CGSizeEqualToSize([UIScreen mainScreen].bounds.size, CGSizeMake(414, 736)));
}

NS_INLINE BOOL AUDeviceIsLowerIphone6() {
    return [UIScreen mainScreen].bounds.size.width == 320;
}

//
NS_INLINE BOOL AUIsPad()
{
    return UIDevice.currentDevice.userInterfaceIdiom == UIUserInterfaceIdiomPad;
}

// 适配小屏手机
NS_INLINE CGFloat AUValueAfterScale(CGFloat value)
{
    if (AUIsPad()) {
        return value;
    }
    
    if (AUDeviceIsLowerIphone6()) {
        CGFloat minFactor = MIN([UIScreen mainScreen].bounds.size.width / 375, [UIScreen mainScreen].bounds.size.height / 667);
        return value * minFactor;
    }
    return value;
}

NS_INLINE CGSize CGSizeFromNSValue(NSValue * _Nullable value, CGSize defaultSize)
{
    return value ? [value CGSizeValue] : defaultSize;
}

@interface UIColor (AUCommonUIExtensions)

/**
 * 用一个24位的整数生成UIColor
 * 这个方法实现如下，只会返回不透明的颜色
   return [UIColor colorWithRed:((rgb & 0xFF0000) >> 16) / 255.0f
      green:((rgb & 0xFF00) >> 8) / 255.0f
      blue:((rgb & 0xFF)) / 255.0f
      alpha:1.0f];
 * @param rgb 形如0xRRGGBB
 */
+ (UIColor *_Nonnull)colorWithRGB:(int)rgb;

// 这个方法可以指定透明度，alpha取值是[0, 1.0]
+ (UIColor *_Nonnull)colorWithRGB:(int)rgb alpha:(CGFloat)alpha;

//
+ (nullable UIColor *)colorFromHexString:(nullable NSString *)hexString;

//
+ (nullable UIColor *)colorFromHexString:(nullable NSString *)hexString alpha:(CGFloat)alpha;

// argb color（写法 #FFababab）
+ (nullable UIColor *)colorFromArgbHexString:(nullable NSString *)hexString;


@end

/**
 *  获取view距离屏幕上方的距离
 *
 */
CGFloat AUCommonUIGetContentInsetTop();

/**
 *  无论竖屏还是横屏，都返回竖屏时屏幕的宽度
 */
CGFloat AUCommonUIGetScreenWidthForPortrait();

/**
 *  无论竖屏还是横屏，都返回竖屏时屏幕的高度
 */
CGFloat AUCommonUIGetScreenHeightForPortrait();

/*
 获取一像素的方法
 */
CGFloat AUUIGetOnePixel();

/**
 * 获取屏幕宽度，竖屏时返回竖屏的宽度，横屏时返回横屏的宽度
 */
CGFloat AUCommonUIGetScreenWidth();

/**
 * 获取屏幕高度
 */
CGFloat AUCommonUIGetScreenHeight();

/**
 * 获取状态栏高度
 */
CGFloat AUCommonUIGetStatusBarHeight();

/**
 * 通话情况下状态栏返回非通话模式高度
 */
CGFloat AUCommonUIGetStatusBarFixedHeightIncall();

/**
 * 获取当前keywindow的SafeAreaInsets
 */
UIEdgeInsets AUGetWindowSafeAreaInsets();
/**
 * 获取导航栏高度
 */
//CGFloat AUCommonUIGetNavigationBarHeight() __deprecated_msg("业务请勿继续使用");

/**
 *  获取导航栏上icon的间距
 */
CGFloat AUCommonUIGetMarginBetweenNavigationItemIcon();

/**
 *  trim字符串前后空格
 */
NSString * _Nullable AUCommonUITrim(NSString * _Nullable string);


/**
 * 判断是否为iPhone X设备
 */

BOOL AUDeviceIsIphoneX();



/**
 方向

 - AUDirectionTop: 上
 - AUDireictionLeft: 左
 - AUDirectionBottom: 下
 - AUDirectionRight: 右
 */
typedef NS_ENUM(NSInteger, AUDirection) {
    AUDirectionTop = 0,
    AUDirectionLeft,
    AUDirectionBottom,
    AUDirectionRight,
};

/**
 底部View适配
 适配规则：
 1、高度不变，但insets.bottom的视图视参数作为子视图append在view的下面（超出bounds）
 2、宽度减去insets.left和insets.right
 3、忽略insets.top的处理
 4、需要业务自己设置y

 @param view 视图
 @param insets 适配边缘
 @param expandColor 延展区域背景色
 @param expandConfig 延展区配置
 */
void iPhoneX_makeViewInBottom(UIView * _Nonnull view,
                              UIEdgeInsets insets,
                              UIColor * _Nonnull expandColor,
                              void(^ _Nullable expandConfig)(AUDirection direction, UIView * _Nullable expandView));



/**
 对分隔线做垂直方向渐变(主要是TabBar的分隔线)

 具体做法：
 iPhone X： 设置Line的背景色为渐变色
 其他设备：设置Line背景色为纯色

 @param line 需要滑颜色的线
 @param color 颜色
 */
void iPhoneX_makeLineVerticalGradual(UIView * _Nonnull line, UIColor * _Nonnull color);
/**
 如果是虚线会变为实线

 @param line 需要滑颜色的线
 @param color 颜色
 */
void iPhoneX_makeLineVerticalReal(UIView * _Nonnull line, UIColor * _Nonnull color);

