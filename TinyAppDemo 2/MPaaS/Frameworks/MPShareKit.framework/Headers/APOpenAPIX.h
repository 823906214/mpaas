//
//  APOpenAPIX.h
//  APShareService
//
//  Created by 佳佑 on 15/6/3.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#ifndef APShareService_APOpenAPIX_h
#define APShareService_APOpenAPIX_h

#import "APOpenAPIObjectX.h"

@interface APOpenAPIX : NSObject

+ (NSDictionary *)getTBGoodsInfoFromUrl:(NSString *)url;

@end

@interface APShareStockObject () <NSCoding>

@end

@interface APShareTBGoodsObject () <NSCoding>

@end

@interface APShareStoreObject () <NSCoding>

@end

@interface APShareFundObject () <NSCoding>

@end

#endif
