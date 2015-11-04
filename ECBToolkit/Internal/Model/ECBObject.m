//
//  ECBObject.m
//  ECBToolkit
//
//  Created by Tony Kieu on 11/3/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBObject.h"

@interface ECBObject () <ECBObjectProtocol>

@property (nonatomic, strong, readwrite) NSString *name;
@property (nullable, nonatomic, strong, readwrite) NSString *objectId;
@property (nonatomic, assign, readwrite) BOOL isActive;
@property (nullable, nonatomic, strong, readwrite) NSDate *updatedAt;
@property (nullable, nonatomic, strong, readwrite) NSDate *createdAt;

@end

@implementation ECBObject

///--------------------------------------
#pragma mark - Class
///--------------------------------------

+ (JSONKeyMapper *)_globalKeyMapper
{
    return [[JSONKeyMapper alloc] initWithDictionary:@{@"Name": @"name",
                                                       @"ID": @"objectId",
                                                       @"IsActive": @"isActive",
                                                       @"UpdatedAt": @"updatedAt",
                                                       @"CreatedAt": @"createdAt"}];
}

///--------------------------------------
#pragma mark - Init
///--------------------------------------

- (id)init
{
    if ((self = [super init]))
    {
        static dispatch_once_t onceToken;
        dispatch_once(&onceToken, ^{
            [JSONModel setGlobalKeyMapper:[ECBObject _globalKeyMapper]];
        });
    }
    return self;
}

- (BOOL)isValid
{
    return YES;
}

@end
