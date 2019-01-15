//
//  AUThemeService+AUServiceUtils.h
//  AntUI
//
//  Created by 莜阳 on 2018/1/2.
//  Copyright © 2018年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AUThemeService (AUServiceUtils)

//
+ (NSString *)themePathSuffix:(NSString *)themeName;

//
+ (NSString *)widthAdaptorByThemePath:(NSString *)themeName;

//
+ (NSString *)widthHeightAdaptorByThemePath:(NSString *)themeName;

+ (BOOL)isBundlePath:(NSString *)url;

+ (void)checkAutoRefreshViewLayout:(NSDictionary *)themeInfo;

@end

@interface AUThemeRefrenceObj : NSObject

@property (nonatomic, weak) UIViewController *viewController;
@property (nonatomic, strong) NSString *vcName;

@end
