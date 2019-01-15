//
//  APLogMgr.h
//  APLog
//
//  Created by myy on 17/1/2.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol APLogZipInterface
- (BOOL)createZipFile:(NSString*)zipFile;
- (BOOL)addFileToZip:(NSString*)file newname:(NSString*)newname;
- (BOOL)closeZipFile;
@end


@protocol APLogMgrDelegate
- (NSString*)uploadLogUrl;
- (NSString*)uploadStatusUrl;
- (NSString*)currentUserId;
- (id<APLogZipInterface>)makeZipObj;
@optional
- (BOOL)isLogFormatAssertCheck;
- (BOOL)isCloseLogEncrypt;
- (void)logWithoutEncrypt:(NSString*)logString;
@end


@interface APLogMgr : NSObject
@property (nonatomic, weak) id<APLogMgrDelegate> delegate;
+ (APLogMgr*)sharedInstance;
- (void)handleUserChanged;
- (void)handleConfigUploadCmd:(NSArray*)taskArray;
- (void)handleSyncUploadCmd:(NSString*)syncOpString;
- (void)handleAutoUpload:(NSDictionary*)param;
- (void)addExcuteBlockAfterUpload:(void (^)(void))block;
- (void)uploadLogWithAccount:(NSString*)account startDate:(NSDate*)startDate endDate:(NSDate*)endDate;
@end



