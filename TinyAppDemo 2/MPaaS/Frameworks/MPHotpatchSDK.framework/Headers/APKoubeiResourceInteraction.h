//
//  APKoubeiResourceInteraction.h
//  DynamicDeployment
//
//  Created by liangbao.llb on 16/8/5.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "APDynamicDeploymentBaseInteraction.h"
#import "APResourceGetParams.h"
#import "APKouBeiResourceManager.h"

@interface APKoubeiResourceInteraction : APDynamicDeploymentBaseInteraction

- (void)getResFromNet:(NSArray<APResourceGetParams *> *)params business:(NSString *)bizId resResultsCallback:(APResResultsCallback)callback;

@end
