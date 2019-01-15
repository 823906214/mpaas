//
//  APTableViewDataSource.h
//  APCommonUI
//
//  Created by WenBi on 13-12-4.
//  Copyright (c) 2013年 WenBi. All rights reserved.
//

@class APTableSection;
@class APTableRow;


@protocol APTableViewDataSource <NSObject>

/**
 * A convenient utility method for retrieving the row at specified index path.
 *
 * @param indexPath An index path locating a row in data source.
 * @return The row at specified index path.
 */
- (APTableRow *)rowAtIndexPath:(NSIndexPath *)indexPath;

- (NSArray *)allSections;

@end

@interface APTableViewDataSource : NSObject <UITableViewDataSource, APTableViewDataSource>

/**
 * Inserts a given section at the end of the section array.
 * 
 * @param section The section object to add to the end of section array. This value MUST NOT be nil.
 */
- (void)addSection:(APTableSection *)section;
- (void)addSectionsFromArray:(NSArray *)array;
- (void)registerClass:(Class)cellClass forCellReuseIdentifier:(NSString *)identifier;

@end
