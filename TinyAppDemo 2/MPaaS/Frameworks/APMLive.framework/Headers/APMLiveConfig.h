//
//  APMLiveConfig.h
//  APMLive
//
//  Created by aspling on 16/6/23.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APMLiveConfig : NSObject<NSCopying>

@property (nonatomic, assign) NSUInteger width;
@property (nonatomic, assign) NSUInteger height;
@property (nonatomic, assign) int bitRate;     //比特率
@property (nonatomic, assign) int fps;         //帧率

@property (nonatomic, assign) NSUInteger timeout;    //推流超时时间

/**
 * 是否使用ping来做盘路验证
 */
@property (nonatomic, assign) BOOL enablePing;

/**
 * 网络不好时，用ping做旁路验证时主机地址
 */
@property (nonatomic, copy) NSString *pingHost;
/**
 * 网络不好时，多久处理一次带宽不足事件.单位秒
 */
@property (nonatomic, assign) NSUInteger period4HandleLowBandwidth;
/**
 * 网络不好时，ping做旁路验证时，ping包的次数
 */
@property (nonatomic, assign) NSUInteger countOfPing;
/**
 * 主播推流，拥塞阀值,单位KB
 */
@property (nonatomic, assign) NSUInteger maxSendBufferSize;
/**
 * 直播主播方底层多久采集一次带宽数据,单位秒
 */
@property (nonatomic, assign) NSUInteger period4BandwidthSample;
/**
 * 主播推流拥塞恢复最大累计次数，超过则认为恢复
 */
@property(nonatomic, assign) NSUInteger maxCongestionResumeEventCount;



@end
