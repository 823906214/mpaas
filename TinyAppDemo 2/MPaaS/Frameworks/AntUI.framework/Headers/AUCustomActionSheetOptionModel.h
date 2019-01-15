#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_actionSheet_AUCustomActionSheet//程序自动生成
//
//  AUCustomActionSheetOptionModel.h
//  AntUI
//
//  Created by zhaolei on 2017/6/1.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    AUCustomActionSheetOptionDefault,
    AUCustomActionSheetOptionGap,
} AUCustomActionSheetOptionType;

typedef enum : NSUInteger {
    AUCustomActionSheetLabelAttributeDefault,
    AUCustomActionSheetLabelAttributeTitle,
    AUCustomActionSheetLabelAttributeCancel,
    AUCustomActionSheetLabelAttributeDestructive,
} AUCustomActionSheetLabelAttribute;

@interface AUCustomActionSheetSeparatorConfig : NSObject

@property (nonatomic, assign) BOOL isShowSeparator;
@property (nonatomic, assign) UIEdgeInsets separatorMargin;

@end

@interface AUCustomActionSheetOptionModel : NSObject

@property (nonatomic, assign) AUCustomActionSheetOptionType optionType;
@property (nonatomic, assign) BOOL isSelectable;
@property (nonatomic, copy) NSAttributedString *descAttributedString;
@property (nonatomic, copy) NSAttributedString *titleAttributedString;
@property (nonatomic, assign) CGFloat optionHeight;//可不设置.Gap默认高度5,不设置则根据实际内容计算
@property (nonatomic, strong) AUCustomActionSheetSeparatorConfig* separatorConfig;

+ (NSAttributedString *)attributedString:(NSString *) string
                                    type:(AUCustomActionSheetLabelAttribute) type;
@end

#endif//程序自动生成
