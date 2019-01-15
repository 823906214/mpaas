//
//  NebulaPackage.h
//  NebulaAppBiz
//
//  Created by 扶瑶 on 16/2/22.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#ifndef NebulaAppDefine_h
#define NebulaAppDefine_h

#pragma mark - Nebula App Key

extern NSString *const NAKEY_EXTRA_ISACAPP;
extern NSString *const NAKEY_EXTRA_NEBULA_APP_VERSION;
extern NSString *const NAKEY_EXTRA_LAUNCHTYPE;

#pragma mark - Error

extern NSString *const NA_ERROR_DOMAIN;
extern NSString *const NA_ERROR_OPTIONS;

typedef enum {
    NAErrorUnknown = 10000000,         //  未知错误
    NAErrorSyncForceReqInvalid,        //  Sync强制请求标记时间过期或格式错误
    NAErrorNebulaAppFormatInvalid,     //  NebulaApp在应用中心extra中配置错误
    NAErrorAppCenterRpcFailed          //  应用中心RPC请求失败
}NAErrorCode;

#pragma mark - Log

// NAMLogType begin from 0
typedef NS_ENUM (NSUInteger, NALogType) {
    NALogTypeSync = 1000,               // Sync, 包含: 1. app 2. config 3. forceReq
    NALogTypeAppCenter,                 // 从应用中心同步数据标记
    NALogTypeException,                 // 异常埋点,通过step区分类型
    NALogTypePrepareApp,                // 准备应用
    NALogTypeSmart                      // 智能列表
};

#pragma mark - App

extern NSString *const NA_NEBULA_LOADING_APPID;

#pragma mark - Notificaton

extern NSString *const NANoti_LoadingPageStatusChanged;
extern NSString *const NANoti_LoadingPageFinished;

#pragma mark - protocol

// appid 维度的debug模式
@protocol NADebugProtocol <NSObject>

- (BOOL)enableDebugApp:(NSString *)appId;

- (BOOL)isNebulaApp:(NSString *)appId nebulaVersion:(NSString **)version;
- (NAMAppType)nbAppType:(NSString *)appId;
- (id)excuteRequest:(id)request header:(NSDictionary *)header;
- (NSString *)sceneForApp:(NSString *)appId;

@end

#pragma mark - App Handler

@interface NebulaStartContext : NSObject
@property (strong, nonatomic) NSString *nburl;
@end

extern NSString *const kNAHandlerFlag;
extern NSString *const kNAHandlerAnimate;

@protocol NebulaStartProtocol <NSObject>

@optional

/*
 * Nebula准备完成应用信息后是否可正常唤起应用
 *
 * param:
 *      app     要唤起的应用实例
 *      params  启动参数
 *      error   不支持启动时,业务返回错误信息
 *      url     不支持启动时,业务返回想要启动的url链接,通过startApp20000067启动
 */
- (BOOL)shouldStartApp:(NAMApp *)app
                params:(NSDictionary *)params
               context:(NebulaStartContext *)context
                 error:(NSError **)error;

/*
 * Nebula准备完成应用信息询问代理是否需要进一步准备流程
 *
 * param:
 *      app     要唤起的应用实例
 *      params  启动参数
 *      finish  完成回调
 *              成功: error参数传nil,正常打开应用
 *              失败: 传递error, 终止打开流程, 出错误页
 */
- (void)prepareApp:(NAMApp *)app
            params:(NSDictionary *)params
           context:(NebulaStartContext *)context
            finish:(NAMFinishBlock)finish;

@end

#endif /* NebulaAppDefine */
