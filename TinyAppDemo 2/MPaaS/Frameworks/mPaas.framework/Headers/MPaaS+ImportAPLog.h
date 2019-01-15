//
//  MPaaS+ImportAPLog.h
//  APMPaaS
//
//  Created by shenmo on 8/29/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import "APLogOCWrapper+MPaaS.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus
    
    id<APLogOCWrapperClass> getAPLogOCWrapper();
    
#ifdef __cplusplus
}
#endif // __cplusplus

// Backward capability macros

#define APLogInfo(tag, fmt, ...)\
[getAPLogOCWrapper() APLogInfo:tag format:fmt, ##__VA_ARGS__]

#define APLogDebug(tag, fmt, ...)\
[getAPLogOCWrapper() APLogDebug:tag format:fmt, ##__VA_ARGS__]

#define APLogWarn(tag, fmt, ...)\
[getAPLogOCWrapper() APLogWarn:tag format:fmt, ##__VA_ARGS__]

#define APLogError(tag, fmt, ...)\
[getAPLogOCWrapper() APLogError:tag format:fmt, ##__VA_ARGS__]

#define APLogMonitor(tag, fmt, ...)\
[getAPLogOCWrapper() APLogMonitor:tag format:fmt, ##__VA_ARGS__]