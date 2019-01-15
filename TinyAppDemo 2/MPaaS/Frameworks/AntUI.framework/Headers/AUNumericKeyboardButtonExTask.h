#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_keyboards_AUNumKeyboards//程序自动生成
//
//  AUNumericKeyboardButtonExTask.h
//  AntUI
//
//  Created by QiXin on 2016/9/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import "AUNumericKeyboardButtonEx.h"

@interface AUNumericKeyboardButtonNumberTask : AUNumericKeyboardButtonBase

@property (nonatomic, copy) AUNumericKeyboardButtonBlock block;

@end

@interface AUNumericKeyboardButtonBlankTask : AUNumericKeyboardButtonBase
@end

@interface AUNumericKeyboardButtonBackspaceTask : AUNumericKeyboardButtonBase

@property (nonatomic, copy) AUNumericKeyboardButtonBlock block;

@end

@interface AUNumericKeyboardButtonFactory (Task)

+ (AUNumericKeyboardButtonBase *)createButtonTaskWithType:(AUNumericKeyboardKeyExInfo)info;

@end

#endif//程序自动生成
