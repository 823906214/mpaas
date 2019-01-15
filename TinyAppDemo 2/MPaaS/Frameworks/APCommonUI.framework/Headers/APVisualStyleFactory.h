//
//  APVisualStyleFactory.h
//  APCommonUI
//
//  Created by WenBi on 14-1-23.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@class APVisualStyle;

/**
 *  样式的工厂类，为指定的view对象创建对应的样式对象。
 */
@interface APVisualStyleFactory : NSObject

/**
 *  Returns a <code>APVisualStyle</code> object with the supplied name.
 *
 *  @param name The name that defines search condition of visual style.
 *
 *  @return The visual style object that matches the conditions defined by the name, if found;
 *  otherwise, the result is nil.
 *
 */
- (APVisualStyle *)visutalStyleForName:(NSString *)aName;

@end
