//
//  MWPhoto.h
//  BeePhotoBrowser
//
//  Created by Michael Waterfall on 17/10/2010.
//  Copyright 2010 d3i. All rights reserved.
//
//  Help Document: http://gitlab.alibaba-inc.com/BeeHive/BeePhotoBrowser/blob/master/APPhoto.md

#import <Foundation/Foundation.h>
#import <AssetsLibrary/AssetsLibrary.h>
#import <Photos/Photos.h>
#import "BEEPhotoProtocol.h"

typedef enum : NSUInteger {
    BEEPhotoSizeTypeThumb,
    BEEPhotoSizeTypeBig,
    BEEPhotoSizeTypeOriginal,
    
    APPhotoSizeTypeThumb    __attribute__((deprecated))  = BEEPhotoSizeTypeThumb,
    APPhotoSizeTypeBig      __attribute__((deprecated))  = BEEPhotoSizeTypeBig,
    APPhotoSizeTypeOriginal __attribute__((deprecated))  = BEEPhotoSizeTypeOriginal,
} BEEPhotoSizeType;

__deprecated_msg("直接使用BEEPhotoSizeType")
typedef BEEPhotoSizeType APPhotoSizeType;

typedef enum : NSUInteger {
    BEEPhotoTypePhoto,
    BEEPhotoTypeVideo,           // 本地相册视频
    BEEPhotoTypeShortVideo,      // 支付宝小视频
    BEEPhotoTypeCloudVideo,      // 支付宝云端大视频
    
    APPhotoTypePhoto        __attribute__((deprecated))  = BEEPhotoTypePhoto,
    APPhotoTypeVideo        __attribute__((deprecated))  = BEEPhotoTypeVideo,
    APPhotoTypeShortVideo   __attribute__((deprecated))  = BEEPhotoTypeShortVideo,
    APPhotoTypeCloudVideo   __attribute__((deprecated))  = BEEPhotoTypeCloudVideo,
} BEEPhotoType;

__deprecated_msg("直接使用BEEPhotoType")
typedef BEEPhotoType APPhotoType;

typedef enum : NSUInteger {
    BEEPhotoErrorCodeUnknow,                                // 默认未知即加载成功
    
    // Gif相关ErrorCode
    BEEPhotoErrorCodeGifFileTooBig      = 0x00F001,         // Gif大小尺寸超限
    BEEPhotoErrorCodeGifSizeOverLimit   = 0x00F002,         // Gif文件尺寸超限
    BEEPhotoErrorCodeGifJustOneFrame    = 0x00F003,         // Gif为单帧静态图
} BEEPhotoErrorCode;

// This class models a photo/image and it's caption
// If you want to handle photos, caching, decompression
// yourself then you can simply ensure your custom data model
// conforms to MWPhotoProtocol
@interface BEEPhoto : NSObject <BEEPhoto, NSCopying>

@property (nonatomic, assign)   BEEPhotoType type;

// 照片资源相关属性
@property (nonatomic, assign)   BOOL loadingInProgress;

// 该属性用于构造对象
@property (nonatomic, strong)   UIImage *image;         // 若需获取BEEPhoto中的Image对象，请访问underlyingImage属性
@property (nonatomic, strong)   NSURL *photoURL;

@property (nonatomic, strong)   ALAsset *asset;
@property (nonatomic, strong)   PHAsset *phAsset;

@property (nonatomic, assign)   BOOL loadAsGif;         // 是否需要作为Gif文件加载，只对图片资源有效，Default = NO
@property (nonatomic, assign)   BOOL enableFadeIn;      // 是否支持弱网下JPG图片渐显 Default = YES 缩略图同时打开有效

@property (nonatomic, assign)   CGRect origFrame;       // 预览图片之前缩略图的位置，用于动画缩放
@property (nonatomic, assign)   CGSize imageSize;       // 大图或原图的尺寸大小，用于控制下载大图或原图
@property (nonatomic, assign)   NSTimeInterval time;    // 时间戳，用于对照片按照时间进行分组
@property (nonatomic, strong)   NSDate *timeDate;       // 时间戳，用于对照片按照时间进行分组
@property (nonatomic, strong)   NSString *caption;

@property (nonatomic, assign)   BEEPhotoSizeType sizeType; // 图片类型
@property (nonatomic, assign)   BEEPhotoSizeType photoType DEPRECATED_MSG_ATTRIBUTE("请使用sizeType替换");

@property (nonatomic, assign)   CGSize          thumbSize;          // 图片类型为缩略图时，需要大小参数
@property (nonatomic, assign)   UIViewContentMode contentMode;      // 图片类型不是缩略图时，需要的ContentMode
@property (nonatomic, assign)   long long originImageTotalBytes;    // 原图总大小(单位：Bytes)

// 视频资源相关数据
@property (nonatomic, copy)     NSString *videoUrlString;           // 小视频的URL
@property (nonatomic, assign)   CGSize    videoDimensions;          // 小视频的尺寸,始终以Portrait方向为基准
@property (nonatomic, copy)     NSString *videoDuration;            // 视频的长度，NSString，仅用于九宫格显示
@property (nonatomic, assign)   NSTimeInterval videoDurationTime;   // 视频长度，NSTimeInterval，以s为单位，用于九宫格显示

@property (nonatomic, copy)     NSString *mmBusinessId;               // 透传给多媒体组件，标识业务Id
@property (nonatomic, copy)     NSString *mmBizType;                  // 透传给多媒体组件，业务标识

// 业务方扩展参数，相册选图业务不需要理解
@property (nonatomic, strong) NSString *extJson;                    // 业务数据，内部不关心
// 保险箱扩展参数，需要透传给多媒体
@property (nonatomic, copy) NSDictionary *extraParams;

/*
 参数(NSURL *)url支持Scheme：

 * http(s)://url
 * alipay-cloud-id://cloudId
 * assets-library://AssetsLibraryPath
 * file://localPath
 */

// New API For APMultimedia
+ (BEEPhoto *)photoWithURL:(NSURL *)url business:(NSString *)business;
+ (BEEPhoto *)photoWithImage:(UIImage *)image business:(NSString *)business;
+ (BEEPhoto *)photoWithAsset:(ALAsset *)asset business:(NSString *)business;
+ (BEEPhoto *)photoWithPHAsset:(PHAsset *)phAsset business:(NSString *)business;


// 构建小视频的APPhoto，videoUrlString不包含前缀"alipay-cloud-id://"或"alipay-local-id://"
+ (BEEPhoto *)photoWithVideoUrl:(NSString *)videoUrl photoType:(BEEPhotoType)photoType business:(NSString *)business;


// New API For APMultimedia
- (id)initWithImage:(UIImage *)image business:(NSString *)business;
- (id)initWithURL:(NSURL *)url business:(NSString *)business;
- (id)initWithAsset:(ALAsset *)asset business:(NSString *)business;
- (id)initWithPHAsset:(PHAsset *)phAsset business:(NSString *)business;

// 构建小视频的APPhoto，videoUrlString不包含前缀"alipay-cloud-id://"或"alipay-local-id://"
- (id)initWithVideoUrl:(NSString *)videoUrl photoType:(BEEPhotoType)photoType business:(NSString *)business;


/**
 *  水印缩略图下载
 *
 *  @param sourceId     水印来源图文件ID
 *  @param position     水印位置，参考以下九宫格方位，[1-9]，默认值：5
 
 *   1左上	2中上	3右上
 *   4左中	5中部	6右中
 *   7左下	8中下	9右下
 
 *  @param transparency 水印来源图透明度，(0,100]，如果设为100则不透明
 *  @param width        水印来源图宽，(0,200]  由于服务端压力 后续该参数会变更为枚举值2个 即指定值如
 *  @param height       水印来源图高，(0,200]
 *  @param xgap         水平边距, 距离图片边缘的水平距离，单位像素， 这个参数只有当水印位置是左上，左中，左下， 右上，右中，右下才有意义，取值范围：[0,4096]
 *  @param ygap         垂直边距, 距离图片边缘的垂直距离，单位像素， 这个参数只有当水印位置是左上，中上， 右上，左下，中下，右下才有意义，取值范围：[0,4096]
*  @param P            对当前水印来源图进行按主图的比例缩放，如10表示基于主图的10%进行处理，比如主图尺寸为1000x1000，则P=10表示把水印来源图缩放成100x100,取值范围(0,100]
 */
- (void)setWaterMark:(NSString *)sourceId
                zoom:(CGSize)zoom
            position:(NSUInteger)position
        transparency:(NSUInteger)transparency
               width:(NSUInteger)width
              height:(NSUInteger)height
                xgap:(NSUInteger)xgap
                ygap:(NSUInteger)ygap
                   p:(NSUInteger)p;

- (void)getDownloadProgress:(void (^)(double progress, BOOL inCloud))block;

- (void)getLocalPhoto;

- (NSString *)cloudId;

- (NSError *)resultError;

- (void)saveToAlbumWithCompletionBlock:(void(^)(NSDictionary *, NSError *))completionBlock;
@end

__deprecated_msg("直接使用BEEPhoto")
@interface APPhoto : BEEPhoto

@end

