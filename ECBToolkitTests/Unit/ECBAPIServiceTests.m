//
//  ECBAPIServiceTests.m
//  ECBToolkit
//
//  Created by Tony Kieu on 11/4/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBTestCase.h"
#import "ECBAPIService.h"

@interface ECBAPIServiceTests : ECBTestCase

@end

@implementation ECBAPIServiceTests

- (void)testGetDummyUser
{
    XCTestExpectation *expectation = [self expectationWithDescription:@"ECB.tests.expectation"];

    ECBAPIService *service = [ECBAPIService new];
    [service getDummyUserWithUsername:@"shishir" success:^(ECBUser *user) {
        ECBLogDebug(ECBLoggingTagCommon, @"User: %@", user);
        [expectation fulfill];
    } error:^(NSInteger statusCode, NSString *statusMessage) {
        // TODO: No Implementation
        [expectation fulfill];
    }];
    
    [self waitForExpectationsWithTimeout:ECBTestsDefaultTimeOut handler:nil];

}

@end
