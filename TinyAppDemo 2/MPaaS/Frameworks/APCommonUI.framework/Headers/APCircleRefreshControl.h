//
//  PPChatRefreshControl.h
//  PPChat
//
//  Created by tgf on 13-11-5.
//  Copyright (c) 2013年 Alipay. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface APCircleRefreshControl : UIControl

- (id)initInScrollView:(UIScrollView *)scrollView;

// Tells the control that a refresh operation was started programmatically
- (void)beginRefreshing;

// Tells the control the refresh operation has ended
- (void)endRefreshing;

@end
