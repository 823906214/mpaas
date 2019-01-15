#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_textfields_AUImageInputBox//程序自动生成
//
//  AUImageInputBox.h
//  AntUI
//
//  Created by QiXin on 2016/10/9.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "AUInputBox.h"


//#########################################################
//文档地址 : http://aui.alipay.net/develop/ios/auimageinputbox
//#########################################################


#define UI_AUImageInputBox

/**
 左侧为图标的输入框样式
 文档：http://idoc.alipay.net/article/57fb3bce22ec746a420304e3
 */
@interface AUImageInputBox : AUInputBox

/**
 左侧图标视图（只读）
 */
@property (nonatomic, strong, readonly) UIImageView *iconView;

/**
 设置左侧图标图片
 
 @param image 图标图片
 */
- (void)setIconImage:(UIImage *)image;

@end

#endif//程序自动生成
