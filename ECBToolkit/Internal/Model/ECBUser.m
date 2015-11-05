//
//  ECBUser.m
//  ECBToolkit
//
//  Created by Tony Kieu on 11/3/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBUser.h"

@interface ECBUser ()

@property (nonnull, nonatomic, strong, readwrite) NSString *username;
@property (nonnull, nonatomic, strong, readwrite) NSString *email;
@property (nonnull, nonatomic, strong, readwrite) NSString *password;
@property (nullable, nonatomic, strong, readwrite) NSString<Optional> *socialMediaId;
@property (nonatomic, assign, readwrite) NSInteger socialMediaSourceId;
@property (nonatomic, assign, readwrite) BOOL isAuthenticated;

@end

@implementation ECBUser

+ (JSONKeyMapper *)keyMapper
{
    return [[JSONKeyMapper alloc] initWithDictionary:
            @{@"Username": @"username",
              @"Email": @"email",
              @"Password": @"password",
              @"SocialMediaId": @"socialMediaId",
              @"SocialMediaSourceId": @"socialMediaSourceId",
              @"IsAuthenticated": @"isAuthenticated"}];
}

- (BOOL)isValid
{
    return YES;
}

@end
