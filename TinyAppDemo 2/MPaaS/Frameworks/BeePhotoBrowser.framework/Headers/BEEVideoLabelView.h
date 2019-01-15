//
//  APVideoLabelView.h
//  BeeHive
//
//  Created by Yanzhi on 15/8/16.
//  Copyright (c) 2015年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface BEEVideoLabelView : UIView {}

@property (nonatomic, strong)         UIImageView     *videoImageView;
@property (nonatomic, strong)         UILabel         *videoTimeLabel;
@property (nonatomic, copy, readonly) NSString        *videoTime;

- (void)buildSubViews;

- (void)setVideoTimeWithNumber:(NSNumber *)number;
- (void)setVideoImage:(UIImage *)image timeString:(NSString *)timeString;

@end
