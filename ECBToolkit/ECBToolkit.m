//
//  ECBToolkit.m
//  ECBToolkit
//
//  Created by Tony Kieu on 11/4/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBToolkit.h"

@implementation ECBToolkit

///--------------------------------------
#pragma mark - Class
///--------------------------------------

+ (void)setupToolkit
{
    // Init singletons
    [ECBLogger sharedLogger];
    [ECBApplication currentApplication];
    [ECBSession current];
}

@end
