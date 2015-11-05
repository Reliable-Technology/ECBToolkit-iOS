//
//  ECBUser.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/3/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBObject.h"

@class UserType;

@interface ECBUser : ECBObject <ECBObjectProtocol>

@property (nonnull, nonatomic, strong, readonly) NSString *username;
@property (nonnull, nonatomic, strong, readonly) NSString *email;
@property (nonnull, nonatomic, strong, readonly) NSString *password;
@property (nullable, nonatomic, strong) NSString<Optional> *phone;
@property (nullable, nonatomic, strong, readonly) NSString<Optional> *socialMediaId;
@property (nonatomic, assign, readonly) NSInteger socialMediaSourceId;
@property (nullable, nonatomic, strong) UserType<Optional> *userType;
@property (nonatomic, assign, readonly) BOOL isAuthenticated;

@end
