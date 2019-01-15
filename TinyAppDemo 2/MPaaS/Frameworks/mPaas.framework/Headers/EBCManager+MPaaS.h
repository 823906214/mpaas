//
//  EBCManager+MPaaS.h
//  APMPaaS
//
//  Created by shenmo on 21/03/2017.
//  Copyright © 2017 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol EBCManagerClass <NSObject>

/**
 获取虚拟机调用栈
 */
+ (NSString*)getEBCContextInfo;

@end
