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
#import "ECBApplication.h"
#import "ECBLogging.h"

@implementation ECBWebClient

///--------------------------------------
#pragma mark - Init
///--------------------------------------

- (id)init
{
    if ((self = [super init]))
    {
        _allowInvalidCertificates = ![ECBApplication currentApplication].isAppStoreEnvironment;
    }
    return self;
}

///--------------------------------------
#pragma mark - Private
///--------------------------------------

- (ECBWebReponse *)_processReponse:(NSURLResponse *)response object:(id)object error:(NSError *)error
{
    NSHTTPURLResponse *httpResponse = (NSHTTPURLResponse *)response;
    
    BOOL isSuccess = YES;
    NSInteger httpStatusCode = httpResponse.statusCode;
    NSString *statusMessage = [NSHTTPURLResponse localizedStringForStatusCode:httpStatusCode];
    NSDictionary *allHeaderFields = httpResponse.allHeaderFields;
    
    // Handles the case when the response serializer faced an unexpected response from
    // the eComBid-API.
    if (object == nil || error)
    {
        if (error)
        {
            statusMessage = error.localizedDescription;
        }
        else
        {
            statusMessage = NSLocalizedString(@"ECBWebResponseNoContent", @"");
            httpStatusCode = ECBHTTPStatusCodeNOCONTENT;
        }
        isSuccess = NO;
        object = @{};
    }
    
    // Handles other error case.
    if (!(httpResponse.statusCode >= ECBHTTPStatusCodeOK &&
          httpResponse.statusCode < ECBHTTPStatusCodeMULTIPLECHOICES))
    {
        if (error) statusMessage = error.localizedDescription;
        isSuccess = NO;
    }
    
    ECBWebReponse *webResponse = [ECBWebReponse reponseObjectWithResult:object
                                                              isSuccess:isSuccess
                                                             statusCode:httpStatusCode
                                                        allHeaderFields:allHeaderFields
                                                          statusMessage:statusMessage];
    return webResponse;
    
}

///--------------------------------------
#pragma mark - Public
///--------------------------------------

- (void)performRequest:(ECBWebRequest *)requestObject
              callback:(ECBWebCallback *)callback
{
    ECBParameterAssert(requestObject, @"RequestObject can't be null");
    ECBParameterAssert(requestObject.httpPath, @"HTTP Path can't be null");
    ECBParameterAssert(requestObject.httpMethod, @"HTTP Method can't be null");
    
    AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
    manager.securityPolicy.allowInvalidCertificates = self.allowInvalidCertificates;
    
    NSURLRequest *request = [ECBHTTPURLRequestConstructor urlRequestWithURL:requestObject.httpPath
                                                                 httpMethod:requestObject.httpMethod
                                                                httpHeaders:requestObject.additionalHeaders
                                                                 parameters:requestObject.parameters];
    
    [[manager dataTaskWithRequest:request completionHandler:^(NSURLResponse *response, id object, NSError *error) {
        ECBLogDebug(ECBLoggingTagCommon, @"Object: %@", object);
        if (callback)
        {
            callback.result([self _processReponse:response object:object error:error]);
        }
    }] resume];
}

- (void)performRequest:(ECBWebRequest *)requestObject
               options:(ECBRequestOptions)options
              callback:(ECBWebCallback *)callback
{
    // TODO: (tkieu87) Implement later
}

@end
