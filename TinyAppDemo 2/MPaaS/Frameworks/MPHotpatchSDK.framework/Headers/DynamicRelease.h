//
//  DynamicRelease.h
//  DynamicRelease
//
//  Created by ronghui.zrh on 16/3/1.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DynamicReleaseInterface.h"

@class DynamicReleaseResponse;

typedef void (^DRExecSuccessBlock)(void);
typedef BOOL (^DRFetchSuccessBlock)(NSArray <DynamicReleaseResponse *> *packageArray);
typedef void (^DRFailedBlock)(NSError *error);
typedef void (^DRFinallyBlock)();

@class DynamicReleaseRequest;

typedef void (^DRRequest)(DynamicReleaseRequest *request);

typedef NS_ENUM(NSInteger, DRActionType) {
    DRActionTypeRollback=0,
    DRActionTypeUpdate=1,
};

typedef NS_ENUM(NSInteger, DRExecuteHotPatchType) {
    DRExecuteHotPatchTypeOnlyOnce=0,
    DRExecuteHotPatchTypeEveryTime=5,
};

typedef NS_ENUM(NSInteger, DRDynamicReleasePackageType) {
    DRDynamicReleasePackageTypeHotpatch = 1 << 0,
    DRDynamicReleasePackageTypeBirdNest = 1 << 1,
};

typedef NS_ENUM(NSInteger, DRDynamicReleaseHotPatchScriptType) {
    DRDynamicReleaseHotPatchScriptTypeUnknown,
    DRDynamicReleaseHotPatchScriptTypeLua,
    DRDynamicReleaseHotPatchScriptTypeJavaScript
};

typedef NS_ENUM(NSInteger, DRDynamicReleaseResultType) {
    DRDynamicReleaseResultTypeUnknown = 0,
    DRDynamicReleaseResultTypeHotPatchFailed = 1 << 0,
    DRDynamicReleaseResultTypeHotPatchSuccess = 1 << 1,
    DRDynamicReleaseResultTypeBirdNestFailed = 1 << 2,
    DRDynamicReleaseResultTypeBirdNestSuccess = 1 << 3,
    DRDynamicReleaseResultTypeFailed = DRDynamicReleaseResultTypeHotPatchFailed|DRDynamicReleaseResultTypeBirdNestFailed
};

typedef NS_ENUM(NSInteger, DRDynamicReleaseRequestType) {
    DRDynamicReleaseRequestTypeUnknown,
    DRDynamicReleaseRequestTypeManual,
    DRDynamicReleaseRequestTypeAuto,
};

@interface DynamicReleaseRequest : NSObject


/**
 *  注册进来的self
 */
@property(nonatomic,weak)id weakSelf;

/**
 *  超时时间，暂时没用
 */
@property(nonatomic,assign)NSInteger timeout;

/**
 *  包类型
 */
@property(nonatomic,assign)DRDynamicReleasePackageType packageType;

/**
 *  请求的方式，手动触发，还是发布模块自动获取
 */
@property(nonatomic,assign)DRDynamicReleaseRequestType requestType;


@property(nonatomic,strong)NSString *packageName;

/**
 *  是否强制调用
 */
@property(nonatomic,assign)BOOL forceFetch;

@end

@interface DynamicReleaseResponse : NSObject

@property(nonatomic,strong)NSString *name;
@property(nonatomic,strong)NSString *path;
@property(nonatomic,strong)NSString *version;
@property(nonatomic,strong)NSString *md5;
@property(nonatomic,strong)NSString *type;

/**
 *  当rollBack为yes的时候，只有name字段，其他的为空
 */
@property(nonatomic,assign)BOOL rollBack;

@end


@protocol DynamicRelaseProtocol <NSObject>

/**
 *  暂时无用
 */
+ (void)registerNotification;

@end

@interface DynamicRelease : NSObject


/**
 *  通过调用这个函数，注册新的包可用的回调，需要注意的是，callback是有返回值的，返回这个包是否成功的应用
 *
 *  @param requestBlock <#requestBlock description#>
 *  @param callback     <#callback description#>
 */
+ (void)registerPackageNotificationWithRequest:(DRRequest)requestBlock
                                      callBack:(DRFetchSuccessBlock)callback;

/**
 *  <#Description#>
 *
 *  @param requestBlock <#requestBlock description#>
 */
+ (void)removePackageNotificationWithRequest:(DRRequest)requestBlock;

/**
 *  执行包
 *
 *  @param requestBlock <#requestBlock description#>
 *  @param successBlock <#successBlock description#>
 *  @param failedBlock  <#failedBlock description#>
 *
 *  
 */
+ (void)executuePackageWithRequest:(DRRequest)requestBlock
                              type:(DRLocalBandageExecutionType)type
                     onSuccess:(DRExecSuccessBlock)successBlock
                      onFailed:(DRFailedBlock)failedBlock
                     onFinally:(DRFinallyBlock)finallyBlock;

@end
