//
//  TinyAppCommonDefine.h
//  TinyAppCommon
//
//  Created by 应俊康 on 2017/12/20.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#ifndef TinyAppCommonDefine_h
#define TinyAppCommonDefine_h

#define TALog(format,...) NSLog(@"[TinyApp] %@",  [NSString stringWithFormat:format,## __VA_ARGS__])

#define STR_EMPTY(str) (![str isKindOfClass:[NSString class]]||str.length <= 0)
#define IMAGE_FORMAT_ARRAY @[@"jpeg",@"jpg",@"png",@"gif",@"webp",@"tiff",@"bmp"]


#define kError        @"error"
#define kError_Msg    @"errorMessage"
#endif /* TinyAppCommonDefine_h */
