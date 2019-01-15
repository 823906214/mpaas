//
//  NebulaTinyappDefine.h
//  NebulaTinyapp
//
//  Created by theone on 2017/12/18.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#ifndef NebulaTinyappDefine_h
#define NebulaTinyappDefine_h


typedef void (^NBJavaScriptCompleteBlock)(NSError *error);
typedef void (^NBJavaScriptCallback)(id json, NSError *error);
typedef void (^NBDownloadCallback)(NSDictionary *);
typedef void (^NBImportJsCallback)(NSDictionary *_Nullable dic, NSError *_Nullable error);


#define kNBFROMH5JSC @"FROMH5JSC"
#define kNBEnableDSL @"enableDSL"


//*******************************ExpandPropertyKeys***************************//
#define kExpandPropertyKey_ComponentManager     @"kExpandPropertyKey_ComponentManager"
#define kExpandPropertyKey_JSC                  @"kExpandPropertyKey_JSC"
#define kExpandPropertyKey_ComponentManager     @"kExpandPropertyKey_ComponentManager"
#define kExpandPropertyKey_JSCViewId            @"kExpandPropertyKey_JSCViewId"
#define kExpandPropertyKey_JSCPageId            @"kExpandPropertyKey_JSCPageId"



#endif /* NebulaTinyappDefine_h */
