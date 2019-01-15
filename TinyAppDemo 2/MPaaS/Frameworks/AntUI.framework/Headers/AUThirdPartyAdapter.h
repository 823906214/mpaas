//
//  AUThirdPartyAdapter.h
//  AntUI
//
//  Created by 祝威 on 16/9/27.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

/*！
 @class       AUThirdPartyAdapter
 @protocol    NSObject
 @discussion  蚂蚁UI的协议
 */

@protocol AUThirdPartyAdapter <NSObject>

@optional
/***********************************************************/
//图片协议APMultimedia
/*
 第三方适配下载图片接口
 主要对多媒体接口进行包装，由第三方实现
 */
- (NSString *)thirdPartyGetImage:(NSString *)identifier
                        business:(NSString *)business
                            zoom:(CGSize)size
                    originalSize:(CGSize)originSize
                        progress:(void (^)(double percentage,long long partialBytes,long long totalBytes))progress
                      completion:(void (^)(UIImage *image, NSError *error))complete;

/*
  第三方适配uiimageview下载图片接口
  由第三方去实现。
 */
- (void)thirdPartypFromImageView:(UIImageView *)fromImgView
                 setImageWithKey:(NSString *)key
                        business:(NSString *)business
                placeholderImage:(UIImage *)placeholder
                            zoom:(CGSize)zoom
                    originalSize:(CGSize)originalSize
                        progress:(void (^)(double percentage,long long partialBytes,long long totalBytes))progress
                      completion:(void (^)(UIImage *image, NSError *error))complete;

/*
 第三方适配下载图片接口
 由第三方去实现。
 */
- (void)thirdPartypGetImageByIdentifier:(NSString *)identifier
                                request:(id)request
                            viewInstant:(UIView *)viewInstants
                                    key:(NSString *)key;

/*
 * 第三方适配获取缓存image
 */
- (UIImage *)thirdPartypGetImageInCache:(NSString *)identifier
                                request:(id)request;

/***********************************************************/
//红点协议MPBadgeService
/*
 初始化红点View
 */
- (UIView *) thirdPartyBadgeViewWithFrame:(CGRect)frame ;

/*
 红点设置widgetId
 
 */
- (void) thirdPartyBadgeViewWith:(UIView *)badgeView
                        widgetId:(NSString *) widgetId;
/*
  注册红点view到MPBadgeManager管理者去。
 */
- (void) thirdPartyBadgeViewReg:(UIView *)badgeView;

/**
 * 更新显示“红点”样式
 * @param badgeView     红点View
 * @param badgeValue  @"."   显示红点
 *                     @"new" 显示new
 *                     @"数字" 显示数字，大于99都显示图片more（...）
 *                     @"惠"/"hui"  显示“惠”字
 *                     @"xin" 显示"新"字
 *                     nil    清除当前显示
 *
 *
 */
+ (void) thirdPartyBadgeViewWith:(UIView *)badgeView
                     updateValue:(NSString *)badgeValue;

/*
 提供业务监控红点控件刷新接口。
 widgetInfo 类型是MPWidgetInfo
 */
- (void) thirdPartyBadgeViewWith:(UIView *)badgeView
           updateBlock:(void(^)(id widgetInfo, BOOL isShow)) updateBlock;

/*
  埋点协议 APMonitor
 */
//按钮的actionName的埋点协议
- (void) thirdPartySetButtonActionLog:(UIButton *)button
                        actionNameLog:(NSString *)actionName;

/*
  通知协议 (AUCardMenu/AUFloatMenu)
 */

/*
 AUCardMenu 注册退出登录的通知，保证退出登录AUCardMenu能够及时销毁 SAAccountDidExitNotification
 */
- (NSString *) thirdPartyCardMenuDismissNotiName;

/*
 AUFloatMenu 注册alerView kShareTokenAlertViewShownNotification
 */
- (NSString *) thirdPartyFloatMenuDismissFromAlertNotiName ;

/*
 AUFloatMenu 注册alerView SALoginAppWillStartNotification
 */
- (NSString *) thirdPartyFloatMenuDismissFromLoginNotiName ;

/* 
  APLogInfo 埋点日志  APMobileFoundation.framework
 */
- (void) thirdPartyAPLogInfo:(NSString *)tag params:(NSString *)param, ...;

/*
 APLogInfo 埋点日志  APMobileFoundation.framework
 */
- (void) thirdPartyAPLogInfo:(NSString *)tag log:(NSString *)log;


/*
 TBIZReport 功能或关键业务不可用时的埋点上报  APMonitor.framework
 */
- (void) thirdPartyMTBIZReport:(NSString *) bizName
                       subName:(NSString *) subName
                      failCode:(NSInteger) failCode
                        params:(NSDictionary *) params;

/**
 Dialog Window 即将展示
 */
- (void) dialogWindowWillShow;

/**
 Dialog Window 即将消失
 */
- (void) dialogWindowDidDismiss;




/////////////////////////////////////////////////////////////
////////////////////// APLanguage ///////////////////////////
/////////////////////////////////////////////////////////////


/**
 *  在名称为 \c bundleName 的bundle中取当前语言状态下\c key 对应的字符串值.
 *
 *  @param key        字符串表中\c key
 *  @param value      默认值, 当找不到该 \c key 对应的 \c value 时返回该默认值.
 *  @param bundleName bundle名称字符串
 *
 *  @return 当前语言状态下\c key 对应的字符串值
 */
- (NSString *)thirdParty_localizedStringForKey:(NSString *)key
                                  defaultValue:(NSString *)value
                                      inBundle:(NSString *)bundleName;


/////////////////////////////////////////////////////////////
////////////////////// APConfig /////////////////////////////
/////////////////////////////////////////////////////////////


/**
 [APConfigService stringForKey]

 @param key 配置服务key
 @return 配置服务的value值
 */
- (NSString *)thirdParty_configForKey:(NSString *)key;

/**
 [APConfigService addConfigChangedObserver]
 @param observer 监听通知的对象
 @param key 配置服务key
 */
- (void)thirdParty_addConfigChangedObserver:(id)observer key:(NSString *)key;

/**
 [APConfigService removeObserver]
 @param observer 监听通知的对象
 @param key 配置服务key
 */
- (void)thirdParty_removeConfigChangedObserver:(id)observer key:(NSString *)key;


- (void)thirdParty_downloadFileWithCloudId:(NSString *)cloudId externDic:(NSDictionary *)externDic;

/////////////////////////////////////////////////////////////
//////////////////////    MD5   /////////////////////////////
/////////////////////////////////////////////////////////////

/**
 获取MD5值

 @param text MD5
 @return md5
 */
- (NSString *)thirdParty_md5String:(NSString *)text;

/////////////////////////////////////////////////////////////
////////////////////    OpenURL   ///////////////////////////
/////////////////////////////////////////////////////////////

/**
 打开URL

 @param url url
 */
- (void)thirdParty_openURL:(NSString *)url;


/*
 * 通用性能埋点
 */
- (void)thirdParty_performanceLog:(NSString *)biztype controlName:(NSString *)controlName;

/*
 * json 字符串解析，解析获取字典
 */
- (NSDictionary *) thirdParty_jsonString_deserialize:(NSString *)jsonString;

- (UINavigationController *)thirdParty_naviController;

/////////////////////////////////////////////////////////////
//////////////////////  Lottie  /////////////////////////////
/////////////////////////////////////////////////////////////

// lottie 初始化
- (UIView *)thirdPartyLottieViewWithFilePath:(NSString *)filePath;

// 感知Lottie是否动画
- (BOOL)thirdPartyLottieViewIsAnimationPlaying:(UIView *)lottieView;

// 设置是否循环动画
- (void)thirdPartyLottieViewSetLoopAnimation:(UIView *)lottieView animation:(BOOL)animation;

//
- (CGFloat)thirdPartyLottieViewanimationProgress:(UIView *)lottieView;

//
- (void)thirdPartyLottieViewSetAnimationProgress:(UIView *)lottieView progress:(CGFloat)progress;

//
- (void)thirdPartyLottieViewPlayProgress:(UIView *)lottieView
                           beginProgress:(CGFloat)beginProgress
                             endProgress:(CGFloat)endProgress;

//
- (void)thirdPartyLottieView:(UIView *)lottieView
                currentFrame:(NSNumber *)currentFrame;

//
- (void)thirdPartyLottieView:(UIView *)lottieView
                  startFrame:(nonnull NSNumber *)startFrame
                     toFrame:(nonnull NSNumber *)toEndFrame;

typedef void (^LOTAnimationCompletionBlock)(BOOL animationFinished);
- (void)thirdPartyLottieView:(UIView *_Nullable)lottieView
                  startFrame:(nonnull NSNumber *)startFrame
                     toFrame:(nonnull NSNumber *)toEndFrame
              withCompletion:(nullable LOTAnimationCompletionBlock)completion;


- (void)thirdPartyLottieView:(UIView *_Nullable)lottieView
                 playToFrame:(nonnull NSNumber *)toFrame
              withCompletion:(nullable LOTAnimationCompletionBlock)completion;

- (BOOL)thirdPartyLottieViewReadFileFail:(UIView *_Nullable)lottieView;

- (NSNumber *_Nullable)thirdPartyLottieViewEndFrame:(UIView *_Nullable)lottieView;

- (NSNumber *_Nullable)thirdPartyLottieViewCurrentFrame:(UIView *_Nullable)lottieView;

- (BOOL)thirdPartyLottieViewIsLoopAnimation:(UIView *_Nullable)lottieView;
@end
