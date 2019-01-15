//
//  H5JSCManager.h
//  NebulaPlugins
//
//  Created by theone on 16/11/21.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
@class H5JSCBridge;
@class PSDSession;

@interface H5JSCManager : NSObject
@property(nonatomic, weak)  H5JSCBridge *bridge;
@property(nonatomic, strong) NSMutableDictionary *workers;
- (instancetype)initWithSession:(PSDSession *)session;
- (void)addWorker:(NSString *)url;
- (BOOL)isWorkerExist:(NSString *)url;
- (void)loadBaseJS;
@end
