//
//  BEEAssetData.h
//  BeePhotoPicker
//
//  Created by Yanzhi on 15/12/28.
//  Copyright © 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

// 定义ALAsset经过处理之后的数据类型
typedef enum : NSUInteger {
    /** 未知类型 */
    BEEAssetDataTypeNone,
    /** 图片UIImage，包括相册图片和拍摄图片 */
    BEEAssetDataTypeImage,
    /** Gif图片数据 */
    BEEAssetDataTypeGifData,
    /** iOS7视频AssetURL，iOS7及以下系统使用ALAssetsLibrary访问视频数据 */
    BEEAssetDataTypeALAssetVideo,
    /** iOS8视频LocalizedIdentify，iOS8及以上系统使用PHAsset访问视频数据 */
    BEEAssetDataTypePHAssetVideo,
    /** 拍摄的视频，BEECamVideo视频基础信息 */
    BEEAssetDataTypeCameraVideo,
    /** 多媒体视频，APVideoInfo视频基础信息 */
    BEEAssetDataTypeAPVideoInfo,
} BEEAssetDataType;

@interface BEEAssetData : NSObject

@property (nonatomic, assign) BEEAssetDataType dataType;
@property (nonatomic, strong) id data;      // UIImage / NSData / ALAssetURL / LocalizedIdentify / BEECamVideo / APVideoInfo

- (id)initWithType:(BEEAssetDataType)type data:(id)data;

@end
