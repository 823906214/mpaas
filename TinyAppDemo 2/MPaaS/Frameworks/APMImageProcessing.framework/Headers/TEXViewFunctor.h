//
//  TEXViewFunctor.h
//  TEX
//
//  Created by Cloud on 2017/5/1.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "TEXFunctor.h"
typedef void (^TEXViewFunctorCompleteHandler)(BOOL result);  //埋点使用

@interface TEXViewFunctor : UIView <TEXInput>

@property (nonatomic, assign) BOOL needsFlip;

@property (nonatomic, strong) TEXViewFunctorCompleteHandler completeHandler; //埋点使用

@end
