//
//  ECBWebClient.m
//  ECBToolkit
//
//  Created by Tony Kieu on 11/1/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "AFNetworking.h"
#import "ECBWebClient.h"
#import "ECBUtils.h"
#import "ECBAssert.h"
#import "ECBRequestObject.h"
#import "ECBApplication.h"
#import "ECBHTTPURLRequestConstructor.h"

@implementation ECBWebClient

///--------------------------------------
#pragma mark - Init
///--------------------------------------

- (id)init
{
    if ((self = [super init]))
    {
        _allowSelfSignedCerts = ![ECBApplication currentApplication].isAppStoreEnvironment;
    }
    return self;
}

///--------------------------------------
#pragma mark - Public
///--------------------------------------

- (void)performRequest:(ECBRequestObject *)requestObject
              callback:(ECBWebCallbackObject *)callback
{
    ECBParameterAssert(requestObject, @"RequestObject can't be null");
    ECBParameterAssert(requestObject.httpPath, @"HTTP Path can't be null");
    ECBParameterAssert(requestObject.httpMethod, @"HTTP Method can't be null");
    
    AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
    manager.securityPolicy.allowInvalidCertificates = self.allowSelfSignedCerts;
    
    NSURLRequest *request = [ECBHTTPURLRequestConstructor urlRequestWithURL:requestObject.httpPath
                                                                 httpMethod:requestObject.httpMethod
                                                                httpHeaders:requestObject.additionalHeaders
                                                                 parameters:requestObject.parameters];

    [manager dataTaskWithRequest:request completionHandler:^(NSURLResponse *response, id responseObject, NSError *error) {
        // Parse Object Here
    }];
}

- (void)performRequest:(ECBRequestObject *)requestObject
               options:(ECBRequestOptions)options
              callback:(ECBWebCallbackObject *)callback
{
    // TODO: (tkieu87) Implement later
}

@end
