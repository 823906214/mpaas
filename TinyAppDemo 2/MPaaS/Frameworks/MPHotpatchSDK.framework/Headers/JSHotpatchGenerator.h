//
//  JSBandageGenerator.h
//  JSHotpatchSDK
//
//  Created by shenmo on 4/7/16.
//  Copyright © 2016 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JPEngineProtocol.h"

@interface JSBandageGenerator : NSObject

/**
 *  启动JPEngine
 */
+ (void)startEngine;

/**
 *  DEBUG调试脚本初始化
 */
+ (void)debugPatchInit;

#ifdef DEBUG

/**
 向调试服务器写log
 */
+ (void)writeServerLog:(NSString*)log;
#endif

/**
 *  运行字符串脚本
 *
 *  @param jsString js脚本内容的字符串
 *
 *  @return 错误信息，若成功则返回nil
 */
+ (NSError *)runJSString:(NSString *)jsString;
+ (NSError *)runJSString:(NSString *)jsString delegate:(id<JPEngineProtocol>)delegate;

/**
 *  运行本地文件的脚本
 *  注意手机运行访问不了mac的目录！
 *
 *  @param filePath js脚本所在目录
 *
 *  @return 错误信息，若成功则返回nil
 */
+ (NSError *)runJSFile:(NSString *)filePath;
+ (NSError *)runJSFile:(NSString *)filePath delegate:(id<JPEngineProtocol>)delegate;

/**
 *  运行加密压缩后的patch.zip文件
 *
 *  @param patchPath patch.zip文件所在目录
 *
 *  @return 错误信息,若成功则返回nil
 */
+ (NSError *)runBandageFile:(NSString *)patchPath;
+ (NSError *)runBandageFile:(NSString *)patchPath delegate:(id<JPEngineProtocol>)delegate;

/**
 *  运行加密压缩后的patch.zip的文件流
 *
 *  @param bandageData patch.zip的文件刘
 *
 *  @return 错误信息,若成功则返回nil
 */
+ (NSError *)runBandageData:(NSData *)bandageData;
+ (NSError *)runBandageData:(NSData *)bandageData delegate:(id<JPEngineProtocol>)delegate;

@end
