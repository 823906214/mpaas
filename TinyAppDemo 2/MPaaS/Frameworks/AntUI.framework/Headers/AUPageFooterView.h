#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_PageFooter_AUPageFooterView//程序自动生成
//
//  AUPageAnkletView.h
//  AntUI
//
//  Created by 莜阳 on 2017/6/21.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AUTextLinkView.h"
#import "AUCopyrightView.h"

@interface AUPageFooterModel : NSObject

@property (nonatomic, strong) NSMutableArray *textLinkInfos;
@property (nonatomic, strong) NSString *copyrightInfo;

@end

typedef void(^paramsBlock)(AUPageFooterModel *model);

@interface AUPageFooterView : UIView

@property (nonatomic, strong) AUTextLinkView *textLinkView;    // 文字链
@property (nonatomic ,strong) AUCopyrightView *copyrightInfoView;  // 版权文字

//
- (instancetype)initWithFrame:(CGRect)frame params:(paramsBlock)params;

@end

#endif//程序自动生成
