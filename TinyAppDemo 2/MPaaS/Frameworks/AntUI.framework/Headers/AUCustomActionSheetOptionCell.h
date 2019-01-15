#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_actionSheet_AUCustomActionSheet//程序自动生成
//
//  AUCustomActionSheetOptionCell.h
//  AntUI
//
//  Created by zhaolei on 2017/6/2.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUCustomActionSheetOptionModel.h"

extern const CGFloat kAUCustomActionGapHeight;

@interface AUCustomActionSheetOptionCell : UITableViewCell

- (void)reloadWithOptionModel:(AUCustomActionSheetOptionModel *) optionModel;

+ (CGFloat)heightWithOptionModel:(AUCustomActionSheetOptionModel *) optionModel;

@end

#endif//程序自动生成
