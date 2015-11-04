//
//  ECBWebRequest.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/2/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 `ECBWebRequest` is a container object of all requests to the eComBid-API. It encapsulates
 the request URL and method, associated parameters, and caching mechanism.
 */
@interface ECBWebRequest : NSObject

/*!
 @abstract Full request path that contains base URL and endpoint
 */
@property (nonatomic, copy, readonly) NSString *httpPath;

/*!
 @abstract Request method
 */
@property (nonatomic, copy, readonly) NSString *httpMethod;

/*!
 @abstract Request body parameters (only for POST & PUT method)
 */
@property (nullable, nonatomic, copy, readonly) NSDictionary *parameters;

/*!
 @abstract Additional request headers (if any)
 */
@property (nullable, nonatomic, copy) NSDictionary *additionalHeaders;

/*!
 @abstract Request cached key
 */
@property (nonatomic, copy, readonly) NSString *cacheKey;

/*!
 @abstract Request session token
 */
@property (nonatomic, copy, readonly) NSString *sessionToken;

/*!
 @abstract Request used Id
 */
@property (nonatomic, assign, readonly) NSInteger userId;

///--------------------------------------
/// @name Init
///--------------------------------------

/*!
 Creates a new `ECBWebRequest` container object.
 
 @param path            The request url path
 @param method          The request method
 @param parameters      The request body parameters
 @param sessionToken    The request session token
 @param userId          The request user Id
 
 @returns A new `ECBWebRequest`
 */
+ (instancetype)requestObjectWithHTTPPath:(nonnull NSString *)path
                               httpMethod:(nonnull NSString *)method
                               parameters:(nullable NSDictionary *)parameters
                             sessionToken:(nonnull NSString *)sessionToken
                                   userId:(NSInteger)userId;

@end

NS_ASSUME_NONNULL_END
