//
//  ECBWebCallback.m
//  ECBToolkit
//
//  Created by Tony Kieu on 11/2/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBWebCallback.h"

@interface ECBWebCallback ()

@property (nonatomic, readwrite) ECBResponseBlock result;

@end

@implementation ECBWebCallback

///--------------------------------------
#pragma mark - Init
///--------------------------------------

+ (instancetype)callbackWithResult:(ECBResponseBlock)result
{
    ECBWebCallback *callback = [ECBWebCallback new];
    callback.result = result;
    return callback;
}

@end
