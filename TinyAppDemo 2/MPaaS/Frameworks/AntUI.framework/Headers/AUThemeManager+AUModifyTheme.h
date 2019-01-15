//
//  AUThemeManager+AUModifyTheme.h
//  AntUI
//
//  Created by 莜阳 on 2017/6/22.
//  Copyright © 2017年 Alipay. All rights reserved.
//

@interface AUThemeManager (AUModifyTheme)

+ (BOOL)au_curTheme_add_extraInfo:(NSDictionary *)extraInfo;

+ (BOOL)au_curTheme_remove_extraInfo:(NSDictionary *)extraInfo;

@end
