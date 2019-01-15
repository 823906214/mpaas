//
//  MPDynamicLoader.h
//  APMPaaS
//
//  Created by shenmo on 18/11/2016.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MPDynamicLoader : NSObject

/**
 加载动态库二进制

 @param name 动态库名字
 @return 加载是否成功
 */
+ (BOOL)loadBinaryWithName:(NSString*)name;

/**
 返回已经加载了哪些动态库
 */
+ (NSSet*)loadedBinaries;

@end
