//
//  APMapSetting.h
//  APMap
//
//  Created by 去疾 on 16/10/10.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APMapKeySetting : NSObject

@property (nonatomic, strong) NSString *apiKey;

+ (instancetype)getInstance;

@end

@interface APMapSetting : NSObject

/**
 *  初始化高德SDK服务，设置APIKey，替代原来的调用 [MAMapServices sharedServices].apiKey = [self getCurrentKey];
 */
+(void)setupAMapMpaasAPIKey;

/**
 *  获取当前包类型的高德APIKey
 *
 *  @return 当前包环境下的key
 */
+(NSString *)getCurrentKey;

@end
