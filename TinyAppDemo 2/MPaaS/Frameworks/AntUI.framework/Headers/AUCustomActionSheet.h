#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_actionSheet_AUCustomActionSheet//程序自动生成
//
//  AUCustomActionSheet.h
//  AntUI
//
//  Created by zhaolei on 2017/6/1.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AUCustomActionSheetOptionModel.h"


//#########################################################
//文档地址 : http://aui.alipay.net/develop/ios/aucustomactionsheet
//#########################################################


typedef void(^AUCustomActionSheetOptionSelectedCallback)(AUCustomActionSheetOptionModel *selectedOptionModel);

@interface AUCustomActionSheet : NSObject

@property (nonatomic, copy) AUCustomActionSheetOptionSelectedCallback optionSelectedCallback;

- (void)showWithOptionModels:(NSArray<AUCustomActionSheetOptionModel *> *) optionModels;

- (void)dismiss;

@end

#endif//程序自动生成
