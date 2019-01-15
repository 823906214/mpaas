//
//  APTableRow.h
//  APCommonUI
//
//  Created by WenBi on 13-12-6.
//  Copyright (c) 2013年 WenBi. All rights reserved.
//

#import <UIKit/UIKit.h>

@class UITableViewCell;

@interface APTableRow : NSObject

@property(nonatomic, assign, readonly) CGFloat cellHeight;

/**
 *  Creates a new cell that the table view row manages.
 *
 *  @return The newly created cell that the row manages.
 */
- (UITableViewCell *)cellForTableView:(UITableView *)tableView;

- (void)updateCell:(UITableViewCell *)cell;

@end

