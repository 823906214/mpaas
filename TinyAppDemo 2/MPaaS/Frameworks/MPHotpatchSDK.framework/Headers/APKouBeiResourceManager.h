//
//  APKouBeiResourceManager.h
//  DynamicDeployment
//
//  Created by liangbao.llb on 16/7/21.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "APResourceManager.h"

@interface APKouBeiResourceManager : APResourceManager

/**
*  获取本地缓存指定资源。注意：当资源版本不设置时，返回本地最新资源。
*
*  @param params   指定资源列表。注意：APResourceGetParams.version为nil，则返回最新版本资源
*  @param bizId    业务名称，注意：不能为nil
*  @param callback 结果回调
*/
+ (void)getResFromCache:(NSArray<APResourceGetParams *> *)params business:(NSString *)bizId resResultsCallback:(APResResultsCallback)callback;

/**
 *  获取服务端指定资源。注意：当资源版本不设置时，返回本地最新资源。
 *
 *  @param params   指定资源列表
 *  @param bizId    业务名称，注意：不能为nil
 *  @param callback 结果回调
 */
+ (void)getResFromNet:(NSArray<APResourceGetParams *> *)params business:(NSString *)bizId resResultsCallback:(APResResultsCallback)callback;

/**
 *  缓存指定资源。
 *
 *  @param params   指定资源列表
 *  @param bizId    业务名称，注意：不能为nil
 *  @param callback 结果回调
 */
+ (void)putRes:(NSArray<APResourcePutParams *> *)params business:(NSString *)bizId resResultsCallback:(APResResultsCallback)callback;

@end
