//
//  ECBUtils.m
//  ECBToolkit
//
//  Created by Tony Kieu on 11/1/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBUtils.h"

@implementation ECBUtils

///--------------------------------------
#pragma mark - Public
///--------------------------------------

+ (BOOL)isNotEmptyString:(NSString *)string
{
    return !(string == nil ||
             [string isKindOfClass:[NSNull class]] ||
             [string isEqualToString:@""]);
}

@end
