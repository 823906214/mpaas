//
//  DRDownloadManager.h
//  DynamicRelease
//
//  Created by ronghui.zrh on 16/3/3.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface DRDownloadRequest : NSObject
@property (nonatomic, strong) NSString *urlString;
@end

typedef void (^DRDownloadRequestBlock)(DRDownloadRequest *request);

typedef void (^DRDownloadOnSuccessBlock)(NSData *data);

typedef void (^DRDownloadOnFailedBlock)(NSError *error);

@interface DRDownloadManager : NSObject

- (void)cancel;

/**
 *  同步下载接口，使用方法如下：
 *  DRDownloadManager *downloadManager = [[DRDownloadManager alloc] init];
    [downloadManager sendConnectionSyncWithRequest:^(DRDownloadRequest *request) {
        request.urlString = "url";
    } onSuccess:^(NSData *data) {
    } onFailed:^(NSError *error) {
    }];
 *
 */
- (void)sendConnectionSyncWithRequest:(DRDownloadRequestBlock )requestBlock
                            onSuccess:(DRDownloadOnSuccessBlock)successBlock
                             onFailed:(DRDownloadOnFailedBlock)failedBlock;

@end
