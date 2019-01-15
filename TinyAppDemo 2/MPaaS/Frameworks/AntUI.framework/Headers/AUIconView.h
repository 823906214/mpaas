#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_IconFont_AUIconView//程序自动生成
//
//  AUIconView.h
//  AntUI
//
//  Created by maizhelun on 2016/9/27.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUIconFontConstants.h"


//#########################################################
//文档地址 : http://aui.alipay.net/develop/ios/auiconview
//#########################################################


// AntUI默认iconfont名称
#define kICONFONT_FONTNAME              (@"auiconfont")
// AntUI默认iconfont路径
#define kICONFONT_FONTPATH              (@"APCommonUI.bundle/iconfont/auiconfont")



#define UI_AUIconView

/**
 iconfont图片控件（可以类似当做imageview来使用）
 实际是通过string的drawrect功能画出的image对象，
 注意目前只支持正方形的矢量图

 iconfont相当于是加载了一个字体，一个字体对应了多张图片，每个图片有一个unicode码，
 所以可以设置text为对应的unicode码，并调用string的drawInRect方法将iconfont渲染出来。

 每个iconfont集合实际就是一个ttf字体文件，因此可以加载多个
 ttf字体文件，每个ttf字体文件有一个名称，默认AntUI的ttf字体
 名称为auiconfont。
 */
@interface AUIconView : UIImageView

@property (nonatomic, strong) UIColor *color;       // 矢量图颜色(默认蚂蚁蓝)
@property (nonatomic, strong) NSString *name;       // 矢量图名称
@property (nonatomic, strong) NSString *fontName;   // 矢量图字库名称


/**
 初始化方法

 @param frame 视图frame
 @param name  iconfont图片名称

 @return AUIconView实例
 */
- (instancetype)initWithFrame:(CGRect)frame name:(NSString *)name;

/**
 初始化方法
 （如果该种iconfont字体已经加载过，则不需要传入fontPath也可以渲染）

 @param frame    视图frame
 @param name     iconfont图片名称
 @param fontName iconfont字体名称

 @return AUIconView实例
 */
- (instancetype)initWithFrame:(CGRect)frame name:(NSString *)name fontName:(NSString *)fontName;


/**
 获取iconView的size

 @return 如果是iconfont，返回的是iconfont的size，如果是普通的imageview返回的是image的size
 */
- (CGSize)iconViewSize;

@end


@interface UIImage (AUIconFont)

/**
 注册iconfont（只需要调用一次）

 @param fontName iconfont字体名称
 @param fontPath iconfont路径（支持绝对和相对路径等，如@"APCommonUI.bundle/iconfont/auiconfont"）
 */
+ (void)registerIconFont:(NSString *)fontName fontPath:(NSString *)fontPath;

/**
 获取一个正方形矢量图（长和宽相等）

 @param name  名称
 @param width 大小
 @param color 图像颜色，传nil，默认为蚂蚁蓝

 @return 正方形矢量图
 */
+ (UIImage *)iconWithName:(NSString *)name
                    width:(CGFloat)width
                    color:(UIColor *)color;


/**
 获取一个正方形矢量图（长和宽相等）

 @param name        名称
 @param fontName    矢量字体名称
 @param width       大小
 @param color       图像颜色，传nil，默认为蚂蚁蓝

 @return 正方形矢量图
 */
+ (UIImage *)iconWithName:(NSString *)name
                 fontName:(NSString *)fontName
                    width:(CGFloat)width
                    color:(UIColor *)color;


/**
 取消iconfont注册
 如果是已经在info.plist里面配置，则此方法不生效
 
 @param fontName 字体名称
 @param fontPath iconfont路径（支持绝对和相对路径等，如@"APCommonUI.bundle/iconfont/auiconfont"）
 */
+ (void)unregisterIconFont:(NSString *)fontName fontPath:(NSString *)fontPath;


/**
 iconfont是否包含该图标
 
 @param name 图标名称
 @param fontName 字体名称
 @return YES，包含；NO，不包含
 */
+ (BOOL)isIconExists:(NSString *)name inFont:(NSString *)fontName;

@end

#endif//程序自动生成
