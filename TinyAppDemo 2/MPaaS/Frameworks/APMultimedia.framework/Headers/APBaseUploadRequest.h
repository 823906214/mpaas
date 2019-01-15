//
//  APBaseUploadRequest.h
//  APMultimedia
//
//  Created by 慎一 on 2016/12/30.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "APMMConst.h"
#import "APBaseRequest.h"

@interface APBaseUploadRequest : APBaseRequest

/**
 上传的进度回调，可选项
 */
@property (nonatomic, copy) APMMProcessiveBlock progress;                           //下载进度回调

@end
