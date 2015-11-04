//
//  ECBHTTPURLRequestConstructor.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/1/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

static NSString * const ECBHeaderNameSessionToken  = @"X-Session-Token";
static NSString * const ECBHeaderNameUserId        = @"X-User-Id";
static NSString * const ECBHeaderClientUniqueId    = @"X-Client-Unique-Id";

@interface ECBHTTPURLRequestConstructor : NSObject

/*!
 Construct a mutable URL Request.
 
 @param url         Request URL
 @param httpMethod  HTTP method
 @param httpHeaders HTTP header parameters
 @param parameters  HTTP body parameters
 */
+ (NSMutableURLRequest *)urlRequestWithURL:(nonnull NSString *)url
                                httpMethod:(nonnull NSString *)httpMethod
                               httpHeaders:(nullable NSDictionary *)httpHeaders
                                parameters:(nullable NSDictionary *)parameters;

NS_ASSUME_NONNULL_END

@end
