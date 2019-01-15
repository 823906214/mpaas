
#import <AssetsLibrary/AssetsLibrary.h>
#import "BEEAssetProtocol.h"

// 已获取用户访问授权方能获取最近图片

@interface APRecentPhotoUtil : NSObject

// 开始监听
+ (void)startMonitor;
// 结束监听
+ (void)stopMonitor;

// 可监听kAPPhotoChangedNotification后获取，或KVO监听此属性，该接口可能返回nil
+ (ALAsset *)getRecentPhoto DEPRECATED_MSG_ATTRIBUTE("请使用recentPhoto替换 V9.9.9废弃");

// 获取最近图片，更新数据时可能无法拿到最新图片
+ (id<BEEAssetProtocol>)recentPhoto;

// 查询Recent图片，解决查询过程中访问getRecentPhoto接口返回nil的问题
+ (void)queryRecentPhoto:(void (^)(id<BEEAssetProtocol>))completionBlock;

@end
