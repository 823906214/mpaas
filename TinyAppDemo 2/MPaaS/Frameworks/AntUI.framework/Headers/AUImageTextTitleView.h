#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_TitleBar_AUImageTextTitleView//程序自动生成
//
//  AUImageTextTitleView.h
//  AntUI
//
//  Created by 莜阳 on 2017/11/1.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>


// 目前只支持图在左边
@interface AUImageTextTitleView : UIView

@property (nonatomic, strong) UIImageView    *iconView;
@property (nonatomic, strong) AULabel        *titleLabel;

- (instancetype)initWithIcon:(UIImage *)icon title:(NSString *)title;

@end

#endif//程序自动生成
