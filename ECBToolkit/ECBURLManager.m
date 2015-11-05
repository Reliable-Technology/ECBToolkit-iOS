//
//  ECBURLManager.m
//  ECBToolkit
//
//  Created by Tony Kieu on 11/5/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBURLManager.h"
#import "ECBAssert.h"
#import "ECBLogging.h"

static NSString * const ECBDevLocalBaseURL          = @"http://192.168.200.7:8087";
static NSString * const ECBDevBaseURL               = @"";
static NSString * const ECBQaBaseURL                = @"";
static NSString * const ECBStagingBaseURL           = @"";
static NSString * const ECBProdBaseURL              = @"";

static NSString * const ECBDevLocalWebServicePath   = @"ECBService.svc";
static NSString * const ECBDevWebServicePath        = @"ECBService.svc";
static NSString * const ECBQaWebServicePath         = @"ECBService.svc";
static NSString * const ECBStagingWebServicePath    = @"ECBService.svc";
static NSString * const ECBProdWebServicePath       = @"ECBService.svc";

static NSString * const ECBDevKey                   = @"dev";
static NSString * const ECBQaKey                    = @"qa";
static NSString * const ECBStagingKey               = @"staging";
static NSString * const ECBProdKey                  = @"prod";

///--------------------------------------
/// @name ECBURL
///--------------------------------------

/*!
 `ECBURL` is a private container class that holds the base URL and its associated service path.
 */
@interface ECBURL : NSObject

@property (nonnull, nonatomic, readonly) NSString *baseURL;
@property (nonnull, nonatomic, readonly) NSString *servicePath;

- (id)init NS_UNAVAILABLE;
- (instancetype)initWithBaseURL:(NSString *)baseURL
                    servicePath:(NSString *)servicePath NS_DESIGNATED_INITIALIZER;
- (NSString *)webServiceURL;

@end

@implementation ECBURL

+ (instancetype)constructWithBase:(NSString *)baseURL servicePath:(NSString *)servicePath
{
    return [[self alloc] initWithBaseURL:baseURL servicePath:servicePath];
}

- (id)init
{
    ECBNotDesignatedInitializer();
}

- (instancetype)initWithBaseURL:(NSString *)baseURL servicePath:(NSString *)servicePath
{
    if ((self = [super init]))
    {
        _baseURL = baseURL;
        _servicePath = servicePath;
    }
    return self;
}

- (NSString *)webServiceURL
{
    NSString *servicePath = self.servicePath ?: ECBProdWebServicePath;
    return [NSString stringWithFormat:@"%@%@", self.baseURL, servicePath];
}

@end

///--------------------------------------
/// @name ECBURLManager
///--------------------------------------

@interface ECBURLManager ()

@property (nonatomic, strong) NSDictionary *_urlDict;

@end

@implementation ECBURLManager

///--------------------------------------
#pragma mark - Init
///--------------------------------------

+ (instancetype)sharedManager
{
    static ECBURLManager *URLManager;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        URLManager = [ECBURLManager new];
    });
    return URLManager;
}

- (id)init
{
    if ((self = [super init]))
    {
        __urlDict = [[NSDictionary alloc] initWithObjectsAndKeys:
                     [ECBURL constructWithBase:ECBDevLocalBaseURL servicePath:ECBDevWebServicePath], ECBDevKey,
                     [ECBURL constructWithBase:ECBQaBaseURL servicePath:ECBQaWebServicePath], ECBQaKey,
                     [ECBURL constructWithBase:ECBStagingBaseURL servicePath:ECBStagingWebServicePath], ECBStagingKey,
                     [ECBURL constructWithBase:ECBProdBaseURL servicePath:ECBProdWebServicePath], ECBProdKey, nil];
    }
    return self;
}

///--------------------------------------
#pragma mark - Helpers
///--------------------------------------

- (ECBURL *)_getURL
{
#ifdef DEBUG
    NSString *key = ECBDevKey;
#elif QA
    NSString *key = ECBQakey;
#elif STAGING
    NSString *key = ECBStagingKey;
#else
    NSString *key = ECBProdKey;
#endif
    
    ECBURL *url = self._urlDict[key];
    ECBLogInfo(ECBLoggingTagCommon, @"<Key: %@ - URL: %@>", key, url.webServiceURL);
    if (!url) url = self._urlDict[ECBProdKey];
    
    return url;
}

///--------------------------------------
#pragma mark - URL Forming
///--------------------------------------

- (NSString *)webServiceURL
{
    NSString *serviceURL = [self _getURL].webServiceURL;
    
    if (self.redirectionURL != nil)
    {
        ECBLogInfo(ECBLoggingTagCommon, @"Apply redirection from URL: %@ to URL: %@"
                   , serviceURL, self.redirectionURL);
        serviceURL = self.redirectionURL;
    }
    
    return serviceURL;
}

- (NSString *)webServiceURLForEndPoint:(NSString *)endPoint
{
    NSString *serviceURL = [self webServiceURL];
    NSString *newURL = @"";
    
    if ([serviceURL hasSuffix:@"/"])
    {
        newURL = [NSString stringWithFormat:@"%@%@", serviceURL, endPoint];
    }
    else
    {
        newURL = [NSString stringWithFormat:@"%@/%@", serviceURL, endPoint];
    }
    ECBLogInfo(ECBLoggingTagCommon, @"Result URL = %@", newURL);
    
    return newURL;
    
}

@end
