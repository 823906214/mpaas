//
//  BEEAssetUtil.h
//  BeePhotoPicker
//
//  Created by muqiao.hyk on 16/11/4.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BEEAssetProtocol.h"

@interface BEEAssetUtil : NSObject
/** @desc 根据AssetKey反向获取Asset */
+ (void)assetForKey:(NSString *)assetKey resultBlock:(void (^)(id<BEEAssetProtocol>))resultBlock;
@end
