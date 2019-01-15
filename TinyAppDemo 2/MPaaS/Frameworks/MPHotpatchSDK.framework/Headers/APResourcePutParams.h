//
//  APResourcePutParams.h
//  DynamicDeployment
//
//  Created by liangbao.llb on 16/7/21.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "APResourceBase.h"

@interface APResourcePutParams : APResourceBase

/**
 *  资源数据, 注意：存储时path和data不能共存，优先选择存储data。
 */
@property (nonatomic, strong) NSData *data;

@end
