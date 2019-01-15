//
//  APTableSection.h
//  APCommonUI
//
//  Created by WenBi on 13-12-4.
//  Copyright (c) 2013年 WenBi. All rights reserved.
//

@class APTableRow;

@interface APTableSection : NSObject

@property(nonatomic, assign) CGFloat height;

+ (APTableSection *)sectionWithTitle:(NSString *)title;
+ (APTableSection *)sectionWithImage:(UIImage *)image;

- (id)initWithTitle:(NSString *)title;
- (id)initWithImage:(UIImage *)image;
- (id)initWithCustomView:(UIView *)customView;

- (UITableViewHeaderFooterView *)viewForTableView:(UITableView *)tableView;

- (UITableViewHeaderFooterView *)viewForHeaderInTableView:(UITableView *)tableView;
- (UITableViewHeaderFooterView *)viewForFooterInTableView:(UITableView *)tableView;

- (CGFloat)heightForHeaderInTableView:(UITableView *)tableView inSection:(NSInteger)section;
- (CGFloat)heightForFooterInTableView:(UITableView *)tableView inSection:(NSInteger)section;

- (NSArray *)allRows;

- (APTableRow *)rowAtIndex:(NSUInteger)index;

- (void)addRow:(APTableRow *)row;
- (void)addRowsFromArray:(NSArray *)array;

@end
