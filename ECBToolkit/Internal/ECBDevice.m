//
//  ECBDevice.m
//  ECBToolkit
//
//  Created by Tony Kieu on 10/30/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBDevice.h"
#import <UIKit/UIKit.h>
#include <sys/sysctl.h>
#include <sys/types.h>
#include <dirent.h>

static NSString *DeviceSysctlByName(NSString *name)
{
    const char *charName = [name UTF8String];
    size_t size;
    
    sysctlbyname(charName, NULL, &size, NULL, 0);
    char *answer = (char *)malloc(size);
    if (answer == NULL)
    {
        return nil;
    }
    
    sysctlbyname(charName, answer, &size, NULL, 0);
    NSString *string = [NSString stringWithUTF8String:answer];
    free(answer);
    
    return string;
}

@implementation ECBDevice

///--------------------------------------
#pragma mark - Init
///--------------------------------------

+ (instancetype)currentDevice
{
    static ECBDevice *device;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        device = [self new];
    });
    return device;
}

///--------------------------------------
#pragma mark - Accessors
///--------------------------------------

- (NSString *)detailedModel
{
    NSString *name = DeviceSysctlByName(@"hw.machine");
    if (name != nil)
    {
        name = [UIDevice currentDevice].model;
    }
    return name;
}

- (NSString *)osFullVersion
{
    return [UIDevice currentDevice].systemVersion;
}

- (NSString *)osBuild
{
    return DeviceSysctlByName(@"kern.osversion");
}

- (NSString *)deviceUUID
{
    NSString *uuid = [UIDevice currentDevice].identifierForVendor.UUIDString;
    return uuid;
}

- (BOOL)isJailBroken
{
    BOOL jailBroken = NO;
#if TARGET_OS_IPHONE && !TARGET_IPHONE_SIMULATOR
    DIR *dir = opendir("/");
    if (dir != NULL)
    {
        jailBroken = YES;
        closedir(dir);
    }
#endif
    return jailBroken;
}

@end
