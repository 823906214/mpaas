//
//  APDynamicDeploymentTaskManager.h
//  DynamicDeployment
//
//  Created by majie on 16/7/11.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APDynamicDeploymentTaskModel.h"
#import "APDynamicDeploymentDef.h"

@interface APDynamicDeploymentDownloadManager : NSObject

+ (instancetype)sharedManager;

/**
 *  请求下载任务，
 *
 *  @param model 必填，下载任务model
 *  @param completionBlock 可填，下载任务完成回调
 */
- (void)requestTaskModel:(APDynamicDeploymentTaskModel *)model
         completionBlock:(APDynamicDeploymentDownloadCompletionBlock)completionBlock;




/**
 *  取消下载任务，
 *
 *  @param model 必填，取消下载任务model
 */
- (void)cancel;

@end
