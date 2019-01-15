//
//  BEEPhotoPicker.h
//  BEEPhotoPicker
//
//  Created by Yanzhi on 15/4/19.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//
//  Help Document: http://gitlab.alibaba-inc.com/BeeHive/BeePhotoPicker/blob/master/APPhotoPickerLoader.md

#import <UIKit/UIKit.h>
//#import <BEEPhotoPicker/BEEAssetProtocol.h>
#import "BEEAssetProtocol.h"

//
#define kButtonTitleCamera __TEXT(@"BeePhotoPicker", @"BeePhotoPicker:拍摄", @"拍摄")
#define kButtonTitleAssets __TEXT(@"BeePhotoPicker", @"BeePhotoPicker:从相册选择", @"从相册选择")

@class BEEAssetData;
@class AUActionSheet;

typedef enum : NSUInteger {
    BEEPhotoPickerSceneCamera = 1,
    BEEPhotoPickerSceneAssets = 1 << 1,
    BEEPhotoPickerSceneQuickAssets = 1 << 2,
    BEEPhotoPickerSceneDirectPreview = 1 << 3,
    BEEPhotoPickerSceneRemote = 1 << 4,
} BEEPhotoPickerScene;

// 定义选择图片的错误码
typedef enum : NSUInteger {
    BEEPhotoPickerErrorSuccess,                  // 成功
    BEEPhotoPickerErrorCameraNoAccess,           // 获取相机授权失败
    BEEPhotoPickerErrorCameraNotSupport,         // 该设备不支持相机
    BEEPhotoPickerErrorAssetLibraryNoAccess,     // 获取相册授权失败
    BEEPhotoPickerErrorAssetLibraryNoPhotos,     // 相册中没有照片
} BEEPhotoPickerError;



//
@protocol BEEPhotoPickerDelegate <NSObject>
@optional

/**
 * @desc 选择照片时，选择或者取消选择图片后回调
 * @param asset the asset be selected or deselected
 */
- (void)photoPickerController:(id)picker didPickAssets:(NSArray<id<BEEAssetProtocol>> *)assets;
- (void)photoPickerController:(id)picker didUnpickAssets:(NSArray<id<BEEAssetProtocol>> *)assets;

/**
 * @desc 拍照、涂鸦或者美颜完成之后的回调，此时选择照片的ViewController尚未Dismiss；当采用预选取模式时，则picker为nil。
 * 拍照或者支持涂鸦、美颜时，必须实现该接口接收返回数据；
 * @param photos NSArray of BEEAssetData
 */
- (void)photoPickerController:(id)picker didFinishPickingAssetData:(NSArray<BEEAssetData *> *)data;

/**
 * @desc 选择照片完成之后的回调，此时选择照片的ViewController尚未Dismiss；当采用预选取模式时，则picker为nil。
 * 仅从相册选取照片，实现该接口。
 * @param assets NSArray of id<BEEAssetProtocol>
 * @param theOriginal BOOL, Pick the Original Photo
 */
- (void)photoPickerController:(id)picker didFinishPickingAssets:(NSArray<id<BEEAssetProtocol>> *)assets theOriginal:(BOOL)theOriginal;

/**
 * @desc 选择照片完成之后的回调，此时选择照片的ViewController尚未Dismiss；当采用预选取模式时，则picker为nil。
 * 仅从相册选取照片，实现该接口。
 * @param source 选取的图片或视频的来源：快速、相册、拍摄
 * @param assets NSArray of id<BEEAssetProtocol>
 * @param theOriginal BOOL, Pick the Original Photo
 */
- (void)photoPickerController:(id)picker didFinishPickingAssets:(NSArray<id<BEEAssetProtocol>> *)assets
                  theOriginal:(BOOL)theOriginal source:(BEEPhotoPickerScene)source;

/**
 * @desc 业务方需要在后台压缩图片过程时一起处理其他逻辑，实现这个方法。
 *
 * 注意：在非主线程中调用
 *
 * @param assets 选中的id<BEEAssetProtocol>数组
 * @param data NSArray Of BEEAssetData
 *
 * @return
 */
- (void)photoPickerController:(id)picker processingAssets:(NSArray<id<BEEAssetProtocol>> *)assets data:(NSArray<BEEAssetData *> *)data;

/**
 * @desc 取消选择照片
 * @param error 取消选择照片的错误类型，参见<BEEPhotoPickerError>
 */
- (void)photoPickerControllerWillCancel:(id)picker withError:(BEEPhotoPickerError)error;
- (void)photoPickerControllerDidCancel:(id)picker withError:(BEEPhotoPickerError)error;

/**
 * @desc 照片选择完成，选择照片的VC即将Dismiss
 */
- (void)photoPickerControllerWillDismiss:(id)picker;

/**
 * @desc 照片选择完成，并且选择照片的ViewController已经Dismiss
 */
- (void)photoPickerControllerDidFinish:(id)picker;
- (void)photoPickerControllerDidFinish:(id)picker assets:(NSArray<id<BEEAssetProtocol>> *)assets;

/**
// * @desc 压缩操作相关的回调：如果实现了start协议，并且返回YES，将执行组件封装的压缩操作，如果返回NO，将不执行组件的压缩操作，由业务方自己实现压缩操作；压缩完成时将回调endCompressWithVideo
// */
//- (BOOL)photoPickerController:(id)picker startCompressVideo:(id<BEEAssetProtocol>)videoAsset orData:(BEEAssetData *)data;
//- (void)photoPickerController:(id)picker endCompressWithVideo:(BEEAssetData *)videoInfo orError:(NSError *)error;

@end



//
@interface BEEPhotoPicker : NSObject
@property (nonatomic, assign) BOOL justPickVideo;                       // 是否只要选择视频,Default NO.不支持快速选择
@property (nonatomic, assign) BOOL enablePickGif;                       // 是否支持选择Gif图片,Default NO.Gif作为静态图使用
@property (nonatomic, assign) BOOL enablePickVideo;                     // 是否支持选择视频,Default NO.
@property (nonatomic, assign) BOOL enableQuickPick;                     // 是否可快速选择 Default YES
@property (nonatomic, assign) BOOL enablePhotoPreview;                  // 是否允许图片预览 Default YES
@property (nonatomic, assign) BOOL enableSelectButton;                  // 是否显示选择CheckButton Default YES
@property (nonatomic, assign) BOOL enableSerialNumber;                  // 是否显示选择序号 Default NO
@property (nonatomic, assign) BOOL enableOriginPhotoForSelectOne;       // 发送单张图片时，是否需要原图 Default NO
@property (nonatomic, assign) BOOL enableEditingToCamera;               // 拍照时，是否可以编辑照片 Default NO
@property (nonatomic, assign) BOOL enterGridViewFirst;                  // 从相册选择时，使用先进入相册列表，default=NO
@property (nonatomic, assign) BOOL enableSysNaviInPreview;              // 预览时是否使用系统导航栏，default=NO
@property (nonatomic, assign) BOOL enableBottomViewInPreview;           // 预览时是否显示底部的选择按钮 Default NO
@property (nonatomic, assign) BOOL hidePickOriginControl;               // 隐藏选择原图的控件 Default NO
@property (nonatomic, assign) BOOL pickOriginChecked;                   // 选择原图控件是否选中，Default NO
@property (nonatomic, assign) BOOL hideProcessingIndicator;             // 隐藏处理图片时的菊花 Default NO
@property (nonatomic, assign) BOOL useFrontCamera;                      // 使用相机拍照时，是否默认是否前置摄像头 Default NO
@property (nonatomic, assign) BOOL fixOrientation;                      // 自动修正照片方向 Default YES
@property (nonatomic, assign) BOOL noAnimationForDismissAssetPicker;    // 隐藏从相册选图界面时，是否使用动画 Default NO
@property (nonatomic, assign) BOOL enableTapAssetToSend;                // 选择一张图片时，单击图片则发送 Default YES
@property (nonatomic, assign) BOOL enableDoodle;                        // 是否允许涂鸦，default=NO
@property (nonatomic, assign) BOOL enablePickAssetInCloud;              // 是否支持iCloud图片(未同步到本地)选择，default=YES
@property (nonatomic, assign) BOOL shouldSyncAssetInCloud;              // 是否需要下载iCloud图片，default=NO
@property (nonatomic, assign) BOOL saveToAlbum;                         // 是否保存到相册 默认保存 拍照模式设置有效
@property (nonatomic, assign) CGFloat beautyLevel;                      // 美颜级别选项（0~1），0-不美颜
@property (nonatomic, strong) NSString *confirmButtonTitle;             // 确定按钮的标题
@property (nonatomic, strong) NSArray *previewAssetArray;               // 直接预览选择图片时带入数据源 NSArray Of PHAsset/ALAsset
@property (nonatomic, strong) NSArray<NSString *> *selectedAssetKeys;   // 设置需要被预先选中的照片，请优先设置MaximumSelected

@property (nonatomic, assign) BOOL enableEditVideo;                     // 是否支持选择视频剪辑,Default 10s. 
@property (nonatomic, assign) CGFloat maximumVideoLength;               // 视频剪辑后最大时长,Default 10s. 开启编辑生效
@property (nonatomic, assign) CGFloat minimumVideoLength;               // 视频剪辑后最大时长,Default 1s. 开启编辑生效

@property (nonatomic, copy) NSString *remoteActionTitle;                // 从服务端选图片时，需要设置，如果不设置，actionsheet将不展示服务端选图的item
@property (nonatomic, copy) NSArray *remoteSources;                     // 服务端图片源

+ (BEEPhotoPicker *)sharedPicker;

/** @desc 设置最大可选图片数量 Default=9 */
- (void)setMaximumSelected:(NSUInteger)count;

/** @desc 隐藏“正在处理...”菊花 */
- (void)setProcessingIndicatorHidden;

/**
 * @Description 显示图片选择控件。当scene只有一个场景时，直接显示拍照（或相册）视图；当scene有两个或以上场景时，使用UIActionSheet弹出选择窗口
 * 支持iPhone和iPad
 */
- (void)showPhotoPickerFromRect:(CGRect)frame
                      withScene:(BEEPhotoPickerScene)scene
                       delegate:(id)delegate;

/**
 * @Description 显示图片选择控件。当scene只有一个场景时，直接显示拍照（或相册）视图；当scene有两个或以上场景时，使用UIActionSheet弹出选择窗口
 * 支持iPhone和iPad
 *
 * @param viewcontroller 将图片选择界面显示在该ViewController上，当业务界面是被present出来的界面，请使用该接口
 */
- (void)showPhotoPickerFromRect:(CGRect)frame
               inViewController:(UIViewController *)viewcontroller
                      withScene:(BEEPhotoPickerScene)scene
                       delegate:(id)delegate;

/**
 * @Description 显示图片选择控件。当scene只有一个场景时，直接显示拍照（或相册）视图；当scene有两个或以上场景时，使用UIActionSheet弹出选择窗口。
 * 支持iPhone和iPad。
 * @param autoDismiss 图片选择完成之后是否自动消失。YES，不能调用dismissPhotoPickerAfterPicking；NO，需要手动调用dismissPhotoPickerAfterPicking。
 */
- (void)showPhotoPickerFromRect:(CGRect)frame
                      withScene:(BEEPhotoPickerScene)scene
                    manuDismiss:(BOOL)manuDismiss
                       delegate:(id)delegate;


/** @Desc 初始化一个UIActionSheet选择窗口，由业务方自定义显示方式 */
- (AUActionSheet *)actionSheetWithScene:(BEEPhotoPickerScene)scene delegate:(id)delegate;

/** @desc 业务方主动调用，消失选图界面 */
- (void)dismissPhotoPickerAfterPicking;

/** @desc 选中的Asset资源 */
//- (NSArray *)selectedAssetArray;

@end
