//
//  APBaseDownloadRequest.h
//  APMultimedia
//
//  Created by 慎一 on 2017/4/13.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "APBaseRequest.h"

@interface APBaseDownloadRequest : APBaseRequest

/**
 *  是否直接使用HTTPS下载（针对红包项目业务）
 */
@property (nonatomic, assign) BOOL useHttps;

/**
 * 视频任务优先级，默认APMultimediaTaskPriorityDefault
 */
@property (nonatomic, assign) APMultimediaTaskPriority priority;

/**
 *  是否后台触发的任务，比如一些预推资源
 */
@property (nonatomic, assign) BOOL backgroundTask;

@end
