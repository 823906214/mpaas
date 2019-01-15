//
//  APResourceGetParams.h
//  DynamicDeployment
//
//  Created by liangbao.llb on 16/7/21.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "APResourceBase.h"

@interface APResourceGetParams : APResourceBase

/**
 *  资源地址，为nil表示是rpc拉取资源
 */
@property (nonatomic, strong) NSString *url;

@end

