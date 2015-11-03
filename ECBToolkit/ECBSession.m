//
//  ECBSession.m
//  ECBToolkit
//
//  Created by Tony Kieu on 11/1/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBSession.h"
#import "ECBAssert.h"
#import "ECBUtils.h"

static NSString * const ECBSessionSoftExpirationKey = @"ECBSessionSoftExpirationKey";
static NSString * const ECBSessionHardExpirationKey = @"ECBSessionHardExpirationKey";
static NSString * const ECBSessionCreatedKey        = @"ECBSessionCreatedKey";
static NSString * const ECBSessionLastCallKey       = @"ECBSessionLastCallKey";
static NSString * const ECBSessionTokenKey          = @"ECBSessionTokenKey";

@interface ECBSession ()

@property (nonatomic, assign) NSInteger _softExpiration;
@property (nonatomic, assign) NSInteger _hardExpiration;
@property (nonatomic, strong) NSDate *_sessionCreated;

@end

@implementation ECBSession

@synthesize sessionToken = _sessionToken;

///--------------------------------------
#pragma mark - Init
///--------------------------------------

+ (instancetype)current
{
    static ECBSession *session;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        session = [ECBSession new];
    });
    return session;
}

- (instancetype)init
{
    if ((self = [super init]))
    {
        NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
        if ([userDefaults objectForKey:ECBSessionSoftExpirationKey] &&
            [userDefaults objectForKey:ECBSessionHardExpirationKey] &&
            [userDefaults objectForKey:ECBSessionCreatedKey] &&
            [userDefaults objectForKey:ECBSessionTokenKey])
        {
            __softExpiration = [userDefaults integerForKey:ECBSessionSoftExpirationKey];
            __hardExpiration = [userDefaults integerForKey:ECBSessionHardExpirationKey];
            __sessionCreated = [userDefaults objectForKey:ECBSessionCreatedKey];
            _sessionToken = [userDefaults stringForKey:ECBSessionTokenKey];
        }
        else
        {
            __softExpiration = ECBDefaultSoftExpirationMinutes;
            __hardExpiration = ECBDefaultHardExpirationMinutes;
            __sessionCreated = [NSDate dateWithTimeIntervalSince1970:0];
        }
    }
    return self;
}

///--------------------------------------
#pragma mark - Accessors
///--------------------------------------

- (NSString *)getSessionToken
{
    BOOL sessionDidExpire = [self isSessionExpired];
    if (sessionDidExpire)
    {
        [self clearSession];
    }
    
    return _sessionToken;
}

///--------------------------------------
#pragma mark - Public
///--------------------------------------

- (void)createNewSessionWithToken:(NSString *)token
            softExpirationMinutes:(NSInteger)softExpirationMinutes
            hardExpirationMinutes:(NSInteger)hardExpirationMinutes
{
    ECBParameterAssert(token, @"Token string can't be null");
    
    _sessionToken = token;
    self._softExpiration = softExpirationMinutes;
    self._hardExpiration = hardExpirationMinutes;
    self._sessionCreated = [NSDate date];
    
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    [userDefaults setInteger:self._softExpiration forKey:ECBSessionSoftExpirationKey];
    [userDefaults setInteger:self._hardExpiration forKey:ECBSessionHardExpirationKey];
    [userDefaults setObject:self._sessionCreated forKey:ECBSessionCreatedKey];
    [userDefaults setObject:self.sessionToken forKey:ECBSessionTokenKey];
    [userDefaults synchronize];
}

- (void)checkSessionOnValid:(void (^)(void))valid
                  onExpired:(void (^)(void))expire
{
    BOOL sessionDidExpire = [self isSessionExpired];
    
    if (sessionDidExpire)
    {
        valid();
    }
    else
    {
        expire();
    }
}

- (void)extendSession:(NSString *)newToken
{
    ECBParameterAssert(newToken, @"Token string can't be null");
    
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    [userDefaults setObject:[NSDate date] forKey:ECBSessionLastCallKey];
    [userDefaults setObject:newToken forKey:ECBSessionTokenKey];
    [userDefaults synchronize];
}

- (BOOL)isSessionExpired
{
    NSDate *lastCall = [[NSUserDefaults standardUserDefaults] objectForKey:ECBSessionLastCallKey];
    if (lastCall == nil) lastCall = [NSDate dateWithTimeIntervalSince1970:0];
    
    NSDate *now = [NSDate date];
    if ([now compare:[NSDate dateWithTimeInterval:self._softExpiration*60 sinceDate:lastCall]] == NSOrderedAscending &&
        [now compare:[NSDate dateWithTimeInterval:self._hardExpiration*60 sinceDate:self._sessionCreated]] == NSOrderedAscending)
    {
        return NO;
    }
    else
    {
        return YES;
    }
}

- (void)clearSession
{
    _sessionToken = @"";
    self._sessionCreated = nil;
    
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    if ([userDefaults objectForKey:ECBSessionLastCallKey])
        [userDefaults removeObjectForKey:ECBSessionLastCallKey];
    if ([userDefaults objectForKey:ECBSessionCreatedKey])
        [userDefaults removeObjectForKey:ECBSessionCreatedKey];
    if ([userDefaults objectForKey:ECBSessionTokenKey])
        [userDefaults removeObjectForKey:ECBSessionTokenKey];
    [userDefaults synchronize];
}

@end
