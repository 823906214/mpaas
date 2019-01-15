//
//  BEEAssetCommon.h
//  BeePhotoPicker
//
//  Created by Yanzhi on 15/12/3.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Photos/Photos.h>
#import <AssetsLibrary/AssetsLibrary.h>

/**
 * @desc 定义系统相册中图片的大小类型
 */
typedef enum : NSUInteger {
    BEEAssetSizeTypeThumb,          // 方形缩略图
    BEEAssetSizeTypeAspectThumb,    // 等比缩略图
    BEEAssetSizeTypeFullScreen,     // 等比全屏图
    BEEAssetSizeTypeOriginal        // 原图
} BEEAssetSizeType;

/**
 * @desc 定义系统相册中多媒体资源的图片类型，包括图片、视频中图片
 */
typedef enum : NSUInteger {
    BEEAssetMediaTypeUnknown = PHAssetMediaTypeUnknown,
    BEEAssetMediaTypeImage   = PHAssetMediaTypeImage,
    BEEAssetMediaTypeVideo   = PHAssetMediaTypeVideo,
    BEEAssetMediaTypeAudio   = PHAssetMediaTypeAudio,
} BEEAssetMediaType;

/**
 * @desc 枚举资源时的错误码
 */
typedef enum : NSUInteger {
    BEELoadAssetSuccess = 0,
    BEELoadAssetErrorCollectionKeyNil,
    BEELoadAssetErrorDiffCollection,
    BEELoadAssetErrorIndexInvalid,
} BEELoadAssetErrorCode;

/**
 * @desc 定义相册权限，兼容iOS7/iOS8
 */
typedef enum : NSUInteger {
    BEEAuthorizationStatusNotDetermined = ALAuthorizationStatusNotDetermined,
    BEEAuthorizationStatusRestricted = ALAuthorizationStatusRestricted,
    BEEAuthorizationStatusDenied = ALAuthorizationStatusDenied,
    BEEAuthorizationStatusAuthorized = ALAuthorizationStatusAuthorized,
} BEEAuthorizationStatus;



// 兼容性预定义
typedef int32_t BEEImageRequestID;
static const BEEImageRequestID BEEInvalidImageRequestID = 0;
static const BEEImageRequestID BEEALAssetImageRequestID = 1;

typedef void (^ BEEAssetImageProgressHandler)(double progress, NSError *__nullable error, BOOL *__nullable stop, NSDictionary *__nullable info);
typedef void (^ BEEAssetDataCompletionHandler)(NSData *__nullable data, BOOL cancelled, NSDictionary *__nullable extInfo);
