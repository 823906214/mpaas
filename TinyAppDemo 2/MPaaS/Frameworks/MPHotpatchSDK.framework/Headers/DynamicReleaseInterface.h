//
//  DynamicReleaseInterface.h
//  MPDynamicRelease
//
//  Created by shenmo on 4/29/16.
//  Copyright © 2016 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NebulaHandler.h"

typedef NS_ENUM(NSInteger, DRLocalBandageExecutionType)
{
    DRLocalBandageExecutionAll = 0,         // 执行所有本地脚本
    DRLocalBandageExecutionNonLazyload,     // 执行非Lazyload的脚本
    DRLocalBandageExecutionLazyload,        // 执行Lazyload的脚本
};

@interface DynamicReleaseInterface : NSObject

/**
 *  单例对象
 */
+ (instancetype)sharedInstance;

#pragma mark - 配置方法，通过Category覆盖以下方法实现应用的自定义配置

/**
 *  拉取Rpc时使用的应用Id，默认实现为
 *      [[[NSBundle mainBundle] infoDictionary] objectForKey:@"Product ID"]
 *
 *  @return 应用Id
 */
- (NSString*)productId;

/**
 *  拉取Rpc时使用的应用版本号，默认实现为
 *      [[[NSBundle mainBundle] infoDictionary] objectForKey:@"Product Version"];
 *
 *  @return 应用版本号
 */
- (NSString*)productVersion;

/**
 *  拉取Rpc时上报的userId，不同用户拉取到的Hotpatch等资源可能不一样。接入应用有自己的账户系统，需要实现这个方法，返回相应的userId值。如果是未登录态，可以返回nil。
 *
 *  @return 当前的userId
 */
- (NSString*)userId;

/**
 *  Hotpatch安全流程涉及到AES加密，每款应用使用的加密Key是不同的，并且使用无线保镖进行黑盒加密。这里返回应用使用的保存在无线保镖中的加密Key的名字。
 *
 *  @return 加密Key名字
 */
- (NSString*)AESEncryptionKeyName;

/**
 *  是否使用SDK预置的同步功能，默认是YES。
 *      当为YES时：SDK自动监听UIApplicationDidFinishLaunchingNotification和UIApplicationWillEnterForegroundNotification事件，
                并同步脚本。
 *      当为NO时：接入应用需要自己择机调用synchronizeBandage方法同步脚本。
 *
 *  @return 返回是否要使用SDK预置的同步功能
 */
- (BOOL)automaticSynchronization;

#pragma mark - 生命期方法，不需要使用Category覆盖，直接使用[DynamicReleaseInterface sharedInstance]调用。

/**
 *  获取本地有哪些脚本，用"|"分隔的脚本ID。这个给日志模块上报使用，每条日志都会带上，所以直接拼好。
 */
- (NSString*)getLocalBandages;

/**
 *  获取已经执行了哪些脚本，返回ID数组。这个给Crash上报使用。
 */
- (NSArray*)getExecutedBandages;

/**
 *  执行本地已经下载的所有Hotpatch脚本，这个方法需要尽量早调用，建议放在应用的didFinishLaunching方法最前面。
 */
- (void)executeLocalBandage:(DRLocalBandageExecutionType)type;

/**
 *  启动阶段进行脚本同步
 */
- (void)synchronizeBootup;

/**
 *  与服务端同步脚本，包括脚本的下载与回滚，同步完成后会自动执行新的脚本。这个方法会异步执行，
 */
- (void)synchronizeBandage;

/**
 *  更多参数的同步方法，这个方法会异步执行，
 *
 *  @param forced    是否强制拉取
 *  @param execute   拉取到后是否自动执行
 *  @param failBlock 失败的回调方法
 */
- (void)synchronizeBandage:(BOOL)forced execute:(BOOL)execute onSuccess:(void(^)())successBlock onFailed:(void(^)(NSError*))failBlock;

/**
 *  获取H5离线包的同步方法，这个方法会异步执行，
 *
 *  @param forced    是否强制拉取
 *  @param execute   拉取到后是否自动执行
 *  @param successBlock   拉取成功的回调方法
 *  @param failBlock 失败的回调方法
 */

- (void)synchronizeNebula:(NSDictionary *)dicApps forced:(BOOL)forced execute:(BOOL)execute onSuccess:(void(^)())successBlock onFailed:(void(^)(NSError*))failBlock;

#pragma mark - 高级方法，目前用于极端情况处理

/**
 *  判断应用是否正在执行本地脚本，执行完成返回NO。
 *  当监测到Crash时，校验这个方法的值，如果返回YES，表示极大可能因为Patch导致启动Crash。
 *
 *  @return 是否正在执行脚本。
 */
- (BOOL)executingBandages;

/**
 *  获取本地的hotpatch缓存工作目录，绝对路径
 */
- (NSString*)bandageLocalWorkspacePath;

/**
 *  重置Patch工作目录
 *
 *  @param reserveMetaInfo  是否保留元文件
        传YES时，删除本地已有脚本，但保留元文件，之后不会再拉取这些脚本；
        传NO时，删除整个目录，元文件也被删除，之后有脚本还是会同步回来。
 */
- (void)resetBandageWorkspace:(BOOL)reserveMetaInfo;

/**
 *  获取当前nebula包的appId
 *
 */
- (NSDictionary *)getNebulaUuids;

/**
 *  设置nebula资源包请求结果的处理方法，默认为nil;
 *
 */
- (id<NebulaHandler>)getNebulaHandler;

/**
 *  设置为YES时关闭没有bandage功能的alert提醒;
 *
 */
- (BOOL)notNeedBandageFunction;

@end
