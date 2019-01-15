//
//  MPLiteSettingService.h
//  APMPaaS
//
//  Created by shenmo on 6/3/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

@protocol MPLiteSettingServiceClass <NSObject>

+ (NSString*)getRPCGateway;
+ (NSString*)getRPCProductId;

+ (NSString*)getRemoteLogGateway;
+ (NSString*)getRemoteLogProductId;

@end
