//
//  APThemeScreenCategory.h
//  APCommonUI
//
//  Created by shenmo on 10/10/15.
//  Copyright © 2015 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM (NSInteger, APThemeScreenCategory)
{
    APThemeScreenNone = 0,
    APThemeScreenPadLow,        // 非Retina的iPad
    APThemeScreenPadRetina,
    APThemeScreenPhoneLow,      // 非Retina的iPhone
    APThemeScreenPhone4,
    APThemeScreenPhone5,
    APThemeScreenPhone6,
    APThemeScreenPhone6p,
};

// 当前设备的屏幕类型
extern APThemeScreenCategory APDeviceScreenCategory();