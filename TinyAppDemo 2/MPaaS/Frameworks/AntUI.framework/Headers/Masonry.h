//
//  Masonry.h
//  Masonry
//
//  Created by Jonas Budelmann on 20/07/13.
//  Copyright (c) 2013 cloudling. All rights reserved.
//

#import <Foundation/Foundation.h>

//define this constant if you want to use Masonry without the 'mas_' prefix
//#define MAS_SHORTHAND

//define this constant if you want to enable auto-boxing for default syntax
#define MAS_SHORTHAND_GLOBALS

//! Project version number for Masonry.
FOUNDATION_EXPORT double MasonryVersionNumber;

//! Project version string for Masonry.
FOUNDATION_EXPORT const unsigned char MasonryVersionString[];

#import <AntUI/MASUtilities.h>
#import <AntUI/View+MASAdditions.h>
#import <AntUI/View+MASShorthandAdditions.h>
#import <AntUI/ViewController+MASAdditions.h>
#import <AntUI/NSArray+MASAdditions.h>
#import <AntUI/NSArray+MASShorthandAdditions.h>
#import <AntUI/MASConstraint.h>
#import <AntUI/MASCompositeConstraint.h>
#import <AntUI/MASViewAttribute.h>
#import <AntUI/MASViewConstraint.h>
#import <AntUI/MASConstraintMaker.h>
#import <AntUI/MASLayoutConstraint.h>
#import <AntUI/NSLayoutConstraint+MASDebugAdditions.h>
