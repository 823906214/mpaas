//
//  AURegisterManager.h
//  AntUI
//
//  Created by 祝威 on 16/9/27.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import  "AUThirdPartyAdapter.h"

/*！
 @class       AURegisterManager
 @abstract    NSObject
 @discussion  蚂蚁UI注册机管理
 */
@interface AURegisterManager : NSObject

/*
 蚂蚁UI注册机实例化
 */
+ (instancetype) shareInstance;

/*
  使用蚂蚁UI之前，需要把实现协议的对象注册进来。
 */
- (void)registerAUObject:(id<AUThirdPartyAdapter>) regObj;

/*
 从注册管理队列中获取出实现协议的对象，提供给内部调用
 */
- (id<AUThirdPartyAdapter>)AUObjectFromManager;


@end
