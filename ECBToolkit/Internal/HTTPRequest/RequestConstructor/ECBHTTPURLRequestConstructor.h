//
//  ECBHTTPURLRequestConstructor.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/1/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ECBHTTPURLRequestConstructor : NSObject

/*!
 Construct a mutable URL Request.
 
 @param url         Request URL
 @param httpMethod  HTTP method
 @param httpHeaders HTTP header parameters
 @param parameters  HTTP body parameters
 */
+ (NSMutableURLRequest *)urlRequestWithURL:(NSURL *)url
                                httpMethod:(NSString *)httpMethod
                               httpHeaders:(NSDictionary *)httpHeaders
                                parameters:(NSDictionary *)parameters;

@end
