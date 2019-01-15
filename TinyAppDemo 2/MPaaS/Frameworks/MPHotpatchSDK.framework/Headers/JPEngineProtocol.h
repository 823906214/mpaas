//
//  JPEngineProtocol.h
//  JSHotpatchSDK
//
//  Created by shenmo on 5/27/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#include "JSPatchMangle.h"

@protocol JPEngineProtocol <NSObject>

@required
- (void)didReplaceMethodForClass:(Class)klass selector:(SEL)selector originalImplementation:(IMP)originalImplementation typeEncoding:(NSString*)typeEncoding;

@end
