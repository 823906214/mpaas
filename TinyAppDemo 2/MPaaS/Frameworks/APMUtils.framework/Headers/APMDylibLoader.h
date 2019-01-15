//
//  APMDylibLoader.h
//  APMUtils
//
//  Created by Cloud on 2017/9/4.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APMDylibLoader : NSObject

+ (BOOL)loadDylibWithName:(NSString*)name;

@end
