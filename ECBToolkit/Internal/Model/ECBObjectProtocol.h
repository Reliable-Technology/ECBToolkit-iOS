//
//  ECBObjectProtocol.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/3/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 Provides a general interface for serializing object
 */
@protocol ECBObjectProtocol <NSObject>

///--------------------------------------
/// @name Validation
///--------------------------------------

/*!
 Called during parsing from a JSON string. This will determine if the eComBid-API
 produces the same payload as expected by the client.
 
 @returns A boolean to see if object is valid or not
 */
- (BOOL)isValid;

@end