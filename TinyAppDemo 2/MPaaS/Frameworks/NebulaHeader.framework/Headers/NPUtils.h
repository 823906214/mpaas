//
//  NPUtils.h
//  NebulaPlugins
//
//  Created by theone on 16/9/1.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NPUtils : NSObject
+ (void)reportReqStart:(UIViewController *)vc;
+ (void)reportReqEnd:(UIViewController *)vc;
+ (void)reportLocStart:(UIViewController *)vc;
+ (void)reportLocEnd:(UIViewController *)vc;
+ (void)addVCCodeSnippet:(UIViewController *)vc code:(NSString *)code key:(NSString *)key;
+ (id)getProxyExpando:(NBViewControllerProxy *)proxy key:(NSString *)key clsName:(NSString *)clsName ;
+ (NSData *)getSourceDataFromCacheWithUrl:(NSURL *)url session:(NBSession *)session;
+ (NSDictionary *)getLocalIdAndTypeFromLocalUrl:(NSString *)url;
+ (NSString *)crateUrlWithLocalId:(NSString *)localId type:(NSString *)type;
+ (NSString *)contentTypeForImageData:(NSData *)data;
+ (void)saveMapRelationToShareDB:(NSString *)key value:(NSString *)value;
+ (NSString *)getMapRelationVal:(NSString *)key;
+ (void)removeMapRelationVal:(NSString *)key;
+ (NSString *)getFallbackUrlWithApp:(PSDSession *)session url:(NSURL *)url;

+ (PSDScene *)getSceneWithViewId:(NSString *)viewId withSession:(PSDSession *)session;

//+ (UIImage *)snapShotWithSize:(CGSize)size view:(UIView *)view isWK:(BOOL)isWK;

+ (NSString *)SWUserAgent;

+ (NSURL *)getAppexFrameworkFallbackUrl:(NSString *)url;
+ (NSDictionary *)appexFrameworkFallbackUrlList;
@end
