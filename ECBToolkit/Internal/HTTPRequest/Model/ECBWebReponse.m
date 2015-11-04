//
//  ECBWebReponse.m
//  ECBToolkit
//
//  Created by Tony Kieu on 11/2/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBWebReponse.h"

@interface ECBWebReponse ()

@property (nonatomic, strong, readwrite) id result;
@property (nonatomic, assign, readwrite) BOOL isSuccess;
@property (nonatomic, assign, readwrite) NSInteger headerStatusCode;
@property (nonatomic, copy, readwrite) NSDictionary *allHeaderFields;
@property (nonatomic, copy, readwrite) NSString *statusMessage;

@end

@implementation ECBWebReponse

///--------------------------------------
#pragma mark - Init
///--------------------------------------

+ (instancetype)reponseObjectWithResult:(id)result
                              isSuccess:(BOOL)isSuccess
                             statusCode:(NSInteger)statusCode
                        allHeaderFields:(NSDictionary *)allHeaderFields
                          statusMessage:(NSString *)statusMessage
{
    ECBWebReponse *responseObject = [ECBWebReponse new];
    responseObject.result = result;
    responseObject.isSuccess = isSuccess;
    responseObject.headerStatusCode = statusCode;
    responseObject.allHeaderFields = allHeaderFields;
    responseObject.statusMessage = statusMessage;
    return responseObject;
}

@end
