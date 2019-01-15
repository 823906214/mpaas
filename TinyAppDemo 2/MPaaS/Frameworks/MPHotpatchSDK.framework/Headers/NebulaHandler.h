//
//  NebulaHandler.h
//  MPHotpatchSDK
//
//  Created by yangwei on 17/4/18.
//  Copyright © 2017年 Alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "UnionResourcePb.pb.h"

@protocol NebulaHandler <NSObject>

- (void)handleNebulaWithInfo:(UnionResourceInfo *)info error:(NSError **)error;

@end
