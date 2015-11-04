//
//  ECBWebClientTests.m
//  ECBToolkit
//
//  Created by Tony Kieu on 11/3/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBTestCase.h"
#import "ECBWebClient.h"

@interface ECBWebClientTests : ECBTestCase

@end

@implementation ECBWebClientTests

- (void)testGetRequest
{
    NSString *requestURL = [[NSURL URLWithString:@"/get" relativeToURL:self.testBaseURL] absoluteString];
    ECBWebRequest *requestObject = [ECBWebRequest requestObjectWithHTTPPath:requestURL
                                                                       httpMethod:ECBHTTPRequestMethodGET
                                                                       parameters:nil
                                                                     sessionToken:[[NSUUID UUID] UUIDString]
                                                                           userId:101];
    XCTAssertNotNil(requestObject);
    XCTAssertEqualObjects(requestObject.httpPath, requestURL);
    XCTAssertEqualObjects(requestObject.httpMethod, ECBHTTPRequestMethodGET);
    XCTAssertNil(requestObject.parameters);
    
    XCTestExpectation *expectation = [self expectationWithDescription:@"ECB.tests.expectation"];
    __block id blockResponseObject = nil;
    
    ECBWebClient *webClient = [ECBWebClient new];
    [webClient performRequest:requestObject callback:[ECBWebCallback callbackWithResult:^(ECBWebReponse *object) {
        blockResponseObject = object;
        [expectation fulfill];
    }]];
    
    [self waitForExpectationsWithTimeout:ECBTestsDefaultTimeOut handler:nil];
    
    XCTAssertNotNil(blockResponseObject);
}

- (void)testPostRequest
{
    
}

- (void)testPutRequest
{
    
}



@end
