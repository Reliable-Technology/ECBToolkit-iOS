//
//  ECBApplication.m
//  ECBToolkit
//
//  Created by Tony Kieu on 10/31/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBApplication.h"

@implementation ECBApplication

///--------------------------------------
#pragma mark - Init
///--------------------------------------

+ (instancetype)currentApplication
{
    static ECBApplication *application;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        application = [ECBApplication new];
    });
    return application;
}

///--------------------------------------
#pragma mark - Accessors
///--------------------------------------

- (UIApplication *)systemApplication
{
    return [UIApplication performSelector:@selector(sharedApplication)];
}

- (BOOL)isAppStoreEnvironment
{
#if TARGET_OS_IPHONE && !TARGET_IPHONE_SIMULATOR
    return ([[NSBundle mainBundle] pathForResource:@"embedded" ofType:@"mobileprovision"] == nil);
#endif
    return NO;
}

- (NSInteger)iconBadgeNumber
{
    return self.systemApplication.applicationIconBadgeNumber;
}

- (void)setIconBadgeNumber:(NSInteger)iconBadgeNumber
{
    if (self.iconBadgeNumber != iconBadgeNumber)
    {
        self.systemApplication.applicationIconBadgeNumber = iconBadgeNumber;
    }
}

@end
