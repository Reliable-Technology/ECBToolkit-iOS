//
//  ECBTestCase.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/3/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <OCMock/OCMock.h>
#import <XCTest/XCTest.h>
#import "ECBLogging.h"

extern NSString * const ECBTestsDefaultBaseUrl;
extern NSTimeInterval const ECBTestsDefaultTimeOut;

@interface ECBTestCase : XCTestCase

///--------------------------------------
/// @name XCTestCase
///--------------------------------------

- (void)setUp NS_REQUIRES_SUPER;
- (void)tearDown NS_REQUIRES_SUPER;

///--------------------------------------
/// @name Expectations
///--------------------------------------

- (XCTestExpectation *)currentSelectorTestExpectation;
- (void)waitForTestExpectations;

///--------------------------------------
/// @name Mocks
///--------------------------------------

- (void)registerMockObject:(id)mockObject;

///--------------------------------------
/// @name Helpers
///--------------------------------------

- (NSURL *)testBaseURL;

@end

#define _ECBRegisterMock(mockObject) [self registerMockObject:mockObject]
#define _ECBMockShim(method, args...) ({ id mock = method(args); _ECBRegisterMock(mock); mock; })
#define _ECBOCMockWarning _Pragma("GCC warning \"Please use ECB mocking methods instead of OCMock ones.\"")

#define _ECBStrictClassMock(kls)         [OCMockObject mockForClass:kls]
#define _ECBClassMock(kls)               [OCMockObject niceMockForClass:kls]
#define _ECBStrictProtocolMock(proto)    [OCMockObject mockForProtocol:proto]
#define _ECBProtocolMock(proto)          [OCMockObject niceMockForProtocol:proto]
#define _ECBPartialMock(obj)             [OCMockObject partialMockForObject:obj]

#define ECBStrictClassMock(...)          _ECBMockShim(_ECBStrictClassMock,    __VA_ARGS__)
#define ECBClassMock(...)                _ECBMockShim(_ECBClassMock,          __VA_ARGS__)
#define ECBStrictProtocolMock(...)       _ECBMockShim(_ECBStrictProtocolMock, __VA_ARGS__)
#define ECBProtocolMock(...)             _ECBMockShim(_ECBProtocolMock,       __VA_ARGS__)
#define ECBPartialMock(...)              _ECBMockShim(_ECBPartialMock,        __VA_ARGS__)

#undef OCMStrictClassMock
#undef OCMClassMock
#undef OCMStrictProtocolMock
#undef OCMProtocolMock
#undef OCMPartialMock

#define OCMStrictClassMock             _ECBOCMockWarning _ECBStrictClassMock
#define OCMClassMock                   _ECBOCMockWarning _ECBClassMock
#define OCMStrictProtocolMock          _ECBOCMockWarning _ECBStrictProtocolMock
#define OCMProtocolMock                _ECBOCMockWarning _ECBProtocolMock
#define OCMPartialMock                 _ECBOCMockWarning _ECBPartialMock

#define ECBAssertEqualInts(a1, a2, description...) \
XCTAssertEqual((int)(a1), (int)(a2), ## description);

#define ECBAssertNotEqualInts(a1, a2, description...) \
XCTAssertNotEqual((int)(a1), (int)(a2), ## description);

#define ECBAssertIsKindOfClass(a1, a2, description...) \
XCTAssertTrue([a1 isKindOfClass:[a2 class]], ## description)

#define ECBAssertNotKindOfClass(a1, a2, description...) \
XCTAssertFalse([a1 isKindOfClass:[a2 class]], ## description)

#define ECBAssertThrowsInconsistencyException(expression, ...) \
XCTAssertThrowsSpecificNamed(expression, NSException, NSInternalInconsistencyException, __VA_ARGS__)

#define ECBAssertThrowsInvalidArgumentException(expression, ...) \
XCTAssertThrowsSpecificNamed(expression, NSException, NSInvalidArgumentException, __VA_ARGS__)

#define ECBAssertStringContains(a, b) XCTAssertTrue([(a) rangeOfString:(b)].location != NSNotFound)
