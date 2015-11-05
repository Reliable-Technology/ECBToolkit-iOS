//
//  ECBAPIService.m
//  ECBToolkit
//
//  Created by Tony Kieu on 11/4/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBAPIService.h"
#import "ECBWebClient.h"
#import "ECBUser.h"
#import "ECBLogging.h"

@implementation ECBAPIService

///--------------------------------------
#pragma mark - Request
///--------------------------------------

- (void)getDummyUserWithUsername:(NSString *)userName
                         success:(ECBUserResultBlock)success
                           error:(ECBErrorResultBlock)error;
{
    // TODO: (tkieu87) Refactor this request later
    ECBWebRequest *webRequest = [ECBWebRequest requestObjectWithHTTPPath:@"http://192.168.200.7:8089/ECBService.svc/GetDummyUser"
                                                              httpMethod:ECBHTTPRequestMethodPOST
                                                              parameters:@{@"username": userName}
                                                            sessionToken:@"" userId:0];
    ECBWebClient *webClient = [ECBWebClient new];
    [webClient performRequest:webRequest callback:[ECBWebCallback callbackWithResult:^(ECBWebReponse *response) {
        
        if (response.isSuccess)
        {
            ECBUser *user = [[[ECBUser class] alloc] initWithDictionary:response.result error:nil];
            ECBLogDebug(ECBLoggingTagCommon, @"Object: %@", user);
            success(user);
        }
        else
        {
            error(response.headerStatusCode, response.statusMessage);
        }
    }]];
}

@end
