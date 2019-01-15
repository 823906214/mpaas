//
//  AntPerformance.h
//  APRemoteLogging
//
//  Created by 卡迩 on 2017/9/29.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AntLogLevel.h"

@interface AntPerformance : NSObject
@property (nonatomic, assign) AntLogLevel logLevel;   /**< 日志等级,可用于控制日志上报，不落日志*/
@property (nonatomic, strong) NSString *header;       /**< 字段1,日志头*/
@property (nonatomic, strong) NSString *bizType;      /**< 字段12,业务类型,可用于控制日志分文件存储以及上报*/
@property (nonatomic, strong) NSString *subType;      /**< 字段13,子类别*/
@property (nonatomic, strong) NSString *extParam1;    /**< 字段20,扩展字段1*/
@property (nonatomic, strong) NSString *extParam2;    /**< 字段21,扩展字段2*/
@property (nonatomic, strong) NSString *extParam3;    /**< 字段22,扩展字段3*/
@property (nonatomic, strong) NSDictionary *extParam4;/**字段23,扩展字段4,将key-value对转换成‘key=value^key1=value1’的形式落入日志.*/
@property (nonatomic, strong) NSString *renderBiz;/**<字段12,最终落在日志中的业务类型,该值为空时取bizType字段*/
@end

@interface AntPerformance (/*Private*/)
@property (nonatomic, strong) NSString *actionId;     /*字段09,actionid*/
@property (nonatomic, strong) NSString *actionToken;  /*字段10,actionToken*/
@property (nonatomic, strong) NSString *sampleRate;   /*字段11,采样率*/
@end
