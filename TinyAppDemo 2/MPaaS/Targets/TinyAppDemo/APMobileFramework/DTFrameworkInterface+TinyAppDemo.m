//
//  DTFrameworkInterface+TinyAppDemo.m
//  TinyAppDemo
//
//  Created by quinn on 2018/07/23. All rights reserved.
//

#import "DTFrameworkInterface+TinyAppDemo.h"
#import <MASSChannel/MASSAccess.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wobjc-protocol-method-implementation"

@implementation DTFrameworkInterface (TinyAppDemo)

+ (void)load {
    // 小程序包要求，必须在+()load方法中注册jsapi
    NSString *filePath = [[NSBundle mainBundle].bundlePath stringByAppendingFormat:@"/%@/%@", @"DemoPlugins.bundle", @"Poseidon-Extra-Config.plist"];
    [NBServiceConfigurationGet() setExtraPluginsFilePath:filePath];
}

- (BOOL)shouldLogReportActive
{
    return YES;
}

- (NSTimeInterval)logReportActiveMinInterval
{
    return 0;
}

- (BOOL)shouldLogStartupConsumption
{
    return YES;
}

- (BOOL)shouldAutoactivateBandageKit
{
    return YES;
}

- (BOOL)shouldAutoactivateShareKit
{
    return YES;
}

- (DTNavigationBarBackTextStyle)navigationBarBackTextStyle
{
    return DTNavigationBarBackTextStyleAlipay;
}

- (void)application:(UIApplication *)application beforeDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // 启动netctrl
    [[MASSAccess shareInstance] dispatchTokenSvrInfo:nil uploadInfo:nil downloadInfo:nil downloadInfoCrypto:nil configStorage:nil];
}

- (void)application:(UIApplication *)application afterDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    [self configNebulaSDK];
    NSDictionary *installedApps = [NAMServiceGet() installApps:nil];
    NSMutableDictionary *requestAllApp = [NSMutableDictionary dictionaryWithDictionary:installedApps];
    [requestAllApp setValue:@"0" forKey:@"nebula-*-all"];
    [[NBServiceGet() appCenter] requestApps:requestAllApp param:@{@"force":@YES} finish:^(NSDictionary *data, NSError *error) {
    }];
    
}

- (void)configNebulaSDK
{
    // 控件创建：指定H5页面的基类和 webView 的基类
    [NBServiceConfigurationGet() setViewControllerClass:[H5WebViewController class]]; // 小程序包中H5页面的基类必须是H5WebViewController 的子类
    [NBServiceConfigurationGet() setContentViewClass:[UIWebView class]];
    
    // 包管理服务器配置(没有包管理服务器时不要设置如下项)
    NSString *version = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"Product Version"];
    [NBServiceConfigurationGet() setClientVersion:version];  // 指定当前应用的版本号，mPaaS框架中，请保持工程 Build Version 与 Product Version 一致
    NSString *bundleId = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleIdentifier"];
    [NBServiceConfigurationGet() setClientBundleId:bundleId];   // 指定当前应用的 bundle ID
    [NBServiceConfigurationGet() setUserAgent:[NSString stringWithFormat:@"TinyApp/%@", version]];//指定userAgent
    
    // 预置包配置（可以脱离包管理服务器）
    [NBServiceConfigurationGet().appConfig setPresetApplistPath:[[NSBundle mainBundle] pathForResource:[NSString stringWithFormat:@"DemoPresetApps.bundle/NAMApplist.plist"] ofType:nil]];  // 指定预置离线包的包信息文件路径
    [NBServiceConfigurationGet().appConfig setPresetAppPackagePath:[[NSBundle mainBundle] pathForResource:@"DemoPresetApps.bundle" ofType:nil]];   // 指定预置离线包的包路径
    
    // 离线包管理设置（验签公钥、公共资源包、离线包下载器）
    [NBServiceConfigurationGet() setCommonResourceAppList:@[@"66666692"]];  // 设置小程序依赖的公共资源包：66666692（必填）；如有普通离线包依赖的公共资源包如77777777，也需设置（可选）
    NSString *pubpem = [[NSBundle mainBundle] pathForResource:@"public_key" ofType:@"pem"];
    [NBServiceConfigurationGet().appConfig setSignPublicKey: [NSString stringWithContentsOfFile:pubpem encoding:NSUTF8StringEncoding error:nil]];  // 指定离线包验签的公钥
    [NBServiceConfigurationGet() setIsNeed2VerifyApp:NO];    // 关闭验签
    [NBServiceConfigurationGet().appConfig setRequestManager:[NARequestManager sharedInctance]];  //指定离线包的下载器
    
    // 监控委托，添加H5页面的自动化埋点
    NBLogConfigurationGet().shouldInjectSPMJS=YES;
    [NBLogServiceGet() start];
    [[NBMonitor defaultMonitor] setDelegate:NBLogServiceGet()];
    
    // 启动服务
    NAMServiceGet();
    [NBServiceGet() start];
}

@end

#pragma clang diagnostic pop

