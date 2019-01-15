//
//  APPhotoBrowser.h
//  BeePhotoBrowser
//
//  Created by Michael Waterfall on 14/10/2010.
//  Copyright 2010 d3i. All rights reserved.
//
//  Help Document: http://gitlab.alibaba-inc.com/BeeHive/BeePhotoBrowser/blob/master/APPhotoBrowserController.md

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>
#import <APMultimedia/APAudioSessionManager.h>
#import "BEECaptionView.h"
#import <BeeMediaPlayer/BeeVideoPlayerView.h>

#import "BEEPhoto.h"
#import "BEEPhotoProtocol.h"

@class BEEPhotoBrowser;
@class BEEPhotoBrowserController;
@class BEEGridViewController;

typedef enum : NSUInteger {
    PhotoBrowserAnimationZoom,
    PhotoBrowserAnimationPush,
    PhotoBrowserAnimationPresent,
    PhotoBrowserAnimationNone,
} PhotoBrowserAnimation;

@protocol BEEPhotoBrowserControllerDismissDelegate <NSObject>

@optional
- (void)willDismissPhotoBrowserController:(BEEPhotoBrowserController *)photoBrowser
                               isSnapChat:(BOOL)isSnapChat atIndex:(NSInteger)index;
- (void)didDismissPhotoBrowserController:(BEEPhotoBrowserController *)photoBrowser
                              isSnapChat:(BOOL)isSnapChat atIndex:(NSInteger)index;
// 返回图片，用作缩放动画的图片
- (UIImage *)imageForZoomAnimation:(BEEPhotoBrowserController *)photoBrowser atIndex:(NSInteger)index;
// 缩放时获取更新后的图片origFrame
- (BOOL)getChangedOrigFrame:(CGRect *)origFrame atIndex:(NSInteger)index;

@end


@interface BEEPhotoBrowserController : DTViewController <UIScrollViewDelegate,
UIActionSheetDelegate, MFMailComposeViewControllerDelegate, APAudioSessionManagerDelegate>

@property (nonatomic, weak) BEEPhotoBrowser *browser;
@property (nonatomic, weak) id<BEEPhotoBrowserControllerDismissDelegate> dismissDelegate;

@property (nonatomic, strong, readonly) UIScrollView *pagingScrollView;

// 选择图片
@property (nonatomic, assign) BOOL enablePickPhoto;                 // 是否可以选择图片
@property (nonatomic, assign) BOOL enablePickOriginPhoto;           // 是否可以选择原图
@property (nonatomic, assign) BOOL hideCountNumberLabel;            // 是否隐藏选中计数Label
@property (nonatomic, assign) BOOL enableDoodle;                    // 是否允许涂鸦
@property (nonatomic, assign) BOOL enableEditPhoto;                 // 是否允许编辑 与涂鸦功能互斥

// 网格入口
@property (nonatomic, assign) BOOL enableGridView;                  // 是否显示网格视图入口
@property (nonatomic, assign) BOOL enableDownOriginPhoto;           // 是否可以查看原图

// 删除图片
@property (nonatomic, assign) BOOL enableDeletePhoto;               // 是否可以删除图片

// 标题
@property (nonatomic, assign) BOOL enableTitle;                     // 是否显示标题
@property (nonatomic, assign) BOOL enableCaptionView;               // 是否显示描述说明
@property (nonatomic, assign) BOOL enablePageControll;              // 是否显示底部的翻页控件

// 手势控制
@property (nonatomic, assign) BOOL enableSingleTapToDismiss;        // 是否允许单击图片消失
@property (nonatomic, assign) BOOL enableLongPress;                 // 是否允许长按图片
@property (nonatomic, assign) BOOL enableSavePhotoAction;           // 是否允许保存图片
@property (nonatomic, assign) BOOL enableScanQRCodeAction;          // 是否允许识别图片中的二维码

@property (nonatomic, assign) BOOL hiChatMode;                      // 聊天会话模式
@property (nonatomic, assign) BOOL snapChatMode;                    // 是否阅后即焚模式

// 首次出现的动画效果
@property (nonatomic, assign) PhotoBrowserAnimation showAnimation;  // 首次出现时使用的动画

@property (nonatomic, assign) BOOL showNavigationView;              // 是否显示自定义导航栏 默认显示
@property (nonatomic, assign) BOOL showBottomToolView;              // 是否显示底部工具栏

@property (nonatomic, assign) BOOL enableSysNaviController;         // 使用系统导航栏 默认使用自定义导航栏

@property (nonatomic, assign) BOOL autoHideControlView;             // 点击是否自动隐藏导航和工具条 Default YES
@property (nonatomic, assign) BOOL hideControlViewWhenBeginScroll;  // 滚动是否自动隐藏导航栏和工具栏 Default NO

@property (nonatomic, assign, readonly) NSUInteger currentIndex;    // 当前图片的索引值
@property (nonatomic, assign, readonly) NSUInteger initIndex;       // 初始化图片预览组件的起始索引值

@property (nonatomic, assign) BOOL allVideoDoPlayWhenDownloading;   // 所有视频走边下边播逻辑，default is NO
//===以下属性只对类型为BEEPhotoTypeCloudVideo的视频起作用===
@property (nonatomic, assign) BOOL enableVideoFullScreen;           // 视频播放是否铺满全屏，default is NO
@property (nonatomic, assign) BeeVideoBarShowMode videoTopBarShowMode;                 // 视频顶部Bar显示模式
@property (nonatomic, assign) BeeVideoBarShowMode videoToolBarShowMode;              // 视频底部播放Bar显示模式
//====================================================

- (id)initWithInitIndex:(NSUInteger)initIndex;

- (void)dismiss;
- (void)dismissWithAnimation:(BOOL)animation duration:(CGFloat)duration;

// Reloads the photo browser and refetches data
- (void)reloadData;
- (void)reloadDataWithCurrentIndex:(NSUInteger)index reloadPhotoManager:(BOOL)enable;

// Set page that photo browser starts on
- (void)setCurrentPhotoIndex:(NSUInteger)index;

// 显示图片的更多选项，就是图片的长按操作
- (void)showMoreAction;

// Scroll To the photo At index with animation
- (BEEGridViewController *)gridController;

- (NSUInteger)maxSelectPhotoCount;
- (NSUInteger)numberOfSelectedPhotos;

// 当前预览图片，所见即所得
- (UIImage *)imageCurrentShowedOnScreen;
- (UIImage *)imageForPhoto:(id<BEEPhoto>)photo;

- (BOOL)photoIsSelectedAtIndex:(NSUInteger)index;

- (void)setPhotoSelected:(BOOL)selected atIndex:(NSUInteger)index;
- (void)setSnapChatImageLeftTime:(NSTimeInterval)leftTime;

- (void)prepareDismissVC;
@end
