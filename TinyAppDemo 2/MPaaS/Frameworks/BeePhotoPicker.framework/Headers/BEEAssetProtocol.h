//
#import <Foundation/Foundation.h>
#import "BEEAssetCommon.h"

#define TICK   NSDate *startTime = [NSDate date]
#define TOCK   NSLog(@"%s Time: %f", __func__, -[startTime timeIntervalSinceNow])

@protocol BEEAssetProtocol <NSObject>

/** @desc Asset的Key值，兼容iOS7/iOS8 */
- (NSString *)bee_assetKey;

/** @desc 服务端的图片资源返回原始url，本地相册的图片返回nil */
- (NSURL *)bee_assetUrl;

/** @desc 资源类型 */
- (BEEAssetMediaType)bee_mediaType;

/** @desc 资源宽度 <br>
 * 如果仅仅需要获取宽高比，请直接使用接口'aspectRatio'，效率会更高
 */
- (NSUInteger)bee_pixelWidth;

/** @desc 资源高度 <br>
 * 如果仅仅需要获取宽高比，请直接使用接口'aspectRatio'，效率会更高
 */
- (NSUInteger)bee_pixelHeight;

/** @desc 图片宽高比 */
- (CGFloat)bee_aspectRatio;

/** @desc 资源创建时间 */
- (NSDate *)bee_creationDate;

///** @desc 资源地理位置 */
//- (CLLocation *)bee_location;

/** @desc 资源时间长度 */
- (NSTimeInterval)bee_duration;

/** @desc 是否iCloud上 */
- (BOOL)bee_isAssetInCloud;

/** @desc 是否是Gif图片 */
- (BOOL)bee_isGif;

///** @desc 资源方向 iCloud图片返回方向无效 */
//- (UIImageOrientation)bee_orientation;

/** @desc asset文件大小，iCloud图片返回方向无效 */
-(long long)bee_size;

/** @desc 异步获取图片。
 *  <br>For iOS7, the block progress will never be used.
 */
- (BEEImageRequestID)bee_getAssetImageWithSizeType:(BEEAssetSizeType)sizeType
                                          progress:(BEEAssetImageProgressHandler)progress
                                        completion:(void (^)(UIImage *image, BOOL cancelled, BOOL isDegraded))completion;

/** @desc 同步获取图片。 */
- (UIImage *)bee_syncGetAssetImageWithSizeType:(BEEAssetSizeType)sizeType;

/** @desc 判断是否有本地图片：无数据立即返回，不触发网络请求 */
- (BOOL)bee_hasAssetImageWithSizeType:(BEEAssetSizeType)sizeType;

/** @desc 异步获取Gif文件数据。
 *  <br>For iOS7, the block progress will never be used.
 */
- (BEEImageRequestID)bee_getAssetGifWithProgress:(BEEAssetImageProgressHandler)progress
                                      completion:(BEEAssetDataCompletionHandler)completion;

/** @desc 同步获取Gif文件数据。 */
- (NSData *)bee_syncGetAssetGif;

/** @desc 异步获取视频 */
- (BEEImageRequestID)bee_getAssetVideoWithProgress:(void (^)(CGFloat progress))progress
                                        completion:(void (^)(AVAsset *video))completion;

/**
 * @desc 取消Asset资源加载请求(包含图片、Gif、视频等)
 */
- (void)bee_cancelGetAssetImage:(BEEImageRequestID)requestID;

///** @desc 从系统相册中删除asset */
//- (void)bee_deleteFromSystemAlbum:(void (^)(BOOL success, NSError *error))completion;

@end
