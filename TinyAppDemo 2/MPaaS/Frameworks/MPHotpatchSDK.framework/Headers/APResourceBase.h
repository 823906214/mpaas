//
//  APResourceBase.h
//  DynamicDeployment
//
//  Created by liangbao.llb on 16/8/8.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface APResourceBase : NSObject

@property (nonatomic, strong) NSString *bizId;      // 业务Id
@property (nonatomic, strong) NSString *resId;      // 资源Id
@property (nonatomic, strong) NSString *version;    // 资源版本，获取资源时，为nil则返回最新版本资源
@property (nonatomic, strong) NSString *path;       // 资源缓存路径

@end
