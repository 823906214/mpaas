//
//  BEEPhotoBrowser.h
//  BeeHive
//
//  Created by Yanzhi on 15/5/5.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//
//  Help Document: http://gitlab.alibaba-inc.com/BeeHive/BeePhotoBrowser/blob/master/BEEPhotoBrowser.md

#import <Foundation/Foundation.h>
#import <AssetsLibrary/AssetsLibrary.h>

@class BEEPhoto;
@class BEECaptionView;
@class BEEPhotoBrowser;
@class BEEPhotoPreviewWindow;
@class BEEPhotoBrowserController;
@class BEEGridViewController;
@class BEEPhotoActionItem;

#pragma mark - Delegate
@protocol BEEPhotoBrowserDelegate <NSObject>

@required
- (NSUInteger)numberOfPhotosInPhotoBrowser:(BEEPhotoBrowser *)photoBrowser;
- (BEEPhoto *)photoBrowser:(BEEPhotoBrowser *)photoBrowser photoAtIndex:(NSUInteger)index;

@optional

#pragma mark - 缩略图

// 数据源中没有视频
- (BEEPhoto *)photoBrowser:(BEEPhotoBrowser *)photoBrowser thumbPhotoAtIndex:(NSUInteger)index;
// 数据源中包含视频
- (BEEPhoto *)photoBrowser:(BEEPhotoBrowser *)photoBrowser thumbPhotoAtIndex:(NSUInteger)index isVideo:(BOOL *)isVideo;

#pragma mark - 底部描述信息 和 导航栏部分

// 针对每个图片的底部视图，会随着Page滚动
- (BEECaptionView *)photoBrowser:(BEEPhotoBrowser *)photoBrowser captionViewForPhotoAtIndex:(NSUInteger)index;

// 标题
- (NSString *)photoBrowser:(BEEPhotoBrowser *)photoBrowser titleForPhotoAtIndex:(NSUInteger)index;
- (UIView *)photoBrowser:(BEEPhotoBrowser *)photoBrowser titleViewAtIndex:(NSUInteger)index;

// 导航栏
- (NSString *)backButtonTitleForPhotoBrowser:(BEEPhotoBrowser *)photoBrowser;
- (UIView *)rightBarItemCustomViewForPhotoBrowser:(BEEPhotoBrowser *)photoBrowser;
- (void)doActionOnRightBarButtonItemForPhotoBrowser:(BEEPhotoBrowser *)photoBrowser
                                          withPhoto:(BEEPhoto *)photo
                                            atIndex:(NSInteger)index;

#pragma mark - 图片操作

// 图片单击
- (void)photoBrowser:(BEEPhotoBrowser *)photoBrowser singleTapPhotoAtIndex:(NSUInteger)index;

// 图片删除提示
- (NSString *)photoBrowser:(BEEPhotoBrowser *)photoBrowser deleteTipForPhotoAtIndex:(NSUInteger)index;
// 图片删除
- (void)photoBrowser:(BEEPhotoBrowser *)photoBrowser deletePhotoAtIndex:(NSUInteger)index;

// 图片长按弹出的ActionSheet的Item，按照数组顺序进行显示
- (NSArray<BEEPhotoActionItem *> *)photoBrowserActionItemArray:(BEEPhotoBrowser *)photoBrowser;
- (NSArray<BEEPhotoActionItem *> *)photoBrowserActionItemArray:(BEEPhotoBrowser *)photoBrowser
                                                    photoIndex:(NSUInteger)photoIndex;

// 长按事件响应
- (void)photoBrowser:(BEEPhotoBrowser *)photoBrowser doActionAtIndex:(NSInteger)index
               title:(NSString *)title photoIndex:(NSInteger)photoIndex;

// ScrollView动作通知
- (void)photoBrowser:(BEEPhotoBrowser *)photoBrowser willChangeFromIndex:(NSUInteger)index;
- (void)photoBrowser:(BEEPhotoBrowser *)photoBrowser didChangeToIndex:(NSUInteger)index;

// 图片长按Item的标题，内部会根据其他参数增加“保存图片”、“扫描二维码功能”
- (NSArray<NSString *> *)photoBrowserActionTitleArray:(BEEPhotoBrowser *)photoBrowser DEPRECATED_MSG_ATTRIBUTE("Replaced by 'photoBrowserActionItemArray:'");
// 长按事件响应
- (void)photoBrowser:(BEEPhotoBrowser *)photoBrowser doActionAtIndex:(NSUInteger)index photoIndex:(NSUInteger)photoIndex DEPRECATED_MSG_ATTRIBUTE("Replace by 'photoBrowser:doActionAtIndex:title:photoIndex:'");

#pragma mark - 图片选择

// 最大可选择的图片数量
- (NSUInteger)maxNumberOfSelectPhotosInPhotoBrowser:(BEEPhotoBrowser *)photoBrowser;

// 获取当前已选中的图片总数
- (NSUInteger)numberOfSelectedPhotosInPhotoBrowser:(BEEPhotoBrowser *)photoBrowser;

// 判断图片是否被选中
- (BOOL)photoBrowser:(BEEPhotoBrowser *)photoBrowser isPhotoSelectedAtIndex:(NSUInteger)index;

// 获取已选中的所有图片
- (NSArray *)selectedPhotosInPhotoBrowser:(BEEPhotoBrowser *)photoBrowser;

// 询问是否允许改变
- (BOOL)shouldChangePhotoBrowser:(BEEPhotoBrowser *)photoBrowser photoSelected:(BOOL)selected atIndex:(NSUInteger)index;

// 图片选中状态改变
- (void)photoBrowser:(BEEPhotoBrowser *)photoBrowser photoAtIndex:(NSUInteger)index selectedChanged:(BOOL)selected;

// 是否需要选择原图
- (BOOL)photoBrowserNeedOriginPhoto:(BEEPhotoBrowser *)photoBrowser;

// 选中原图状态发生变更
- (void)photoBrowserNeedOriginPhotoChanged:(BEEPhotoBrowser *)photoBrowser;

// 图片选择，加载指定ALAsset资源
- (void)photoBrowser:(BEEPhotoBrowser *)photoBrowser loadAsset:(NSUInteger)index completion:(void(^)(ALAsset *asset))completion;

// 图片确认选择按钮显示文案
- (NSString *)photoBrowserConfirmButtonTitle:(BEEPhotoBrowser *)photoBrowser;

// 完成图片选择
- (void)photoBrowserDidFinishSelectPhoto:(BEEPhotoBrowser *)photoBrowser;

#pragma mark - 涂鸦

// 是否允许涂鸦
- (BOOL)photoBrowser:(BEEPhotoBrowser *)photoBrowser shouldEnableDoodlePhotoAtIndex:(NSUInteger)index;

// 启动涂鸦
- (void)photoBrowser:(BEEPhotoBrowser *)photoBrowser startDoodlePhotoAtIndex:(NSUInteger)index;

#pragma mark - 图片编辑
// 是否允许视频编辑
- (BOOL)photoBrowser:(BEEPhotoBrowser *)photoBrowser enablePhotoEdit:(BEEPhoto *)photo atIndex:(NSUInteger)index;

// 启动视频编辑
- (void)photoBrowser:(BEEPhotoBrowser *)photoBrowser startEditPhoto:(BEEPhoto *)photo atIndex:(NSUInteger)index;

#pragma mark - 视频控制
// 是否允许视频编辑
- (BOOL)photoBrowser:(BEEPhotoBrowser *)photoBrowser enableVideoEditAtIndex:(NSUInteger)index;

// 启动视频编辑
- (void)photoBrowser:(BEEPhotoBrowser *)photoBrowser startEditVideoAtIndex:(NSUInteger)index;

// 视频剪辑后最大时长 默认10s
- (NSTimeInterval)photoBrowser:(BEEPhotoBrowser *)photoBrowser maximumVideoDurationAtIndex:(NSUInteger)index;

// 预览小视频时，是否显示“轻触退出”功能，收藏界面和生活圈个人详情页播放小视频逻辑不一样
- (BOOL)enableShowTapToExitViewForShortVideo:(BEEPhotoBrowser *)photoBrowser;

// 播放视频时是否静音，默认不静音，返回YES则置为静音 
- (BOOL)enableMutedForShortVideo:(BEEPhotoBrowser *)photoBrowser;

// 在非Wifi网络下，是否自动播放视频
- (BOOL)autoPlayOnlineVideoOnWWLAN:(BEEPhotoBrowser *)photoBrowser;

// 视频是否允许自动重播
- (BOOL)canVideoAutoReplay:(BEEPhotoBrowser *)photoBrowser atIndex:(NSUInteger)index;

//视频开始播放
- (void)photoBrowser:(BEEPhotoBrowser *)photoBrowser videoStartPlayAtIndex:(NSUInteger)index;

//视频暂停播放
- (void)photoBrowser:(BEEPhotoBrowser *)photoBrowser videoPausePlayAtIndex:(NSUInteger)index;

//视频停止播放
- (void)photoBrowser:(BEEPhotoBrowser *)photoBrowser videoStopPlayAtIndex:(NSUInteger)index;

//视频播放结束
- (void)photoBrowser:(BEEPhotoBrowser *)photoBrowser videoFinishPlayAtIndex:(NSUInteger)index;

//视频取消播放
- (void)photoBrowser:(BEEPhotoBrowser *)photoBrowser videoCancelPlayAtIndex:(NSUInteger)index;

#pragma mark - 即将预览

- (void)willAppearPhotoBrowser:(BEEPhotoBrowser *)photoBrowser;

#pragma mark - 退出预览

// 用作缩放动画的图片，聊天场景和服务窗中需实现
- (UIImage *)imageForZoomAnimationInPhotoBrowser:(BEEPhotoBrowser *)photoBrowser atIndex:(NSInteger)index;

// 如果其他业务的缩略图图片位置发生变化，则在此更新缩略图的Frame，
// 注意：该方法将在全屏预览退出的时候才进行调用
- (CGRect)changedOrigFrameInPhotoBrowser:(BEEPhotoBrowser *)photoBrowser atIndex:(NSInteger)index;

// 图片预览将要退出
- (void)willDismissPhotoBrowser:(BEEPhotoBrowser *)photoBrowser isSnapChat:(BOOL)isSnapChat atIndex:(NSInteger)index;
// 图片预览已经退出
- (void)didDismissPhotoBrowser:(BEEPhotoBrowser *)photoBrowser;
- (void)didDismissPhotoBrowser:(BEEPhotoBrowser *)photoBrowser isSnapChat:(BOOL)isSnapChat atIndex:(NSInteger)index;
- (BOOL)shouldCancelAllDownloadingWhenDismissPhotoBrowser:(BEEPhotoBrowser *)photoBrowser;

#pragma mark - 是否支持旋转
// 默认不支持图片旋转
- (BOOL)enableSupportOrientationChanged:(BEEPhotoBrowser *)photoBrowser;

#pragma mark - 社交聊天
// 区分是接收方还是发送方的消息
- (BOOL)isReceivedMessageAtIndex:(NSInteger)index;

#pragma mark - 阅后即焚

// 阅后即焚倒计时总时间
- (NSTimeInterval)snapChatTotalTime;
// 阅后即焚视频开始播放
- (void)snapVideoDidStartPlay;
// 阅后即焚视频结束播放
- (void)snapVideoDidEndPlay;
// 区分是接收方还是发送方的消息
- (BOOL)isReceivedSnapChatMessage DEPRECATED_MSG_ATTRIBUTE("Replace by 'isReceivedMessageAtIndex:'");
// 大图片已经显示
- (void)snapChatImageDidShow;

@end

__deprecated_msg("直接使用BEEPhotoBrowserDelegate")
@protocol WWPhotoBrowserDelegate <BEEPhotoBrowserDelegate>

@end


#pragma mark - API
@interface BEEPhotoBrowser : NSObject

@property (nonatomic, weak)   id<BEEPhotoBrowserDelegate> delegate;
@property (nonatomic, strong) BEEPhotoPreviewWindow     *previewWindow;
@property (nonatomic, strong) BEEPhotoBrowserController *browserController;
@property (nonatomic, strong) BEEGridViewController     *gridController;
@property (nonatomic, weak)   DTNavigationController    *fromNaviVC;            // 当业务方的ViewController被present出来时需要此参数

@property (nonatomic, assign) BOOL startByAppId;        // 是否通过AppId启动，是则需要退出当前应用

+ (BEEPhotoBrowser *)sharedBrowser;

/**
 * @desc 释放资源
 */
- (void)releasePhotoBrowswer;

/**
 * @desc 重新加载数据
 */
- (void)reloadData;

/**
 * @desc 阅后即焚，设置倒计时时间
 */
- (void)setSnapChatLeftTime:(NSTimeInterval)leftTime;

/**
 * @desc 视频播放控制
 */
- (void)startPlayVideo;
- (void)pausePlayVideo;
- (void)stopPlayVideo;


// 初始化方法

/**
 * @desc 创建一个图片大图预览的BrowserController，需要自己配置属性
 * @return BEEPhotoBrowserController
 */
- (BEEPhotoBrowserController *)createPhotoBrowserControllerWithIndex:(NSUInteger)index
                                                            delegate:(id <BEEPhotoBrowserDelegate>)delegate;
@end

#pragma mark - ShowByScene

@interface BEEPhotoBrowser(ShowByScene)
/**
 * @desc 聊天
 */
+ (void)showPhotoBrowserInChatSceneWithIndex:(NSUInteger)index delegate:(id <BEEPhotoBrowserDelegate>)delegate;

/**
 * @desc 阅后即焚
 */
+ (void)showPhotoBrowserInSnapChatSceneWithIndex:(NSUInteger)index delegate:(id <BEEPhotoBrowserDelegate>)delegate;

/**
 * @desc 私信
 */
+ (void)showPhotoBrowserInPrivateChatSceneWithIndex:(NSUInteger)index delegate:(id <BEEPhotoBrowserDelegate>)delegate;

/**
 * @desc 群设置聊天图片下初始化图片预览
 */
+ (void)showPhotoBrowserInGroupSettingSceneWithIndex:(NSUInteger)index delegate:(id <BEEPhotoBrowserDelegate>)delegate;

/**
 * @desc 生活圈首页查看朋友图片
 */
+ (void)showPhotoBrowserInTimeLineSceneShowOthersWithIndex:(NSUInteger)index delegate:(id <BEEPhotoBrowserDelegate>)delegate;

/**
 * @desc 发布生活圈时，编辑界面图片预览
 */
+ (void)showPhotoBrowserInTimeLineSceneEditPreviewWithIndex:(NSUInteger)index delegate:(id <BEEPhotoBrowserDelegate>)delegate;

/**
 * @desc 查看商户评论时，初始化图片预览
 */
+ (void)showPhotoBrowserInSellerCommentSceneWithIndex:(NSUInteger)index delegate:(id<BEEPhotoBrowserDelegate>)delegate;

/**
 * @desc 发表商户评论时，初始化图片预览
 */
+ (void)showPhotoBrowserInPublishSellerCommentSceneWithIndex:(NSUInteger)index delegate:(id<BEEPhotoBrowserDelegate>)delegate;

/**
 * @desc 商家相册场景下，初始化图片预览
 */
+ (void)showPhotoBrowserInSellerPhotoAlbumSceneWithIndex:(NSUInteger)index delegate:(id<BEEPhotoBrowserDelegate>)delegate;

/**
 * @desc 服务窗场景下，初始化图片预览
 */
+ (void)showPhotoBrowserInPublicPlatformSceneWithIndex:(NSUInteger)index delegate:(id<BEEPhotoBrowserDelegate>)delegate;

/**
 * @desc 收藏业务下，初始化图片预览
 */
+ (void)showPhotoBrowserInFavoriteSceneWithIndex:(NSUInteger)index delegate:(id <BEEPhotoBrowserDelegate>)delegate;

/**
 * @desc 红包福卡，初始化图片预览
 */
+ (void)showPhotoBrowserInRedPacket:(NSUInteger)index delegate:(id <BEEPhotoBrowserDelegate>)delegate;

/**
 * @desc 通用场景，个性化设置可在ConfigBlock里设置
 */
+ (void)showPhotoBrowserWithConfigBlock:(void(^)(BEEPhotoBrowserController *browserVC))block index:(NSUInteger)index delegate :(id <BEEPhotoBrowserDelegate>)delegate;

/**
 * @desc startApp方式启动图片浏览
 */
- (void)showPhotoBrowserInH5WithOption:(NSDictionary *)options index:(NSUInteger)index
                              delegate:(id <BEEPhotoBrowserDelegate>)delegate;

/**
 * @desc 选择图片时，初始化图片预览
 */
- (void)showPhotoBrowserControllerInPickPhotoSceneWithIndex:(NSUInteger)index hideOriginPhoto:(BOOL)hideOriginPhoto
                                                   delegate:(id <BEEPhotoBrowserDelegate>)delegate;

/**
 * @desc 预览本地相册视频
 */
- (void)showPhotoBrowserControllerInPreviewVideoSceneWithdelegate:(id <BEEPhotoBrowserDelegate>)delegate;

@end

__deprecated_msg("直接使用BEEPhotoBrowser")
@interface WWPhotoBrowser : BEEPhotoBrowser

@end

