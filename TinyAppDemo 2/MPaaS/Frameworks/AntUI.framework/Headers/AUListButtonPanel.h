#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_BaseComponent_AUListButtonPanel//程序自动生成
//
//  AUListButtonPanel.h
//  AntUI
//
//  Created by 莜阳 on 2017/12/1.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol AUListButtonPanelDelegate;

/*
 * 展示在列表上的button面板
 */

@interface AUListButtonPanel : UIControl

@property(nonatomic,strong) NSArray *titles;
@property(nonatomic,strong) id <AUListButtonPanelDelegate>delegate;

- (instancetype)initWithButtonTittles:(NSArray *)titles;

@end



@protocol AUListButtonPanelDelegate <NSObject>

@optional
- (void)didClickButtonAtIndex:(NSInteger)index title:(NSString *)title;

@end

#endif//程序自动生成
