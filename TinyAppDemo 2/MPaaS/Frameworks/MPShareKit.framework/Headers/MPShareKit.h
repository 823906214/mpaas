//
//  MPShareKit.h
//  MPShareKit
//
//  Created by shenmo on 10/14/15.
//  Copyright (c) 2015 shenmo. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "APSKClient.h"
#import "WeiboSDK.h"
#import "APOpenAPI.h"
#import "APOpenAPIX.h"

extern NSString* const MPShareKitDidReceiveWeiboRequestNotification; // WeiboSDKDelegate回调方法，ShareKit处理完后，会将消息继续抛出
extern NSString* const MPShareKitDidReceiveWeiboResponseNotification; // WeiboSDKDelegate回调方法，ShareKit处理完后，会将消息继续抛出