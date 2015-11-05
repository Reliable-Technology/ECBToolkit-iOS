//
//  ECBWebClient.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/1/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ECBWebRequest.h"
#import "ECBWebReponse.h"
#import "ECBWebCallback.h"
#import "ECBHTTPRequest.h"
#import "ECBHTTPURLRequestConstructor.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, ECBRequestOptions)
{
    ECBRequestOptionNoRetry = 0,
    ECBRequestOptionRetryIfFailed = 1 << 0
};

static NSTimeInterval const ECBRequestDefaultRetryDelay = 1.0;
static uint8_t const ECBRequestDefaultMaxAttemptsCount  = 5;

///--------------------------------------
/// @name ECBWebClient
///--------------------------------------

@interface ECBWebClient : NSObject

@property (nonatomic, assign) BOOL allowInvalidCertificates;

- (void)performRequest:(ECBWebRequest *)requestObject
              callback:(ECBWebCallback *)callback;

- (void)performRequest:(ECBWebRequest *)requestObject
               options:(ECBRequestOptions)options
              callback:(ECBWebCallback *)callback;

@end

NS_ASSUME_NONNULL_END
