//
//  ECBToolkit.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/4/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ECBUser.h"

#import "ECBUtils.h"

#import "ECBWebClient.h"
#import "ECBAPIService.h"

#import "ECBSession.h"
#import "ECBConstants.h"

#import "ECBLogging.h"
#import "ECBAssert.h"
#import "ECBMacros.h"
#import "ECBDevice.h"
#import "ECBApplication.h"

/*!
 The `ECBToolkit` class contains static functions that handle global configuration for the framework.
 */
@interface ECBToolkit : NSObject

+ (void)setupToolkit;


@end
