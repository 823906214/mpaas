//
//  APSKClient.h
//  APSKClient
//
//  Created by WenBi on 14-1-9.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

#import "APSKConstants.h"

@class APSKLaunchpad;

/**
 * 分享渠道选择面板delegate回调方法
 * The <code>APSKLaunchpadDelegate</code> protocol defines a set of methods
 * for a delegate of a <code>APSKLaunchpad</code> object.
 */
@protocol APSKLaunchpadDelegate <NSObject>

@optional
/**
 * Tells the delegate that the specified sharing channel is now selected.
 *
 * @param launchpad The luanchpad object informing the delegate about the channel selection.
 * @param channelName A string represents the sharing channel.
 */
- (void)sharingLaunchpad:(APSKLaunchpad *)launchpad didSelectChannel:(NSString *)channelName;

/**
 * 此delegate和- (void)sharingLaunchpad:didSelectChannel:根据需要只实现一个即可，如果都实现，分享组件只调用这个.
 *
 * Tells the delegate that the specified sharing channel is now selected.
 *
 * @param launchpad The luanchpad object informing the delegate about the channel selection.
 * @param channelName A string represents the sharing channel.
 */
- (void)sharingLaunchpad:(APSKLaunchpad *)launchpad didSelectChannel:(NSString *)channelName needShowAlert:(BOOL)showAlert;

/**
 * Tells the delegate that the launchpad has been cancelled by user.
 * @param launchpad The launchpad object informing the delegate.
 */
- (void)sharingLaunchpadDidCancel:(APSKLaunchpad *)launchpad;

@end


/**
 * 分享渠道的选择界面。
 *
 * 虽然这个launchpad也是继承自<code>UIView</code>类，但是它与普通的view稍有不同，会有以下默认的行为：
 *
 *  - 高度默认固定，宽度与父视图的宽度相同，并显示在父视图底部。
 *  - 默认显示所有已支持的分享渠道，且这些渠道排列的顺序固定。
 *
 * 但是请注意，这个默认的行为都是可以修改的。
 *
 * 如果你使用<code>initWithFrame:</code>方法初始化launchpad，那么frame参数将会被忽略。
 *
 * 不推荐使用<code>-[UIView addSubview:]</code>将这个launchpad加入一个父视图。
 * 如果要显示这个launchpad，可以调用<code>showForView:animated:</code>方法。
 */
@interface APSKLaunchpad : UIView

/** The launchpad's delegate. */
@property(nonatomic, weak) id<APSKLaunchpadDelegate> delegate;

/** An array object that contains the names of sharing channels display in the launchpad. */
@property(nonatomic, readonly) NSArray *channels;

/**
 *
 * 根据指定的分享渠道的数组，初始化并返回新创建的<code>APSKLaunchpad</code>类型的对象。
 *
 * @param channels 包含分享渠道名称的数据。这个数组中的无素必须是定义在 @ref APSKChannelNames 中的字符串，否则会忽略该元素。
 * @return 经过初始化的<code>APSKLaunchpad</code>对象。如果初始化失败会返回nil。
 * 各渠道有优先级顺序，分享组件会根据各渠道的优先级进行排序显示，不支持业务方进行渠道显示排序(8.4)；
 */
- (id)initWithChannels:(NSArray *)channels;

/**
 * 根据指定的分享渠道的数组，初始化并返回新创建的<code>APSKLaunchpad</code>类型的对象。
 * 支持业务方自定义是否由分享组件进行排序显示；
 *
 *
 * @param channels 包含分享渠道名称的数据。这个数组中的无素必须是定义在 @ref APSKChannelNames 中的字符串，否则会忽略该元素。
 *  @param needSort YES:分享组件会对channels进行排序，在分享选择面板中显示，同initWithChannels:；
 *     NO：分享组件不会进行排序，按照业务方指定的顺序在分享选择面板中显示。
 *
 *  @return 经过初始化的<code>APSKLaunchpad</code>对象。如果初始化失败会返回nil。
 *
 */
- (id)initWithChannels:(NSArray *)channels sort:(BOOL)needSort;


/**
 *  注册需要被隐藏掉的渠道,某些渠道被屏蔽时，需要隐藏掉。
 *  此API仅供分享组件调用，业务方请勿调用。
 *
 *  @param filteredChannels filteredChannels description
 *
 *
 */
+(void)registerFilteredChannels:(NSArray*)filteredChannels;

/**
 *  注册需要显示Alert的渠道，某些渠道被屏蔽时，需要显示Alert。
 ** 此API仅供分享组件调用，业务方请勿调用。
 *
 *  @param alertedChannels 需要显示alert的业务。
 *
 *
 */
+(void)registerAlertedChannels:(NSArray*)alertedChannels;



/**
 * 在指定的父视图中显示分享的launchpad。
 *
 * @param view 父视图
 * @param animated 指定在显示launachpad时，是否显示动画。如果为YES，
 *  launchpad在显示时，会做一个从上往上推的动画。如果为NO，则不显示动画。
 */
- (void)showForView:(UIView *)view animated:(BOOL)animated;

/**
 * 关闭分享launchpad的显示。
 *
 * @param animated 指定在在launchpad关闭时是否需要显示动画。
 *  如果为YES，launchpad关闭时会默认显示从上往下移动的动画。如果为NO，
 *  则不显示动画。
 */
- (void)dismissAnimated:(BOOL)animated;

@end



//extern NSString * const kAPSKMessageExtraInfoRecipientsKey;

/**
 * This class represents a message for sharing。
 */
@interface APSKMessage : NSObject

/**
 * The type of content to be shared, its can be one of the following values:
 *  - text  indicates this message is used for sharing text.
 *  - image indicates this message is used for sharing an image.
 *  - url   indicates this message is used for sharing a url.(标准LinkCard)
 *  - 微信、来往、QQ的图文加连接的形式使用url
 */
@property(nonatomic, copy) NSString *contentType;

/**
 * 要分享的内容。
 *
 * 这个属性的值依赖于<code>contentType</code>的值。
 *  <table>
 *      <tr>
 *          <td>type</td>
 *          <td>content</td>
 *      </tr>
 *      <tr>
 *          <td>url</td>
 *          <td>
 *              这个属性的值可以是以下类型的对象：
 *
 *              - NSURL
 *
 *          </td>
 *      </tr>
 *      <tr>
 *          <td>image</td>
 *          <td>
 *              这个属性的值可以是以下类型的对象：
 *
 *              - UIImage
 *              - NSURL
 *
 *              如果这个属性的值通过URL指定，它可以是指向本地图片资源的URL，也可以是指向网络上的图片的URL。
 *          </td>
 *      </tr>
 *      <tr>
 *          <td>1001/1002/1003</td>
 *          <td>
 *              这个属性的值可以是以下类型的对象：
 *
 *              - NSURL
 *
 *          </td>
 *      </tr>
 *  </table>
 */

//图文+连接的 卡片形式的分享，目前微信、来往、QQ、微博已支持
@property(nonatomic, strong) id content;

/** 缩略图 */
@property(nonatomic, strong) UIImage *icon;

/** 缩略图url, 目前仅支付宝联系人使用 */
@property(nonatomic, strong) NSURL *iconUrl;

/** 分享标题 */
@property(nonatomic, copy) NSString *title;

/** 分享消息的描述信息 */
@property(nonatomic, copy) NSString *desc;

/** 护展信息
 *  留作以后扩展使用
 *
 */
@property(nonatomic, strong) NSDictionary *extraInfo;

/**
 *  点击多媒体内容之后呼起第三方应用特定页面附加的scheme信息 长度小于255
 */
@property (nonatomic, strong) NSString *scheme;

/**
 * 创建并初始化一个用于分享URL的消息。
 *
 * @param url A NSURL object represents a URL to be shared.
 * @param icon A UIImage object.
 * @param title The message's title.
 * @param description The message's description.
 * @return A <code>APSKMessage</code> object initialized with the specified url.
 */
+ (APSKMessage *)messageWithURL:(NSURL *)url icon:(UIImage *)icon title:(NSString *)title description:(NSString *)description;

/**
 * 根据指定的图片对象，创建并初始化一个用于分享图片的消息。
 *
 * @param image 要分享的图片对象，UIImage类型。
 * @return 新创建并经过初始化的<code>APSKMessage</code>对象。
 */
+ (APSKMessage *)messageWithImage:(UIImage *)image;

/**
 * 根据指定的图片消息，创建并初始化一个用于分享图片的消息。
 *
 * @param imageURL 指向图片的URL对象。如果图片存储于本地，可以使用<code>-[NSURL fileURLWithPath:]</code>将本地路径转换成URL对象。如果图片存储于网络上，分享组件会自动从服务端器上下载指定的URL所指向的图片。
 * @return 新创建并经过初始化的<code>APSKMessage</code>对象。
 */
+ (APSKMessage *)messageWithImageURL:(NSURL *)imageURL;
@end

/**
 * @defgroup APSKClient
 *
 * 分享组件，可以将指定的消息分享到指定的渠道。目前支持的分享渠道可以参见在 @ref APSKChannelNames 中的定义。
 * 目前在分享组件中有如下几个概念：
 *  
 *  - 分享控制面板，由<code>APSKLaunchpad</code>类表示。
 *  - 分享的消息，由<code>APSKMessage</code>类表示。
 *  - 分享组件，由<code>APSKClient</code>表示。
 *
 * 代码示例：
 *
 *  <pre>- (void)shareButtonClicked:(id)sender
 *  {
 *      APSKLaunchpad *launchpad = [[APSKLaunchpad alloc] init];
 *      if (launchpad) {
 *          launchpad.delegate = self;
 *          [launchpad showForView:self.view animated:YES];
 *      }
 *  }</pre>
 *
 *  <pre>- (void)sharingLaunchpad:(APSKLaunchpad *)launchpad didSelectChannel:(NSString *)channelName
 *  {
 *      NSURL *url = [NSURL URLWithString:@"..."];
 *      UIImage *icon = [UIImage imageNamed:@"..."];
 *      APSKMessage *msg = [APSKMessage messageWithURL:url icon:icon title:@"Your title" description:@"Your desc ..."];
 *      APSKClient *shareKit = [[APSKClient alloc] init];
 *      if ([shareKit shareMessage:msg toChannel:channelName error:nil]) {
 *          NSLog(@"分享成功");
 *      }
 *      else {
 *          NSLog(@"分享失败或取消");
 *      }
 *  }</pre>
 *
 * @{
 */

/**
 * 分享组件，可以实现把指定的消息分享到指定的分享渠道。
 *
 * 在分享的过程中，出现以下情况时，分享组件会认为此次分享已取消：
 *  - 已跳转至分享渠道的app且在分享完成前，将分享渠道app压后台或结束进程
 *  - 已跳转至分享渠道的app且在分享完成前，连按HOME键切回调用分享的app
 *
 * 分享组件创建后，如果发起了一个分享的请求，那么这个实例就会一直存在，直到分享结束。
 */

typedef enum _APSKErrorCode
{
    APSKErrorSuccess = 0,           //分享成功
    APSKErrorUserCancel = -1,       //用户取消 (受限于QQ的错误码，分享到QQ拿不到这个状态码，微信、来往、微博可以)
    APSKErrorSendFail = -2,         //发送失败
    APSKErrorAuthDeny = -3,         //授权失败
    APSKErrorAPPUninstall = -4,     //分享APP未安装
    APSKErrorUnsupport = -5,        //不支持的请求
    APSKErrorUnknown = -6          //未知原因
    
}APSKErrorCode;

@interface APSKClient : NSObject
@property(nonatomic, strong) NSMutableDictionary *pluginDict;

//设为YES，禁止分享组件的toast提示，需要在completionBlock中自定义界面显示；
@property(nonatomic, assign) BOOL disableToastDisplay;


/**
 *  注册分享渠道的配置参数，主要是key、secret参数
 *
 *  @return 所要分享渠道的配置词典
 *  词典格式为：@{@"laiwang" : @{@"key" : @"your_key", @"secret" : @"your_secret"},
                @"weixin" : {}, @"weibo" : {}, @"qq" : {}};
 *  qq的key值传入十进制APPID即可；
 */
+(BOOL)registerAPPConfig:(NSDictionary*)configDic;



- (void)registerPluginClass:(Class *)pluginClass forChannel:(NSString *)channelName;
- (void)unregisterPluginForChannel:(NSString *)channelName;

/**
 *  如果接入应用自己进行绑定等操作，APSKClient并不感知，会因为curPlugin未设置而无法处理之后的handleOpenURL。这里强制设定当前的channel
 */
- (void)setActiveChannel:(NSString *)channelName;

/**
 * 获取分享组件的实例。
 * 此方法仅供分享组件自己使用，业务方请勿使用。
 *
 * 分享组件同时不会存在多个实例，但它也不是一个单例类。
 *
 *
 * @return 如果分享组件的实例已存在，则返回该实例，否则返回<code>nil</code>。
 */
//+ (APSKClient *)pickClient;

/**
 * 处理分享渠道app回调的URL。
 *
 * 该方法是留给框架调用，分享调用方不需要关心它。
 *
 * @param aURL 第三方app回调的URL。
 * @return 如果指定的URL是一个分享渠道app回调的URL，返回YES，否则返回NO。
 */
+ (BOOL)handleOpenURL:(NSURL *)aURL;


/**
 * 分享指定的消息到指定的渠道(需先注册key、secret等)。
 *
 * @param message An instance of <code>APSKMessage</code> class.
 * @param channelName The name of the sharing channel.
 * @param error On output, a pointer to an error object. If an error occurs, this pointer
 *  is assigned to an actual error object containing the error information. You can specify the
 *  <code>nil</code> for this parameter if you do not want the error infomation.
 * @param completionBlock 通过block通知业务方结果。
 *          NSError code为APSKErrorCode， 错误提示串Key值为NSLocalizedDescriptionKey。
 *
 */
- (void)shareMessage:(APSKMessage *)message toChannel:(NSString *)channelName completionBlock:(void (^)(NSError *error, NSDictionary *userInfo))completionBlock;


/**
 * 分享指定的消息到指定的渠道,(需先注册key、secret等), 加入业务方标示bizType参数。
 *
 * @param message An instance of <code>APSKMessage</code> class.
 * @param channelName The name of the sharing channel.
 * @param error On output, a pointer to an error object. If an error occurs, this pointer
 *  is assigned to an actual error object containing the error information. You can specify the
 *  <code>nil</code> for this parameter if you do not want the error infomation.
 * @param completionBlock 通过block通知业务方结果。
 *          NSError code为APSKErrorCode， 错误提示串Key值为NSLocalizedDescriptionKey。
 * @param bizType  标示业务类型，埋点时使用，不需要埋业务参数，可以设空；
 *
 *
 */
- (void)shareMessage:(APSKMessage *)message toChannel:(NSString *)channelName completionBlock:(void (^)(NSError *error, NSDictionary *userInfo))completionBlock bizType:(NSString*)bizType;


/**
 * 查询指定的分享渠道的APP是否已安装(需先注册key、secret等)。
 *
 * @param channelName The name of the sharing channel.
 * @return YES if the responsible 3rd APP is installed in the device for the specified sharing channel
 *  returns NO if an error occurred.
 */
+(BOOL)isAppInstalledForChannel:(NSString *)channelName;


/**
 *  查看指定渠道的配置值
 *
 *  @param channel 指定的渠道
 *
 *  @return 指定渠道的配置值
 */
+(NSDictionary*)configForChannel:(NSString*)channel;


/**
 *  查看指定渠道设置过的key值
 *
 *  @param channel 指定的渠道
 *
 *  @return 指定渠道注册过的key值
 */
+(NSString*)keyForChannel:(NSString*)channel;

/**
 *  查看指定渠道设置过的secret值(如有)
 *
 *  @param channel 指定的渠道
 *
 *  @return 指定渠道注册过的secret值
 */
+(NSString*)secretForChannel:(NSString*)channel;


@end

