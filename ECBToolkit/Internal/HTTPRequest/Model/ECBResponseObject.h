//
//  ECBResponseObject.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/2/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 `ECBResponseObject` is a container object of all responses from the eComBid-API. 
 It encapsulates the result, and properties about the response status.
 */
@interface ECBResponseObject : NSObject

/*!
 @abstract Response result, can be either a NSDictionary or NSArray
 */
@property (nonatomic, strong, readonly) id result;

/*!
 @abstract Whether the response is success or not
 */
@property (nonatomic, assign, readonly) BOOL isSuccess;

/*!
 @abstract Response status code
 */
@property (nullable, nonatomic, copy, readonly) NSString *statusCode;

/*!
 @abstract Response status message
 */
@property (nullable, nonatomic, copy, readonly) NSString *statusMessage;

///--------------------------------------
/// @name Init
///--------------------------------------

/*!
 Creates a new `ECBResponseObject` container object.
 
 @param result          The response result object
 @param isSuccess       The flag to indicate response is success or not
 @param statusCode      The response status code
 @param statusMessage   The response status message
 
 @returns A new `ECBResponseObject`
 */
+ (instancetype)reponseObjectWithResult:(id)result
                              isSuccess:(BOOL)isSuccess
                             statusCode:(NSString *)statusCode
                          statusMessage:(NSString *)statusMessage;

@end

NS_ASSUME_NONNULL_END
