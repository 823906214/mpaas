//
//  APSKChannel.h
//  APSKClient
//
//  Created by WenBi on 14-1-9.
//  Copyright (c) 2014年 WenBi. All rights reserved.
//

/**
 * @addtogroup APSKClient
 * @{
 */

/**
 * @defgroup APSKChannelNames Sharing channel names
 * @{
 */

/** 分享到微博 */
extern NSString * const kAPSKChannelWeibo;

/** 通过邮件分享-暂不支持 */
extern NSString * const kAPSKChannelEmail;

/** 通过短信分享 */
extern NSString * const kAPSKChannelSMS;

/** 复制链接 */
extern NSString * const kAPSKChannelCopyLink;

/** 微信 */
extern NSString * const kAPSKChannelWeixin;

/** 微信朋友圈*/
extern NSString * const kAPSKChannelWeixinTimeLine;

/** 支付宝联系人*/
extern NSString * const kAPSKChannelALPContact;

/** 支付宝生活圈*/
extern NSString * const kAPSKChannelALPTimeLine;

/** QQ好友 */
extern NSString * const kAPSKChannelQQ;

/** QQ空间 */
extern NSString * const kAPSKChannelQQZone;


/** 钉钉会话 */
extern NSString * const kAPSKChannelDingTalkSession;





/**
 *  分享到支付宝联系人拓展扩展字段key值 (message.extraInfo中的key值)
 */

////////////////////////////////////股票//////////////////////////

/**
 *  股票名
 */
extern NSString * const kAPSKExtraInfoStockNameKey;

/**
 *  股票代码
 */
extern NSString* const kAPSKExtraInfoStockCodeKey;

/**
 *  股票价格
 */
extern NSString * const kAPSKExtraInfoStockPriceKey;

/**
 *  股票盈亏
 */
extern NSString * const kAPSKExtraInfoStockPriceChangeKey;

/**
 *  股票盈亏率
 */
extern NSString * const kAPSKExtraInfoStockPriceChangeRatioKey;

/**
 *  股票时间
 */
extern NSString * const kAPSKExtraInfoStockTimeKey;

/**
 *  股票涨跌状态
 */
extern NSString * const kAPSKExtraInfoStockIncreaseStateKey;



////////////////////////////////////基金//////////////////////////

/**
 *  基金名
 */
extern NSString * const kAPSKExtraInfoFundNameKey;

/**
 *  基金代码
 */
extern NSString * const kAPSKExtraInfoFundCodeKey;

/**
 *  基金价格
 */
extern NSString * const kAPSKExtraInfoFundPriceKey;

/**
 *  基金日涨幅文字
 */
extern NSString * const kAPSKExtraInfoFundDailyDescKey;

/**
 *  基金周涨幅文字
 */
extern NSString * const kAPSKExtraInfoFundWeeklyDescKey;

/**
 *  基金日涨幅数字
 */
extern NSString * const kAPSKExtraInfoFundDailyRatioKey;

/**
 *  基金周涨幅数字
 */
extern NSString * const kAPSKExtraInfoFundWeeklyRatioKey;

/**
 *  基金时间
 */
extern NSString * const kAPSKExtraInfoFundTimeKey;

/**
 *  基金标签LabelText
 */
extern NSString * const kAPSKExtraInfoFundLabelTextKey;

/**
 *  基金扩展字段
 */
extern NSString * const kAPSKExtraInfoFundExtendKey;

/**
 *  基金价格显示的颜色
 */
extern NSString * const kAPSKExtraInfoFundPriceColorKey;

/**
 *  基金日涨幅文字显示的颜色
 */
extern NSString * const kAPSKExtraInfoFundDailyDescColorKey;

/**
 *  基金周涨幅文字显示的颜色
 */
extern NSString * const kAPSKExtraInfoFundWeeklyDescColorKey;

/**
 *  基金日涨幅数字显示的颜色
 */
extern NSString * const kAPSKExtraInfoFundDailyRatioColorKey;

/**
 *  基金周涨幅数字显示的颜色
 */
extern NSString * const kAPSKExtraInfoFundWeeklyRatioColorKey;

/**
 *  基金时间显示的颜色
 */
extern NSString * const kAPSKExtraInfoFundTimeColorKey;

/**
 *  基金标签显示的颜色
 */
extern NSString * const kAPSKExtraInfoFundLabelColorKey;


typedef NS_ENUM(NSUInteger, APSKExtraInfoColor) {
    /**
     *  通用颜色
     */
    APSKExtraInfoColorDefaut = 0,
    
    /**
     *  红色
     */
    APSKExtraInfoColorRed    = 1,
    
    /**
     *  绿色
     */
    APSKExtraInfoColorGreen  = 2,
    
    /**
     *  灰色
     */
    APSKExtraInfoColorGray   = 3
};


/**
 *  End  拓展扩展字段key值
 */
