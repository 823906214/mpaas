//
//  APResourceResult.h
//  DynamicDeployment
//
//  Created by liangbao.llb on 16/7/21.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "APResourceBase.h"

@interface APResourceResult : APResourceBase

/**
 *  处理失败信息
 */
@property (nonatomic, strong) NSError *error;

@end
