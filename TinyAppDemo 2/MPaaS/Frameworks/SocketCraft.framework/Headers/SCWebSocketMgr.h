//
//  SCWebSocketMgr.h
//  SocketCraft
//
//  Created by yangxiao on 2017/2/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "SCWebSocketDefines.h"
#import "SCWebSocketHandler.h"

@interface SCWebSocketMgr : NSObject<SCWebSocketHandlerDelegate>

@property (nonatomic) NSMutableDictionary<NSString*,SCWebSocketHandler*>*          dicAppID2WebSocketHandler;

+(instancetype)shareInstance;

-(void)closeAndDeleteAllWebSocketHandler;

-(void)closeAndDeleteHandlerWithAppID:(NSString*)appid;

-(void)closeSocketWithAppID:(NSString*)appid;

-(void)closeSocketWithAppID:(NSString*)appid code:(NSInteger)code reason:(NSString*)reason;

-(void)connectSocketWithAppID:(NSString*)appid appVersion:(UInt64)version isIgnoreCheckDomain:(BOOL)ignDomain url:(NSURL*)url httpHeader:(NSDictionary*)headers method:(NSString*)method params:(NSString*)data completionHandler:(connectSCWebSocketCompletionHandler)completionHandler openHandler:(callBackOnSCWebSocketOpen)openHandler messageHandler:(callBackOnSCWebSocketRecieveMessage)messageHandler errorHandler:(callBackOnSCWebSocketError)errorHandler closeHandler:(callBackOnSCWebSocketClose)closeHandler;

-(void)sendMessage:(id)msg withAppID:(NSString*)appid completionHandler:(sendSCWebSocketMessageCompletionHandler)handler;



@end
