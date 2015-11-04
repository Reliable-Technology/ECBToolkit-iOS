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

///--------------------------------------
/// @name HTTP Methods
///--------------------------------------

static NSString * const ECBHTTPRequestMethodGET                 = @"GET";
static NSString * const ECBHTTPRequestMethodHEAD                = @"HEAD";
static NSString * const ECBHTTPREquestMethodDELETE              = @"DELETE";
static NSString * const ECBHTTPRequestMethodPOST                = @"POST";
static NSString * const ECBHTTPRequestMethodPUT                 = @"PUT";
static NSString * const ECBHTTPRequestMethodPATCH               = @"PATCH";

///--------------------------------------
/// @name HTTP Headers
///--------------------------------------

static NSString * const ECBHTTPRequestHeaderNameContentType     = @"Content-Type";
static NSString * const ECBHTTPRequestHeaderNameContentLength   = @"Content-Length";

static NSString * const ECBHTTPURLRequestContentTypeJSON        = @"application/json; charset=utf-8";
static NSString * const ECBHTTPURLRequestContentTypeXML         = @"application/xml; charset=utf-8";
static NSString * const ECBHTTPURLRequestContentTypeOctetStream = @"binary/octet-stream";

///--------------------------------------
/// @name HTTP Status Codes
///--------------------------------------

static NSInteger const ECBHTTPStatusCodeOK                      = 200;
static NSInteger const ECBHTTPStatusCodeCREATED                 = 201;
static NSInteger const ECBHTTPStatusCodeACCEPTED                = 202;
static NSInteger const ECBHTTPStatusCodeNOCONTENT               = 204;
static NSInteger const ECBHTTPStatusCodeMULTIPLECHOICES         = 300;
static NSInteger const ECBHTTPStatusCodeFORBIDDEN               = 403;
static NSInteger const ECBHTTPStatusCodeNotFound                = 404;
static NSInteger const ECBHTTPStatusCodeMETHODNOTALLOWED        = 405;
static NSInteger const ECBHTTPSTatusCodeCONFLICT                = 409;

#endif /* ECBHTTPRequest_h */
