//
//  APPhotoBrowserHelper.h
//  BeeHive
//
//  Created by Yanzhi on 15/5/29.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WWPhotoBrowser.h"

typedef void (^H5Callback)(NSDictionary *data);

@interface BEEPhotoBrowserHelper : NSObject <BEEPhotoBrowserDelegate>

@property (nonatomic, strong) NSMutableArray *photoArray;
@property (nonatomic, strong) NSMutableArray *thumbArray;
@property (nonatomic, assign) BOOL enableSavePhoto;
@property (nonatomic, assign) NSUInteger flagNumber;
@property (nonatomic, assign) BOOL enableDeviceRotate;
@property (nonatomic, assign) BOOL autoDismissForSingleVideo;   //单个视频播放结束自动退出预览，default is NO
@property (nonatomic, copy) H5Callback callback;


/**
  * 解析外部传入的数据源
  * @param: imageItemArray=[{u:, t:, r:, m:},{u:, t:, r:, m:},…]
            u: image Url（Required）
            t: Thumbnail url (Optional)
            r: thumbnail Rect (based on UIScreen, Optional)
            m: thumbnail content Mode (UIViewContentMode, default is UIViewContentModeScaleAspectFill)
 **/
- (id)initWithImageItemArray:(NSArray *)imageItemArray;

@end
