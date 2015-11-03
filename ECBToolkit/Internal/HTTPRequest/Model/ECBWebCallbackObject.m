//
//  ECBWebCallbackObject.m
//  ECBToolkit
//
//  Created by Tony Kieu on 11/2/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBWebCallbackObject.h"

@interface ECBWebCallbackObject ()

@property (nonatomic, readwrite) ECBResponseBlock result;

@end

@implementation ECBWebCallbackObject

///--------------------------------------
#pragma mark - Init
///--------------------------------------

+ (instancetype)callbackWithResult:(ECBResponseBlock)result
{
    ECBWebCallbackObject *callback = [ECBWebCallbackObject new];
    callback.result = result;
    return callback;
}

@end
