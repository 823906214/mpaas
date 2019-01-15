//
//  NPOpenApiHandler.h
//  NebulaSDKPlugins
//
//  Created by 应俊康 on 2018/1/3.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NPAuthResultDelegate<NSObject>

-(void)handleAuthResult:(NSDictionary *)result;

@end

@protocol NPPayResultDelegate<NSObject>

-(void)handlePayResult:(NSDictionary *)result;

@end

@interface NPOpenApiHandler : NSObject

@property (nonatomic,strong) id<NPAuthResultDelegate> authResultHandler;
@property (nonatomic,strong) id<NPPayResultDelegate>payResultHandler;

+(instancetype)shareInstance;

-(void)handleUrl:(NSURL*)url;
@end
