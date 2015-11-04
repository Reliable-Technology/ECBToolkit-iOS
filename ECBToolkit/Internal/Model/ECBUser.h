//
//  ECBUser.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/3/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBObject.h"

@interface ECBUser : ECBObject <ECBObjectProtocol>

@property (nonnull, nonatomic, strong, readonly) NSString *username;
@property (nonnull, nonatomic, strong) NSString *email;
@property (nullable, nonatomic, strong) NSString *phone;
@property (nullable, nonatomic, strong) NSString *alternatePhone;

@end
