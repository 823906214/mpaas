//
//  AntBehavior.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2017/9/27.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AntLogLevel.h"

/**
 行为日志模型
 */
@interface AntBehavior : NSObject
@property (nonatomic, strong) NSString *actionId;     /**< 字段9,行为ID*/
@property (nonatomic, strong) NSString *appId;        /**< 字段12,子应用ID*/
@property (nonatomic, strong) NSString *spm/*seed*/;  /**< 字段16,spm,原seed字段*/
@property (nonatomic, assign) AntLogLevel logLevel;   /**< 字段17,日志等级,可用于控制日志上报*/
@property (nonatomic, strong) NSString *bizType;      /**< 字段18,业务类型,可用于控制日志分文件存储以及上报*/
@property (nonatomic, strong) NSString *extParam1;    /**< 字段20,扩展字段1*/
@property (nonatomic, strong) NSString *extParam2;    /**< 字段21,扩展字段2*/
@property (nonatomic, strong) NSString *extParam3;    /**< 字段22,扩展字段3*/
@property (nonatomic, strong) NSDictionary *extParam4;/**< 字段23,扩展字段4,将key-value对转换成‘key=value^key1=value1’的形式落入日志.*/
@property (nonatomic, strong) NSString *ucId;         /**< 字段27,用例编号*/
@end

////////////////////////////////////////////////////////////////////////////////

@interface AntBehavior ()
@property (nonatomic, strong) NSString *header;       /**< 字段1,日志头*/
@property (nonatomic, strong) NSString *ABTestInfo;   /**< 字段10,ABTest信息*/
@property (nonatomic, strong) NSString *refer;        /**< 字段11,refer信息(上一个页面的spm+pageId)*/
@property (nonatomic, strong) NSString *pageStartTime;/**< 字段13,页面打开时间戳,单位ms,64进制*/
@property (nonatomic, strong) NSString *xpath;        /**< 字段14,控件或页面XPath*/
@property (nonatomic, strong) NSString *entityId;     /**< 字段15,数据回流ID(scm)*/
@property (nonatomic, strong) NSString *renderBiz;    /**< 字段18,最终落在日志中的业务类型,该值为空时取bizType字段*/
@property (nonatomic, strong) NSString *pageStayTime; /**< 字段25,页面停留时长*/
@property (nonatomic, strong) NSString *pageId;       /**< 字段28,页面Id,格式为"spmId__utdid__timestampIn64_"*/
@property (nonatomic, strong) NSString *lastViewId;   /**< 字段29,上一个ViewId*/
@property (nonatomic, strong) NSString *viewId;       /**< 字段30,当前ViewId*/
@property (nonatomic, strong) NSString *trackId;      /**< 字段31,当前ACTIONID*/
@property (nonatomic, strong) NSString *trackToken;   /**< 字段32,当前ACTION_TOKEN*/
@property (nonatomic, strong) NSString *trackDesc;    /**< 字段33,当前ACTION_DESC*/
@property (nonatomic, strong) NSString *spmStatus;    /**< 字段45,spm状态,标识pageStart,pageEnd是否有效*/
@end

////////////////////////////////////////////////////////////////////////////////

@interface AntBehavior (Compatibility)
/**
 生成一个AntBehavior对象，兼容老的埋点接口参数
 */
+ (AntBehavior *)behaviorWithActionId:(NSString *)actionId
                            extParams:(NSArray *)extParams
                                appId:(NSString *)appId
                                 seed:(NSString *)seed
                                 ucId:(NSString *)ucId
                              bizType:(NSString *)bizType
                              extInfo:(NSDictionary *)extInfo;
@end

