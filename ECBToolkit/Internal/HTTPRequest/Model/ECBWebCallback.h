//
//  ECBWebCallback.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/2/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ECBWebReponse;

typedef void (^ECBResponseBlock)(ECBWebReponse *);

/*!
 `ECBWebCallback` is a container object which handles the callback block
 for success and failure of case ECBWebResponse.
 */
@interface ECBWebCallback : NSObject

@property (nonatomic, readonly) ECBResponseBlock result;

///--------------------------------------
/// @name Init
///--------------------------------------

/*!
 Forms a new block callback with `ECBWebResponse`
 
 @param result The callback block
 
 @returns A new `ECBWebCallback`
 */
+ (instancetype)callbackWithResult:(ECBResponseBlock)result;

@end

NS_ASSUME_NONNULL_END