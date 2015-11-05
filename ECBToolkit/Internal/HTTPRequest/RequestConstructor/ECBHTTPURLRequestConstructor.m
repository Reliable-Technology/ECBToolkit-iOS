//
//  ECBHTTPURLRequestConstructor.m
//  ECBToolkit
//
//  Created by Tony Kieu on 11/1/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBHTTPURLRequestConstructor.h"
#import "ECBHTTPRequest.h"
#import "ECBAssert.h"
#import "ECBSession.h"
#import "ECBDevice.h"

@implementation ECBHTTPURLRequestConstructor

///--------------------------------------
#pragma mark - Public
///--------------------------------------

+ (NSMutableURLRequest *)urlRequestWithURL:(NSString *)url
                                httpMethod:(NSString *)httpMethod
                               httpHeaders:(NSDictionary *)httpHeaders
                                parameters:(NSDictionary *)parameters
{
    NSParameterAssert(url != nil);
    NSParameterAssert(httpMethod != nil);
    
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:url]];
    
    request.HTTPMethod = httpMethod;
    
    // TODO: (tkieu87) Define User Header Fields
    NSMutableDictionary *allHeaderFields = [NSMutableDictionary dictionary];
    [allHeaderFields setObject:[ECBSession current].sessionToken forKey:ECBHeaderNameSessionToken];
    [allHeaderFields setObject:@"" forKey:ECBHeaderNameUserId];
    [allHeaderFields setObject:[ECBDevice currentDevice].deviceUUID forKey:ECBHeaderClientUniqueId];
    [allHeaderFields setObject:ECBHTTPURLRequestContentEncodingGZIP forKey:ECBHTTPRequestHeaderNameContentEncoding];
    [allHeaderFields setObject:ECBHTTPURLRequestContentTypeJSON forKey:ECBHTTPRequestHeaderNameAccept];
    if (httpHeaders) [allHeaderFields addEntriesFromDictionary:httpHeaders];
    
    if (parameters != nil)
    {
        ECBConsistencyAssert([httpMethod isEqualToString:ECBHTTPRequestMethodPOST] ||
                             [httpMethod isEqualToString:ECBHTTPRequestMethodPUT],
                             @"Can't create %@ request with json body.", httpMethod);
        
        [allHeaderFields setObject:ECBHTTPURLRequestContentTypeJSON forKey:ECBHTTPRequestHeaderNameContentType];
        
        NSError *error = nil;
        [request setHTTPBody:[NSJSONSerialization dataWithJSONObject:parameters
                                                             options:(NSJSONWritingOptions)0
                                                               error:&error]];
        
        ECBConsistencyAssert(error == nil, @"Failed to serialize JSON with error = %@", error);
    }
    
    request.allHTTPHeaderFields = allHeaderFields;
    
    return request;
}



@end
