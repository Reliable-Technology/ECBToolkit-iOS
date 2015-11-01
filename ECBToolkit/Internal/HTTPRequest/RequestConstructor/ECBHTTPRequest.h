//
//  ECBHTTPRequest.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/1/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#ifndef ECBHTTPRequest_h
#define ECBHTTPRequest_h

#import <Foundation/Foundation.h>

static NSString * const ECBHTTPRequestMethodGET                 = @"GET";
static NSString * const ECBHTTPRequestMethodHEAD                = @"HEAD";
static NSString * const ECBHTTPREquestMethodDELETE              = @"DELETE";
static NSString * const ECBHTTPRequestMethodPOST                = @"POST";
static NSString * const ECBHTTPRequestMethodPUT                 = @"PUT";

static NSString * const ECBHTTPRequestHeaderNameContentType     = @"Content-Type";
static NSString * const ECBHTTPRequestHeaderNameContentLength   = @"Content-Length";

static NSString * const ECBHTTPURLRequestContentTypeJSON        = @"application/json; charset=utf-8";
static NSString * const ECBHTTPURLRequestContentTypeXML         = @"application/xml; charset=utf-8";
static NSString * const ECBHTTPURLRequestContentTypeOctetStream = @"binary/octet-stream";

#endif /* ECBHTTPRequest_h */
