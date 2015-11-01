//
//  ECBUtils.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/1/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ECBUtils : NSObject

///--------------------------------------
/// @name Common
///--------------------------------------

/*!
 Checks an input string to see if empty or null.
 
 @param string Input string
 @returns A boolean true if string empty, otherwise false
 */
+ (BOOL)isNotEmptyString:(NSString *)string;

@end
