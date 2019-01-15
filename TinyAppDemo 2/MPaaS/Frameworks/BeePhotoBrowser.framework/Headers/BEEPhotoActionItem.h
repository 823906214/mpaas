//
//  APPhotoActionItem.h
//  BeeHive
//
//  Created by Yanzhi on 15/5/20.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//
//  Help Document: http://gitlab.alibaba-inc.com/BeeHive/BeePhotoBrowser/blob/master/BEEPhotoActionItem.md

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    ActionItemTypeDefine,
    ActionItemTypeSavePhoto,
    ActionItemTypeScanQRCode,
    ActionItemTypeReport,
} ActionItemType;

// 举报参数的Key定义
#define ReportKey_ComplainSubScene          @"complainSubScene"         // 举报子场景
#define ReportKey_ComplainContentIdList     @"complainContentIdList"    // 举报的内容ID集合
#define ReportKey_OppositeUserid            @"oppositeUserid"           // 被举报用户ID
//#define ReportKey_ComplainTargetId          @"complainTargetId"         // 举报的主体ID
//#define ReportKey_ComplainType              @"complainType"             // 举报主体类型

@interface BEEPhotoActionItem : NSObject

@property (nonatomic, assign) ActionItemType itemType;
@property (nonatomic, copy)   NSString       *title;
@property (nonatomic, assign) BOOL           actionWillDisappearPhotoBrowser;     // 标记该操作将使图片预览界面被盖住

/**
 * 1、itemType == ActionItemTypeReport 举报类型时，actionParams包含Keys：<br>
 * complainSubScene NSString 必需，举报子场景，根据产品定义<br>
 * complainContentIdList NSString 必需，举报的内容ID集合，多个内容，逗号分割<br>
 * oppositeUserid NSString 可选，被举报用户ID，支付宝账户ID，若无可不传<br>
 * complainTargetId NSString 可选，举报的主体ID，生活号id、圈子id、群id等<br>
 * complainType NSString 可选，举报主体类型，生活号、圈子场景码等，若无可不传<br>
 */
@property (nonatomic, strong) NSDictionary   *actionParams;                       // 操作的参数信息

@end
