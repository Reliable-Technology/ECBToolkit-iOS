//
//  ECBAPIService.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/4/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ECBConstants.h"

@interface ECBAPIService : NSObject

- (void)getDummyUserWithUsername:(NSString *)userName
                         success:(ECBUserResultBlock)success
                           error:(ECBErrorResultBlock)error;

@end
