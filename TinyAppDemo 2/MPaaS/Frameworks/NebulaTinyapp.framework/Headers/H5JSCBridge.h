//
//  H5JSCBridge.h
//
//  Created by theone on 16/11/21.
//  Copyright © 2016年 theone. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <NebulaTinyapp/NebulaTinyappDefine.h>

@class H5JSCExecutor;
@class H5JSCTiming;

@interface H5JSCBridge : PSDJsBridge

@property(nonatomic, weak)   H5JSCExecutor  *javaScriptExecutor;

- (instancetype)initWithSession:(PSDSession *)session;


- (void)executeJavaScript:(NSString *)javaScript
                sourceURL:(NSURL *)sourceURL
               onComplete:(NBJavaScriptCallback)onComplete;

- (void)doFlushMessageQueue:(id)buffer;

- (void)doFlushMessageQueue:(NSDictionary*)message
                   callBack:(PSDJsApiResponseCallbackBlock)callback;

- (void)sendMessage:(NSString *)messageName
               data:(id)data
   responseCallback:(PSDJsApiResponseCallbackBlock)responseCallback;

//timer
- (void)addUpdateObserver:(H5JSCTiming *)timer;
- (void)createTimer:(nonnull NSNumber *)callbackID
           duration:(NSTimeInterval)jsDuration
   jsSchedulingTime:(nonnull NSDate *)jsSchedulingTime
            repeats:(BOOL)repeats;
- (void)deleteTimer:(nonnull NSNumber *)timerID;
- (void)invalidate;
- (void)setUp;

//importjs
- (void)importJSWithUrl:(nullable NSString *)url callback:(nullable NBImportJsCallback)callback;
@end
