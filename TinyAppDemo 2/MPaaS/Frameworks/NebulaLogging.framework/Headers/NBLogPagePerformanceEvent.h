//
//  NBLogPagePerformanceEvent.h
//  NebulaBiz
//
//  Created by Glance on 2017/8/4.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <NebulaPoseidon/NebulaPoseidon.h>

@interface NBLogPagePerformanceEvent : PSDEvent

@property (nonatomic, copy) NSDictionary *eventData;

@end
