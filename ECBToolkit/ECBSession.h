//
//  ECBSession.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/1/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 The default period for soft expiration is 1 day.
 */
static NSInteger const ECBDefaultSoftExpirationMinutes = 24 * 60;

/*!
 The default period for hard expiration is 3 days.
 */
static NSInteger const ECBDefaultHardExpirationMinutes = 72 * 60;

/*!
 `ECBSession` class provides a centralized way to manage 
 the client device session with the ECB backend.
 */
@interface ECBSession : NSObject

///--------------------------------------
/// @name Session Properties
///--------------------------------------

/*!
 @abstract The session token string for the current session.
 */
@property (nonatomic, readonly, getter=getSessionToken) NSString *sessionToken;

///--------------------------------------
/// @name Shared Session
///--------------------------------------

/*!
 A shared instance of 'ECBSession' that should be used for all service request.
 
 @returns A shared singleton instance of 'ECBSession'
 */
+ (instancetype)sharedSession;

///--------------------------------------
/// @name Session Utilities
///--------------------------------------

/*!
 Creates a new session with soft and hard expiration period (in minutes).
 
 @param token                   The new session token
 @param softExpirationMinutes   The period of soft expiration in minutes
 @param hardExpirationMinutes   The period of hard expiration in minutes
 */
- (void)createNewSessionWithToken:(NSString *)token
            softExpirationMinutes:(NSInteger)softExpirationMinutes
            hardExpirationMinutes:(NSInteger)hardExpirationMinutes;

/*!
 Checks the current session and performs callback when session is valid
 or expired.
 
 @param valid Callback block if session is valid
 @param expire Callback block if session is expired
 */
- (void)checkSessionOnValid:(void (^)(void))valid
                  onExpired:(void (^)(void))expire;

/*!
 Extends the current session with new token value.
 
 @param newToken New token value
 */
- (void)extendSession:(NSString *)newToken;

/*!
 Checks whether the current session is expired or not.
 
 @returns A true value if session is expired, otherwise false
 */
- (BOOL)isSessionExpired;

/*!
 Clear the current session.
 */
- (void)clearSession;

@end

NS_ASSUME_NONNULL_END
