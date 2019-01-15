//
//  BeeAudioPlayerDelegate.h
//  BEEAudioUtil
//
//  Created by 莜阳 on 17/1/16.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "BeeAudioItemInfo.h"

@protocol BeeAudioPlayerDelegate <NSObject>

- (void)playedInfo:(NSDictionary *)dic;

@end
