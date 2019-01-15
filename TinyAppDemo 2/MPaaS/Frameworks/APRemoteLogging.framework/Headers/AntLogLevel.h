//
//  AntLogLevel.h
//  AntLog
//
//  Created by 卡迩 on 2017/1/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#ifndef AntLogLevel_h
#define AntLogLevel_h

typedef NS_ENUM(NSInteger,AntLogLevel) {
    AntLogLevelHigh   = 1,  //级别最高
    AntLogLevelNormal = 2,  //默认级别
    AntLogLevelLow    = 3   //级别最低
};

#ifdef __cplusplus
extern "C" {
#endif
    
    AntLogLevel AntLogLevelFromString(NSString *str);
    
    NSString *AntLogLevelToString(AntLogLevel level);
    
    AntLogLevel AntLogLevelFromFormatterDict(NSDictionary *dict);
#ifdef __cplusplus
}
#endif
    

#endif /* AntLogLevel_h */
