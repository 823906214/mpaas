#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_PopMenu_AUPopMenu//程序自动生成
//
//  AUPopItemBaseView.h
//  AntUI
//
//  Created by niki on 2017/6/19.
//  Copyright © 2017年 Alipay. All rights reserved.
//

// 对象模型
@interface AUPopItemModel : NSObject

@property (nonatomic, strong) NSString *titleString;    // 主文案描述
@property (nonatomic, strong) id iconImage;             // 左侧icon，可以传UIImage 对象或者 URL

@end


//
@interface AUPopItemBaseView : UIControl

@property (nonatomic, strong) AULabel *titleLabel; //

@end

#endif//程序自动生成
