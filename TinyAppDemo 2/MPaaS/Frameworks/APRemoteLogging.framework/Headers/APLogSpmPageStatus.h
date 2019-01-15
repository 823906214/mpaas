//
//  APLogSpmPageStatus.h
//  APRemoteLogging
//
//  Created by majie on 16/8/3.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APLogSpmPageStatus : NSObject

//判断是否在等pageend操作
@property (atomic, assign) BOOL writeingPageEnd;

//当前页面流水号
@property (atomic, strong) NSString *pageId;

//上一个页面流水号
@property (atomic, strong) NSString *lastPageId;

//当前页面spmid
@property (atomic, strong) NSString *pageSpmId;

//上一个页面的spmid
@property (atomic, strong) NSString *lastPageSpmId;

//打开时间
@property (atomic, assign) CFTimeInterval t1;

//页面打开时间
@property (atomic, strong) NSString *startTime;

//页面流水号index
@property (atomic, strong) NSString *hashCode;


@property (atomic, strong) NSString *currentPageId;
@property (atomic, strong) NSString *oldPageId;
@property (atomic, strong) NSString *spmStatus;
@property (atomic, strong) NSString *appId;

- (void)reset;

@end

@interface APLogSpmPageList : NSObject

- (void)addContent:(NSString *)content;
- (BOOL)containContent:(NSString *)content;

@end
