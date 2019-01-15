//
//  APLogSpmContext.h
//  APRemoteLogging
//
//  Created by majie on 16/8/3.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APLogSpmPageStatus.h"

@interface APLogSpmContext : NSObject

+ (instancetype)sharedInstance;

@property (nonatomic, strong) APLogSpmPageStatus *pageStatus;
@property (nonatomic, strong) APLogSpmPageList *pageList;

- (NSString *)pageIdForHashCode:(NSString *)hashCode;
- (void)reset;
- (void)setPageId:(NSString *)pageId hashCode:(NSString *)hashCode index:(NSObject *)index;

@end

//重构手动spm埋点，解决ios8以下，生命周期的问题
@interface APLogManualPageInfo : NSObject<NSCopying>

@property (atomic, weak) NSObject *weakIndex;

//当前页面流水号
@property (atomic, strong) NSString *pageId;

//当前页面spmid
@property (atomic, strong) NSString *pageSpmId;

//打开时间
@property (atomic, strong) NSNumber *t1;

//页面打开时间
@property (atomic, strong) NSString *startTime;

//应用appid
@property (atomic, strong) NSString *appId;

//是否已经调用过pageEnd
@property (atomic, assign) BOOL didEnd;

@property (atomic, copy) NSString *referSpm;

// 来源的SPM
@property(atomic, strong) NSString *srcSPM;
// 当前页面最后点击的SPM
@property(atomic, strong) NSString *lastSPM;
// refer的PageInfo
@property(atomic, strong) APLogManualPageInfo *referPageInfo;

+ (void)filterPageInfo:(APLogManualPageInfo *)pageInfo;
+ (APLogManualPageInfo *)createPageInfoWithSpmId:(NSString *)spmid index:(NSObject *)index;
+ (void)updatePageId:(APLogManualPageInfo *)pageInfo WithSpmid:(NSString *)spmid;

@end

@interface APLogManualContext : NSObject

+ (instancetype)sharedInstance;

//上一个页面的spmid
@property (atomic, strong) NSString *lastPageSpmId;

//上一个页面流水号
@property (atomic, strong) NSString *lastPageId;

//上一个页面
@property (atomic, strong) NSString *lastViewId;

//上一个页面的pageInfo，包含srcSPM、lastSPM、pageId等
@property (atomic, strong) APLogManualPageInfo *lastPageInfo;


- (APLogManualPageInfo *)pageInfoForKey:(NSString *)key;
- (void)updatePageInfo:(APLogManualPageInfo *)pageInfo withSpmId:(NSString *)spmId;
- (void)updatePageInfo:(NSObject *)index withSrcSpm:(NSString *)srcSpm;
- (void)updatePageInfo:(APLogManualPageInfo *)pageInfo withLastSpm:(NSString *)lastSpm;
- (void)insertPageInfo:(APLogManualPageInfo *)pageInfo forKey:(NSString *)key;
- (void)checkWeakPageInfo;
- (NSString *)getSrcSpmFromDict:(NSObject *)index;

@end

