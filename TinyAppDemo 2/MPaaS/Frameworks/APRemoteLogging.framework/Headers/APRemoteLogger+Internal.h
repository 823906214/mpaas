//
//  APRemoteLogger+Internal.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2017/4/12.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "APRemoteLogging.h"
#import "APLogSpmContext.h"

//把APRemoteLogging.h中那堆不需要普通业务关注的接口移到了这里. by 卡迩
NS_ASSUME_NONNULL_BEGIN
@interface APRemoteLogger (Internal)

#pragma mark -
#pragma mark 兼容需要保留
/**
 *   注意：新的埋点不要调用此接口，为保持兼容以前的代码所以保留
 *              8.3之前的老的页面继续使用此接口，8.3新开的页面使用writeLogWithActionId:..这个接口
 *
 *  @param dict log 字典
 */
+(void)writeLogWithLogDictionary:(NSDictionary *) dict /*__deprecated*/;

#pragma mark -
#pragma mark Global State
/**
 获取最近一次手动PV埋点(pageMonitor)生成的pageInfo对象.
 
 @return 最近一次手动PV埋点生成的pageInfo对象.
 */
+ (nullable APLogManualPageInfo *)currentPageInfo;

/**
 获取最后点击的控件的spm值.

 @return 最后点击的控件的spm值(若有).
 */
+(nullable NSString *)lastClickSpm;

/**
 更新最后点击的spm值.
 @note 该方法供自动化埋点SDK调用,业务方不要使用.
 @param spm 最后点击的spm值.可以为空.
 */
+(void)setLastClickSpm:(nullable NSString *)spm;

/**
 *  界面点击的ActionToken(TraceID)
 *
 *  @return 最近界面点击的ActionToken(TraceID)
 */
+(nullable NSString *) currentActionToken;

/**
 *  界面点击的ActionToken的生成时间戳，为精简RPC包大小而提供
 *
 *  @return 最近界面点击的ActionToken的生成时间戳
 */
+(unsigned long long) tokenTimestamp;

/**
 *  界面点击的最近一个控件标识
 *
 *  @return 最近界面点击的最近一个控件标识
 */
+(nullable NSString *) currentActionControlID;

/**
 *  当前页面的ID
 *
 *  @return 当前页面的ID
 */
+(nullable NSString *) currentPageID;

+(nullable NSString *) lastPageID;

+(nullable NSString *) currentSubAppID;

+(void) resetCurrentPageId:(nonnull NSString *)pageId;

/**
 *  页面数据准备好到达可用状态，由业务主动调用
 *
 *  @return void
 */
+ (void)pageDidFinishInitializing;

/**
 *  字符串数组格式化转成str1|str2|str3格式字符串
 *
 *  @param array 字符串数组
 *
 *  @return 格式化后字符串
 */
+ (nonnull NSString *)convertToStringFromArray:(nonnull NSArray *)array;

/**
 *  设置扩展参数，支持扩展参数的日志模型（行为，性能）
 *  字典转成 key=value^key=value^key=value 格式字符串
 *
 *  @return void
 */
+ (void)setFoundationExtended:(nullable NSDictionary *)dict;

/**
 *  字典格式化 转成 key:value&key:value&key:value 格式字符串
 *
 *  @param dictionary 字典
 *  @param kvSeparator 可以为空，默认使用:连接，字典key和value的连接字符（比如key:value）
 *  @param componentsSeparator 可以为空，默认使用&连接，每队key，value组合后的连接字符（比如key:value&key:value）
 *  @return 格式化后的字符串
 *
 */
+ (nonnull NSString *)convertToStringFromDictionary:(nonnull NSDictionary *)dictionary
                                        kvSeparator:(nullable NSString *)separator1
                                componentsSeparator:(nullable NSString *)separator2;

/**
 *  取索引的pageid
 *  @param index  pageid索引
 *  @return 页面流水号
 */
+ (nullable NSString *)pageIdForIndex:(nonnull NSObject *)index;

/**
 *  取索引的pageid的时间戳
 *  @param index  pageid索引
 *  @return 页面流水号的时间戳
 */
+ (nullable NSString *)pageIdTimestampForIndex:(nonnull NSObject *)index;

/**
 *  取索引的spmid
 *  @param index  pageid索引
 *  @return 页面spmid
 */
+ (nullable NSString *)spmIdForIndex:(nonnull NSObject *)index;

/**
 *  取索引的信息
 *  @param index  pageid索引
 *  @param type  pageInfo类型
 *  @return 页面信息
 */
+ (nullable NSString *)pageInfomationForIndex:(nonnull NSObject *)index forType:(APRemoteLoggerPageInfomationType)type;

/**
 *  清除所有无效的历史流水号
 */
+ (void)resetPageMonitorContext;

/**
 *  向spmpage列表中添加page页
 */
+ (void)addSpmPage:(nonnull NSString *)spmPage;

/**
 *  得到日志等级
 */
+ (NSInteger)levelNumberForString:(nonnull NSString *)strLevel;

/**
 *  设置外部开关值
 */
+ (void)setSwitchValue:(nullable NSString *)value forKey:(nonnull NSString *)key;

/**
 是否已经完成历史日志文件检查
 @note 在该方法返回YES后,触发某个bizType的日志的上报会附加上历史日志,否则只会上报本次启动产生的日志
 @return 在启动完成一定时间后会捞取历史日志到内存中,当该动作已完成时,返回 YES, 否则返回 NO.
 */
+ (BOOL)isHistoryLogFileChecked;

#pragma mark -
#pragma mark 以下函数业务不要调用

+(void)writeCrashLog:(NSString *) report vcStack:(NSString *) vcStack;
+(NSDictionary*)stateWhenCrashed:(NSString*)vcStack thread:(thread_t)thread;
+(void)writeCrashLog:(NSString *) report state:(NSDictionary*)state;
+(void)writeOOMLog:(NSString *)report state:(NSDictionary *)infoDic;

+ (void)writePerformanceLogWithType:(APLogType)type
                            subType:(NSString *) subType
                        extraParams:(NSArray *) extraParams
                    actionControlID:(NSString *) controlID
                         actionToke:(NSString *) actionToken;
+(void)upload;
+ (void)protectExtentionParams:(NSMutableArray *)params;
+(void) logAutoEventWithBizType:(NSString*)bizType params:(NSArray*)params;
+(void) logPageBeginRenderWithPageName:(NSString *) name;
+(void) logPageStartWithPageId:(NSString *) pageId appId:(NSString *) appId
                   sourceAppId:(NSString *) sourceAppId pageName:(NSString *) pageName;

+ (void)logPageMonitorWithMonitorType:(NSString *)monitorType;
+ (NSString *)logPageMonitorType;

NSString *pageDidAppearName(NSString *pageName);
+ (void)logPageEndRenderWithPageName:(NSString *)name;

+(BOOL) statusForWriteLogSwitch:(NSString*) logType;
+(BOOL) statusForSendLogSwitch:(NSString*) logType;

void logApplicationSendEvent(UIEvent * event);
void logSendAction(SEL action, id target, id sender, UIEvent* event);

+(void) checkCrashLogWithCompletionBlock:(void (^)(void)) block;
void updateSwitchProfile(NSString *actionType);

// 添加OC版本的接口，为了利用OC的动态特性实现模块间解耦合
+ (void)SLWriteMonitorLog:(NSDictionary*)attachDict appID:(NSString*)appID monitorType:(NSString*)monitorType subMonitorType:(NSString*)subMonitorType;
+ (void)APWriteNetLog:(NSString*)identifier size:(NSString*)size type:(NSString*)type owner:(NSString*)owner extDict:(NSDictionary*)extDict;
void  SLWriteMonitorLog(NSDictionary * attachDict, NSString* appID, NSString *monitorType, NSString *subMonitorType);
void APWriteNetLog(NSString *identifier, NSString *size, NSString* type, NSString *owner, NSDictionary * extDict);

/**
 *   暂停日志上传，最大暂停时间为60s，时间过后自动打开日志上传
 *   设置这个机制的原因是防止调用方异常，没有调用resumeLogUploading等情况下，导致日志无法上传。
 *
 *  @param secondes 自定义的日志暂停上传时间，最大值为60s，最小值为1s，其余值将导致默认暂停10s
 */
+(void) suspendLogUploadingForSeconds:(int) seconds;

/**
 *   立即恢复日志上传功能
 */
+(void) resumeLogUploading;


@end
NS_ASSUME_NONNULL_END
