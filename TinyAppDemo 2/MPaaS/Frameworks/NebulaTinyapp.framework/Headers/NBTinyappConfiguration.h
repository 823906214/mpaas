//
//  NBTinyappConfiguration.h
//  NebulaTinyapp
//
//  Created by theone on 2017/12/18.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NebulaTinyapp/NebulaTinyappDefine.h>

@protocol NBTinyappConfigDelegate

/**
 ServiceWork UserAgent
 @return NSString
 */
- (NSString *)SWUserAgent;

/**
小程序框架资源的fallback地址
 @param url 小程序框架资源的url
 @return fallback地址
 */
- (NSURL *)getAppexFrameworkFallbackUrl:(NSString *)url;

/**
 通过appId来查找一个NAMApp

 @param appid 小程序appId
 @return NAMApp 对象
 */
- (NAMApp *)findApp:(NSString *)appid;


/**
 可以通过某个key来查找已经持久化存储过的对象

 @param key 查询的key
 @param business 业务标识
 @return 持久化存储过的对象
 */
- (NSData *)getSavedDataWithKey:(NSString*)key business:(NSString*)business;
@end

@protocol NBTinyappDownLoadDelegate

/**
 传入一个包含url的字典来下载某个资源，回调资源的的本地路径
 @param data 下载的具体信息 @{@"url": targetUrl, @"appId": @"20000067"}
 @param callback 回调的结果 @{@"tempFilePath": tempFilePath}
 */
- (void)downLoadWithData:(NSDictionary *)data callback:(NBDownloadCallback)callback;
@end


@protocol NBTinyappCustomFileManagerDelegate

/**
 按照AppId来清除小程序存储过的资源

 @param appId 当前小程序的appId
 */
- (void)clearAppTempFilesWithAppId:(NSString *)appId;
@end

@interface NBTinyappConfiguration : NSObject
@property(nonatomic, weak)      id<NBTinyappConfigDelegate>                 tinyappConfigDelegate;
@property(nonatomic, weak)      id<NBTinyappDownLoadDelegate>               tinyappDownLoadDelegate;
@property(nonatomic, weak)      id<NBTinyappCustomFileManagerDelegate>      tinyappCustomFileManagerDelegate;
@property(nonatomic, copy)      NSString                                    *JSCBridgeFilePath;
@property(nonatomic)            Class                                       tinyappViewControllerCls;
@end


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    NBTinyappConfiguration * NBTinyappConfigurationGet();
    
#ifdef __cplusplus
}
#endif // __cplusplus
