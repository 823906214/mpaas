//
//  BCRecordSwitchView.h
//  BeeCapture
//
//  Created by noahlu on 16/4/25.
//  Copyright © 2016年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "define_public.h"

@class BCRecordSwitchView;

@protocol BCRecordSwitchViewDelegate <NSObject>

- (void)switchStatusChange:(BCRecordSwitchStatus)status view:(BCRecordSwitchView *)view;

@end

@interface BCRecordSwitchView : UIView

@property (nonatomic, readonly) BCRecordSwitchStatus switchStatus;
@property (nonatomic, weak) id<BCRecordSwitchViewDelegate> delegate;

- (void)switchToStatus:(BCRecordSwitchStatus)status animation:(BOOL)animation;

- (id)initWithFrame:(CGRect)frame switchStatus:(BCRecordSwitchStatus)switchStatus delegate:(id<BCRecordSwitchViewDelegate>)delegate;

@end
