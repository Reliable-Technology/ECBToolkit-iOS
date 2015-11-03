//
//  ECBWebClient.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/1/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ECBRequestObject;
@class ECBResponseObject;
@class ECBWebCallbackObject;

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

@property (nonatomic, assign) BOOL allowSelfSignedCerts;

- (void)performRequest:(ECBRequestObject *)requestObject
              callback:(ECBWebCallbackObject *)callback;

- (void)performRequest:(ECBRequestObject *)requestObject
               options:(ECBRequestOptions)options
              callback:(ECBWebCallbackObject *)callback;

@end

NS_ASSUME_NONNULL_END
