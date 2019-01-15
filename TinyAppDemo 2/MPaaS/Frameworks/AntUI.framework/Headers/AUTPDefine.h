//
//  AUThirdPartyDefine.h
//  AntUI
//
//  Created by maizhelun on 2017/3/31.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AUTPWrapper.h"

#ifndef AUThirdPartyDefine_h
#define AUThirdPartyDefine_h


/////////////////////////////////////////////////////////////
////////////////////// Language /////////////////////////////
/////////////////////////////////////////////////////////////

/**
 *  取当前语言版本的文本.
 *  @param bundle  文本在字符串表所在\c bundle名,通常为模块资源bundle名称.
 *  @param key     文本在字符串表中的key
 *  @param comment 当找不到\c key 对应的文本内容时, commont作为默认返回内容.同时 \c commont 也作为\c genstrings自动生成\c .strings文件时的注释.
 *
 *  @return 当前语言版本的文本内容. 若字符串表中没有该\c key, 返回 \c comment .
 */
#undef	__TEXT
#define __TEXT(bundle,key,comment) \
[AUShell thirdParty_localizedStringForKey:(key) defaultValue:(comment) inBundle:(bundle)]


/////////////////////////////////////////////////////////////
////////////////////// Log /////////////////////////////
/////////////////////////////////////////////////////////////

#define AULogError(fmt, ...) \
NSLog(fmt, ##__VA_ARGS__); \
[AUShell thirdPartyAPLogInfo:@"[AntUI]" params:fmt, ##__VA_ARGS__];

#define AULogInfo(fmt, ...) \
NSLog(fmt, ##__VA_ARGS__); \
[AUShell thirdPartyAPLogInfo:@"[AntUI]" params:fmt, ##__VA_ARGS__];

#define AULogWarn(fmt, ...) \
NSLog(fmt, ##__VA_ARGS__); \
[AUShell thirdPartyAPLogInfo:@"[AntUI]" params:fmt, ##__VA_ARGS__];

#define AULogDebug(fmt, ...) \
NSLog(fmt, ##__VA_ARGS__);



/////////////////////////////////////////////////////////////
//////////////////////  Config  /////////////////////////////
/////////////////////////////////////////////////////////////

#define AUConfigForKey(key) [AUShell thirdParty_configForKey:(key)]

/////////////////////////////////////////////////////////////
//////////////////////   RGB    /////////////////////////////
/////////////////////////////////////////////////////////////

#define RGB(c) \
[UIColor colorWithRed:(((c) & 0xff0000) >> 16) / 255.0f \
green:(((c) & 0xff00) >> 8) / 255.0f \
blue:((c) & 0xff) / 255.0f \
alpha:1.0]

#define RGB_A(c,a) \
[UIColor colorWithRed:(((c) & 0xff0000) >> 16) / 255.0f \
green:(((c) & 0xff00) >> 8) / 255.0f \
blue:((c) & 0xff) / 255.0f \
alpha:a]


/////////////////////////////////////////////////////////////
//////////////////////   MD5    /////////////////////////////
/////////////////////////////////////////////////////////////
#define MD5String(text) [AUShell thirdParty_md5String:text];

/////////////////////////////////////////////////////////////
////////////////////  OpenURL  ///////////////////////////
/////////////////////////////////////////////////////////////

#define AUOpenURL(urlString) [AUShell thirdParty_openURL:(urlString)]

#endif /* AUThirdPartyDefine_h */
