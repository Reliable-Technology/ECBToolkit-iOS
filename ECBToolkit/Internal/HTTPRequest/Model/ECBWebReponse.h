//
//  ECBWebReponse.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/2/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 `ECBWebReponse` is a container object of all responses from the eComBid-API.
 It encapsulates the result, and properties about the response status.
 */
@interface ECBWebReponse : NSObject

/*!
 @abstract Response result, can be either a NSDictionary or NSArray
 */
@property (nonatomic, strong, readonly) id result;

/*!
 @abstract Whether the response is success or not
 */
@property (nonatomic, assign, readonly) BOOL isSuccess;

/*!
 @abstract Header status code
 */
@property (nonatomic, assign, readonly) NSInteger headerStatusCode;

/*!
 @abstract Header fields
 */
@property (nonnull, nonatomic, copy, readonly) NSDictionary* allHeaderFields;

/*!
 @abstract Header status message
 */
@property (nullable, nonatomic, copy, readonly) NSString *statusMessage;

///--------------------------------------
/// @name Init
///--------------------------------------

/*!
 Creates a new `ECBWebReponse` container object.
 
 @param result          Response result object
 @param isSuccess       Flag to indicate response is success or not
 @param statusCode      HTTP header status code
 @param allHeaderFields All header fields
 @param errorMessage    Header status message
 
 @returns A new `ECBWebReponse`
 */
+ (instancetype)reponseObjectWithResult:(id)result
                              isSuccess:(BOOL)isSuccess
                             statusCode:(NSInteger)statusCode
                        allHeaderFields:(NSDictionary *)allHeaderFields
                          statusMessage:(NSString *)statusMessage;

@end

NS_ASSUME_NONNULL_END
