#import "AUUILoadDefine.h"//程序自动生成
#ifdef ANTUI_UI_keyboards_AUNumKeyboards//程序自动生成
//
//  AUNumKeyboardsDefs.h
//  AntUI
//
//  Created by QiXin on 2016/9/26.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#ifndef AUNumKeyboardsDefs_h
#define AUNumKeyboardsDefs_h

typedef void(^AUNumericKeyboardButtonPressBlock) ();
typedef void(^AUNumericKeyboardButtonBlock) (UIView *sender, int keyCode);

typedef enum {
    AUNumericKeyboardButtonNumber1         = 0,
    AUNumericKeyboardButtonBackspace1,
    AUNumericKeyboardButtonReturn1,
    AUNumericKeyboardButtonDismiss1,
    AUNumericKeyboardButtonBlank1,
    AUNumericKeyboardButtonInvalid,
    
    APNumericKeyboardButtonNumber1      __attribute__((deprecated))  = AUNumericKeyboardButtonNumber1, //0,
    APNumericKeyboardButtonBackspace1   __attribute__((deprecated)) = AUNumericKeyboardButtonBackspace1,
    APNumericKeyboardButtonReturn1      __attribute__((deprecated)) = AUNumericKeyboardButtonReturn1,
    APNumericKeyboardButtonDismiss1     __attribute__((deprecated)) = AUNumericKeyboardButtonDismiss1,
    APNumericKeyboardButtonBlank1       __attribute__((deprecated)) = AUNumericKeyboardButtonBlank1,
    
    APNumericKeyboardButtonInvalid      __attribute__((deprecated)) = AUNumericKeyboardButtonInvalid
    
} AUNumericKeyboardButtonType;


typedef enum {
    AUNumericKeyboardButtonKeyCode0         = '0',
    AUNumericKeyboardButtonKeyCode1         = '1',
    AUNumericKeyboardButtonKeyCode2         = '2',
    AUNumericKeyboardButtonKeyCode3         = '3',
    AUNumericKeyboardButtonKeyCode4         = '4',
    AUNumericKeyboardButtonKeyCode5         = '5',
    AUNumericKeyboardButtonKeyCode6         = '6',
    AUNumericKeyboardButtonKeyCode7         = '7',
    AUNumericKeyboardButtonKeyCode8         = '8',
    AUNumericKeyboardButtonKeyCode9         = '9',
    AUNumericKeyboardButtonKeyCodeRadix     = '.',
    AUNumericKeyboardButtonKeyCodeX         = 'X',
    AUNumericKeyboardButtonKeyCodeP         = '-',
    
    
    AUNumericKeyboardButtonKeyCodeBackspace = 10,
    AUNumericKeyboardButtonKeyCodeReturn    = 11,
    AUNumericKeyboardButtonKeyCodeDismiss   = 12,
    AUNumericKeyboardButtonKeyCodeBlank     = 13,
    
    AUNumericKeyboardButtonKeyCodeInvalid   = -1,
    
    APNumericKeyboardButtonKeyCode0    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode0,
    APNumericKeyboardButtonKeyCode1    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode1,
    APNumericKeyboardButtonKeyCode2    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode2,
    APNumericKeyboardButtonKeyCode3    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode3,
    APNumericKeyboardButtonKeyCode4    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode4,
    APNumericKeyboardButtonKeyCode5    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode5,
    APNumericKeyboardButtonKeyCode6    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode6,
    APNumericKeyboardButtonKeyCode7    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode7,
    APNumericKeyboardButtonKeyCode8    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode8,
    APNumericKeyboardButtonKeyCode9    __attribute__((deprecated))     = AUNumericKeyboardButtonKeyCode9,
    APNumericKeyboardButtonKeyCodeRadix  __attribute__((deprecated))   = AUNumericKeyboardButtonKeyCodeRadix,
    APNumericKeyboardButtonKeyCodeX      __attribute__((deprecated))   = AUNumericKeyboardButtonKeyCodeX,
    
    
    APNumericKeyboardButtonKeyCodeBackspace __attribute__((deprecated)) = AUNumericKeyboardButtonKeyCodeBackspace,
    APNumericKeyboardButtonKeyCodeReturn    __attribute__((deprecated)) = AUNumericKeyboardButtonKeyCodeReturn,
    APNumericKeyboardButtonKeyCodeDismiss   __attribute__((deprecated)) = AUNumericKeyboardButtonKeyCodeDismiss,
    APNumericKeyboardButtonKeyCodeBlank     __attribute__((deprecated)) = AUNumericKeyboardButtonKeyCodeBlank,
    
    APNumericKeyboardButtonKeyCodeInvalid   __attribute__((deprecated)) = AUNumericKeyboardButtonKeyCodeInvalid
    
} AUNumericKeyboardButtonKeyCodeType;



// 存储每个键盘按钮信息的结构
typedef struct {
    int keyCode;
    CGRect	frame;
    AUNumericKeyboardButtonType keyType;
    BOOL hidePressLightStyle;
} AUNumericKeyboardKeyExInfo;

#define DEVICE_IS_IPHONE4 ([[UIScreen mainScreen] bounds].size.height == 480)
#define DEVICE_IS_IPHONE5 ([[UIScreen mainScreen] bounds].size.height == 568)
#define DEVICE_IS_IPHONE6 ([[UIScreen mainScreen] bounds].size.height == 667)
#define DEVICE_IS_IPHONE6Pluc ([[UIScreen mainScreen] bounds].size.height == 736)

#define AUNumericKeyboardLineSize() \
if (DEVICE_IS_IPHONE6Pluc) {\
return 1.1 / 3;         \
}                           \
return 1. / 2;              \


#endif /* AUNumKeyboardsDefs_h */

#endif//程序自动生成
