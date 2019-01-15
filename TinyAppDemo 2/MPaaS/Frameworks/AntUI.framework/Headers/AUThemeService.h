//
//  AUThemeService.h
//  AntUI
//
//  Created by 莜阳 on 2017/6/28.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#import "AUThemeManager.h"

#define AU_THEME_1              @"themes/theme1.strings"
#define AU_THEME_2              @"themes/theme2.strings"
#define AU_BUNDLE_NAME          @"APCommonUI"

@interface AUThemeService : NSObject

+ (AUThemeService *)themeService;

// 设置某一bundle当前主题
+ (void)setCurrentThemeName:(NSString *)themeName inBundle:(NSString *)bundleName;

// 指定更新某一bundle下的主题
+ (void)updateThemes:(NSDictionary *)themes;

+ (id)themeForKey:(NSString *)key inBundle:(NSString *)bundle;

// 当前bundle下的主题
+ (AUTheme *)currentThemeInBundle:(NSString *)bundle;

// 当前bundle的当前主题名称(主题名称即配置文件名称)
+ (NSString *)currentThemeName:(NSString *)bundle;

+ (NSDictionary*)loadStaticTheme;

@end


