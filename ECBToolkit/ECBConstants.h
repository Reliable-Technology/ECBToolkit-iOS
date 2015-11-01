//
//  ECBConstants.h
//  ECBToolkit
//
//  Created by Tony Kieu on 10/30/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ECBObject;
@class ECBUser;

///--------------------------------------
/// @name Version
///--------------------------------------

#define API_VERSION @"0.1.0"

///--------------------------------------
/// @name Cache Policies
///--------------------------------------

/*!
 `ECBCachePolicy` specifies different caching policies.
 
 This lets you show data when the user's device is offline, or when
 the app has just started and network requests have not yet had time
 to complete. The SDK will automatically flushing the cache when it
 takes up too much space.
 
 @warning Cache policy could only be set when Local Datastore is not enabled.
 */
typedef NS_ENUM(uint8_t, ECBCachePolicy)
{
    /*!
     @abstract The request does not load from the cache or save results to the cache.
     This is the default cache policy.
     */
    kECBCachePolicyIgnoreCache = 0,
    /*!
     @abstract The request only loads from the cache, ignoring the network.
     If there are no cached results, this causes a `NSError` with `kECBErrorCacheMiss` code.
     */
    kECBCachePolicyCacheOnly,
    /*!
     @abstract The request does not load from the cache, but will save the results to the cache.
     */
    kECBCachePolicyNetworkOnly,
    /*!
     @abstract The request first tries to load from the cache, but if that fails, it loads results from the network.
     If there are no cached results, this causes a 'NSError' with 'KECBErrorCacheMiss' code.
     */
    kECBCachePolicyCacheElseNetwork,
    /*!
     @abstract The query first tries to load from the network, but if that fails, it loads results from the cache.
     If there are no cached results, this causes a `NSError` with `KECBErrorCacheMiss` code.
     */
    kECBCachePolicyNetworkElseCache,
    /*!
     @abstract The query first loads from the cache, then loads from the network.
     The callback will be called twice - first with the cached results, then with the network results.
     Since it returns two results at different times, this cache policy cannot be used with synchronous or task methods.
     */
    kECBCachePolicyCacheThenNetwork
};

///--------------------------------------
/// @name Logging Levels
///--------------------------------------

/*!
 `ECBLogLevel` enum specifies different levels of logging that could be used to limit or display more messages in logs.
 */
typedef NS_ENUM(uint8_t, ECBLogLevel)
{
    /*!
     Log level that disables all logging.
     */
    ECBLogLevelNone = 0,
    /*!
     Log level that if set is going to output error messages to the log.
     */
    ECBLogLevelError = 1,
    /*!
     Log level that if set is going to output the following messages to log:
     - Errors
     - Warnings
     */
    ECBLogLevelWarning = 2,
    /*!
     Log level that if set is going to output the following messages to log:
     - Errors
     - Warnings
     - Informational messages
     */
    ECBLogLevelInfo = 3,
    /*!
     Log level that if set is going to output the following messages to log:
     - Errors
     - Warnings
     - Informational messages
     - Debug messages
     */
    ECBLogLevelDebug = 4
};

///--------------------------------------
/// @name Errors
///--------------------------------------

extern NSString *const __nonnull ECBErrorDomain;

/*!
 `ECBErrorCode` enum contains all custom error codes that are used as `code` for `NSError` for callbacks on all classes.
 
 These codes are used when `domain` of `NSError` that you receive is set to `ECBErrorDomain`.
 */
typedef NS_ENUM(NSInteger, ECBErrorCode)
{
    /*!
     @abstract Internal server error. No information available.
     */
    kECBErrorInternalServer = 1,
};

///--------------------------------------
/// @name Blocks
///--------------------------------------

typedef void (^ECBBooleanResultBlock)(BOOL succeeded, NSError *__nullable error);
typedef void (^ECBIntegerResultBlock)(int number, NSError *__nullable error);
typedef void (^ECBArrayResultBlock)(NSArray *__nullable objects, NSError *__nullable error);
typedef void (^ECBObjectResultBlock)(ECBObject *__nullable objects, NSError *__nullable error);
typedef void (^ECBUserResultBlock)(ECBUser *__nullable user, NSError *__nullable error);
typedef void (^ECBDataResultBlock)(NSData *__nullable data, NSError *__nullable error);
typedef void (^ECBDataStreamResultBlock)(NSInputStream *__nullable stream, NSError *__nullable error);
typedef void (^ECBFilePathResultBlock)(NSString *__nullable filePath, NSError *__nullable error);
typedef void (^ECBStringResultBlock)(NSString *__nullable string, NSError *__nullable error);
typedef void (^ECBIdResultBlock)(__nullable id object, NSError *__nullable error);
typedef void (^ECBProgressBlock)(int percentDone);

///--------------------------------------
/// @name Deprecated Macros
///--------------------------------------

#ifndef ECB_DEPRECATED
#  ifdef __deprecated_msg
#    define ECB_DEPRECATED(_MSG) __deprecated_msg(_MSG)
#  else
#    ifdef __deprecated
#      define ECB_DEPRECATED(_MSG) __attribute__((deprecated))
#    else
#      define ECB_DEPRECATED(_MSG)
#    endif
#  endif
#endif
