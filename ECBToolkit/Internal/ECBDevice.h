//
//  ECBDevice.h
//  ECBToolkit
//
//  Created by Tony Kieu on 10/30/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ECBDevice : NSObject

@property (nonatomic, copy, readonly) NSString *detailedModel;
@property (nonatomic, copy, readonly) NSString *osFullVersion;
@property (nonatomic, copy, readonly) NSString *osVersion;
@property (nonatomic, copy, readonly) NSString *osBuild;

@property (nonatomic, assign, readonly, getter=isJailBroken) BOOL jailBroken;

+ (instancetype)currentDevice;

@end
