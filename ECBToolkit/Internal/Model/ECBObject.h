//
//  ECBObject.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/3/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <JSONModel/JSONModel.h>
#import "ECBObjectProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@interface ECBObject : JSONModel

///--------------------------------------
/// @name Object Properties
///--------------------------------------

/*!
 @abstract The name of the object.
 */
@property (nonatomic, strong, readonly) NSString<Optional> *name;

/*!
 @abstract The id of the object.
 */
@property (nullable, nonatomic, strong, readonly) NSString *objectId;

/*!
 @abstract Whether the object is active.
 */
@property (nonatomic, assign, readonly) BOOL isActive;

/*!
 @abstract When the object was last modified.
 */
@property (nullable, nonatomic, strong, readonly) NSDate *dateModified;

/*!
 @abstract When the object was added.
 */
@property (nullable, nonatomic, strong, readonly) NSDate *dateAdded;

@end

NS_ASSUME_NONNULL_END
