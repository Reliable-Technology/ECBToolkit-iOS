//
//  ECBTestCase.m
//  ECBToolkit
//
//  Created by Tony Kieu on 11/3/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBTestCase.h"

NSString * const ECBTestsDefaultBaseUrl     = @"https://httpbin.org/";
NSTimeInterval const ECBTestsDefaultTimeOut = 30;

@implementation ECBTestCase
{
    NSMutableArray *_mocks;
    dispatch_queue_t _mockQueue;
}

///--------------------------------------
#pragma mark - Init
///--------------------------------------

+ (void)initialize
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        [[ECBLogger sharedLogger] setLogLevel:ECBLogLevelDebug];
    });
}

- (void)setUp
{
    [super setUp];
    
    _mocks = [[NSMutableArray alloc] init];
    _mockQueue = dispatch_queue_create("ECB.tests.mock.queue", DISPATCH_QUEUE_SERIAL);
}

- (void)tearDown
{
    dispatch_sync(_mockQueue, ^{
        [_mocks makeObjectsPerformSelector:@selector(stopMocking)];
    });
    
    _mocks = nil;
    _mockQueue = nil;
    
    [super tearDown];
}

///--------------------------------------
#pragma mark - Helpers
///--------------------------------------

- (XCTestExpectation *)currentSelectorTestExpectation
{
    NSInvocation *invocation = self.invocation;
    NSString *selectorName = invocation ? NSStringFromSelector(invocation.selector) : @"testExpectation";
    return [self expectationWithDescription:selectorName];
}

- (void)waitForTestExpectations
{
    [self waitForExpectationsWithTimeout:ECBTestsDefaultTimeOut handler:nil];
}

- (NSURL *)testBaseURL
{
    return [NSURL URLWithString:ECBTestsDefaultBaseUrl];
}

///--------------------------------------
#pragma mark - Mock Registration
///--------------------------------------

- (void)registerMockObject:(id)mockObject
{
    dispatch_sync(_mockQueue, ^{
        [_mocks addObject:mockObject];
    });
}

@end
