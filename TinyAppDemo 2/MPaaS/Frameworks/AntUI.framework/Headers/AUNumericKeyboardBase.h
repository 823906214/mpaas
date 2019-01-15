#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_keyboards_AUNumKeyboards//程序自动生成
//
//  AUNumericKeyboardBase.h
//  AntUI
//
//  Created by QiXin on 2016/9/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AUNumKeyboardsDefs.h"

@interface AUNumericKeyboardBase : UIView
{
@protected
    CGFloat _keyboardHeight;
    NSInteger _keyboardKeyCount;
    CGFloat _numericButtonLayoutWidth;
    CGFloat _numericButtonLayoutHeight;

    // 真正布局的内容区
    UIView *_contentView;
    UIColor *_sepratorLineColor;
    
    @package
    // 键盘的输入目标
    __weak id<UITextInput> _input;
}

@property (nonatomic, strong) NSMutableArray *buttons;

//初始化数据成员
- (void)configurerMembers;
//构造所有按钮键
- (void)createButtons;
//释放所有观察者
- (void)free;
//设置键盘按钮需要enable
- (void)setButtonEnable:(bool)flag;

@end

#endif//程序自动生成
