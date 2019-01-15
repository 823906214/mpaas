//
//  APPhotoPickerSceneHelper.h
//  BeeHive
//
//  Created by Yanzhi on 15/6/2.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef _SUPPORT_CHAT_SCENE
static BOOL     isSocialChatScene;
#endif
static NSString *confirmButtonTitle;

@interface BEEPhotoPickerSceneHelper : NSObject

#ifdef _SUPPORT_CHAT_SCENE
+ (void)setIsSocialChatScene:(BOOL)_isSocialChatScene;
#endif

+ (UIImage *)originSelectImageWithSocailChatScene;

+ (UIImage *)selectImageWithSocailChatScene;

+ (NSString *)confirmButtonTitle;

+ (void)setConfirmButtonTitle:(NSString *)_confirmButtonTitle;

@end
