//
//  ECBApplication.h
//  ECBToolkit
//
//  Created by Tony Kieu on 10/31/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "ECBConstants.h"

/*!
 `ECBApplication` class provides a centralized way to get the information about the current application,
 or the environment it's running in. Please non, that all device specific things - should go to <ECBDevice>
 */
@interface ECBApplication : NSObject

@property (nonatomic, strong, readonly) UIApplication *systemApplication;
@property (nonatomic, assign, readonly, getter=isAppStoreEnvironment) BOOL appStoreEnvironment;
@property (nonatomic, assign, readonly, getter=isExtensionEnvironment) BOOL extensionEnvironment;
@property (nonatomic, assign) NSInteger iconBadgeNumber;

+ (instancetype)currentApplication;

@end
