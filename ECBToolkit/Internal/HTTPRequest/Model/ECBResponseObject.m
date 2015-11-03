//
//  ECBResponseObject.m
//  ECBToolkit
//
//  Created by Tony Kieu on 11/2/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBResponseObject.h"

@interface ECBResponseObject ()

@property (nonatomic, strong, readwrite) id result;
@property (nonatomic, assign, readwrite) BOOL isSuccess;
@property (nonatomic, copy, readwrite) NSString *statusCode;
@property (nonatomic, copy, readwrite) NSString *statusMessage;

@end

@implementation ECBResponseObject

///--------------------------------------
#pragma mark - Init
///--------------------------------------

+ (instancetype)reponseObjectWithResult:(id)result
                              isSuccess:(BOOL)isSuccess
                             statusCode:(NSString *)statusCode
                          statusMessage:(NSString *)statusMessage
{
    ECBResponseObject *responseObject = [ECBResponseObject new];
    responseObject.result = result;
    responseObject.isSuccess = isSuccess;
    responseObject.statusCode = statusCode;
    responseObject.statusMessage = statusMessage;
    return responseObject;
}

@end
