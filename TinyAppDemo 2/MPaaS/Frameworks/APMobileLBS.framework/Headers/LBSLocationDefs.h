//
//  LBSLocationDefs.h
//  APMobileLBS
//
//  Created by 去疾 on 17/3/7.
//  Copyright © 2017年 Alipay. All rights reserved.
//

#ifndef LBSLocationDefs_h
#define LBSLocationDefs_h

typedef NS_ENUM(NSInteger, APCoreLocationCacheAvaliable) {
    APCoreLocationCacheAvaliableNone=0,
    APCoreLocationCacheAvaliableFiveSeconds=5,
    APCoreLocationCacheAvaliableTenSeconds=10,
    APCoreLocationCacheAvaliableDefault = 30,
    APCoreLocationCacheAvaliableSixty = 60,
    APCoreLocationCacheAvaliableOneHundredATwenty= 120,
    APCoreLocationCacheAvaliableTwoHundredAfourty = 240,
};

typedef NS_ENUM(NSInteger, APCoreLocationReGeoType) {
    APCoreLocationReGeoTypeReverse,
    APCoreLocationReGeoTypeReGeoCode,
    APCoreLocationReGeoTypeReGeoCodeToCity,
    APCoreLocationReGeoTypeReGeoCodeAll
};

typedef NS_ENUM(NSInteger, LBSLocationReGeoLevel) {
    LBSLocationReGeoLevelCountry = 2,
    LBSLocationReGeoLevelProvince ,
    LBSLocationReGeoLevelCity ,
    LBSLocationReGeoLevelDistrict ,
    LBSLocationReGeoLevelTown ,
    LBSLocationReGeoLevelStreet ,
    LBSLocationReGeoLevelStreetWithPOIs ,
};


typedef NS_ENUM(NSInteger, APCoreLocationErrorCode) {
    APCoreLocationErrorCodeSuccess = 0,
    APCoreLocationErrorCodeTimeOut = 100,               //超时时间内没有可用位置
    APCoreLocationErrorCodeLocation,                    //系统错误，新版本不会再有
    APCoreLocationErrorCodeReGeoCode,                   //逆地理失败
    APCoreLocationErrorCodeWifiLocation,                //wifi补偿定位失败
    APCoreLocationErrorCodeOptimization,                //位置纠偏失败，不会影响结果
    APCoreLocationErrorCodeAuthorization,               //无权限
    APCoreLocationErrorCodeBackgourndTimeout,           //后台定位失败，如果应用在后台，目前的权限定位必然会失败
    APCoreLocationErrorCodeBiztypeInBlacklist,          //业务标识在黑名单中
    APCoreLocationErrorCodeCancel                       //业务中途取消
};




#endif /* LBSLocationDefs_h */
