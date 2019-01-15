//
//  APTextureView.h
//  APMultimedia
//
//  Created by Cloud on 15/9/15.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface APMTextureView : UIView

/**
 *  要展示的texture的长和宽
 */
@property (nonatomic, assign) CGSize dimension;

/**
 *  纹理是否需要上下颠倒，默认是YES
 */
@property (nonatomic, assign) BOOL needsFlip;

/**
 *  因为GPU在后台时无法使用，所以此时如果还继续render的话，需要传入NO，禁止render
 *  默认是YES
 */
@property (nonatomic, assign) BOOL renderingEnabled;

/**
 *  渲染纹理到view上
 *
 *  @param texture 需要渲染的纹理
 *  @param context 和纹理绑定的context
 */
- (void)render:(GLuint)texture context:(EAGLContext *)context;

@end
