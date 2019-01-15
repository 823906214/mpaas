#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_PopMenu_AUPopMenu//程序自动生成
//
//  AUPopMenu.h
//  AntUI
//
//  Created by niki on 2017/6/14.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AUPopItemView.h"


//#########################################################
//文档地址 : http://aui.alipay.net/develop/ios/aupopmenu
//#########################################################


@protocol AUPopMenuDelegate <NSObject>

@optional
- (void)DidClickPopItemView:(AUPopItemModel *)viewModel;
- (void)DidClickPopItemViewAtIndex:(NSInteger)index itemModel:(AUPopItemModel *)viewModel;

@end

@interface AUPopMenu : UIView

@property (nonatomic, weak) id<AUPopMenuDelegate> delegate;
@property (nonatomic, assign) BOOL isArchViewUp;             // 方向角朝向，默认向上
@property (nonatomic, strong) NSString *bizType;            // 业务标识，须传

/*  datas是 AUPopItemModel 对象列表
 *  position 方向尖角所在位置
 *  superView 所在父view
 */
- (instancetype)initWithDatas:(NSArray<AUPopItemModel *> *)datas
                     position:(CGPoint)position
                    superView:(UIView *)superView;

/*  默认带动画展示和隐藏
 */
- (void)showMenu;

//
- (void)hideMenu;

@end

#endif//程序自动生成
