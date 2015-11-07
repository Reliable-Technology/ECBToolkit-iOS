//
//  ECBLogger.m
//  ECBToolkit
//
//  Created by Tony Kieu on 10/31/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBLogger.h"

#import "ECBApplication.h"
#import "ECBLogging.h"

@implementation ECBLogger

///--------------------------------------
#pragma mark - Class
///--------------------------------------

+ (NSString *)_descriptionForLoggingTag:(ECBLoggingTag)tag
{
    NSString *description = nil;
    switch (tag)
    {
        case ECBLoggingTagCommon:
            break;
        case ECBLoggingTagCrashReporting:
            description = @"Crash Reporting";
            break;
        default:
            break;
    }
    return description;
}

+ (NSString *)_descriptionForLogLevel:(ECBLogLevel)level
{
    NSString *description = nil;
    switch (level)
    {
        case ECBLogLevelNone:
            break;
        case ECBLogLevelError:
            description = @"Error";
            break;
        case ECBLogLevelWarning:
            description = @"Warning";
            break;
        case ECBLogLevelInfo:
            description = @"Info";
            break;
        case ECBLogLevelDebug:
            description = @"Debug";
            break;
        default:
            break;
    }
    return description;
}

///--------------------------------------
#pragma mark - Init
///--------------------------------------

+ (instancetype)sharedLogger
{
    static ECBLogger *logger;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        logger = [ECBLogger new];
    });
    return logger;
}

- (instancetype)init
{
    self = [super init];
    if (self == nil) return nil;
    
    _logLevel = ([ECBApplication currentApplication].appStoreEnvironment ? ECBLogLevelNone : ECBLogLevelDebug);
    
    return self;
}

///--------------------------------------
#pragma mark - Logging Messages
///--------------------------------------

- (void)logMessageWithLevel:(ECBLogLevel)level
                        tag:(ECBLoggingTag)tag
                     format:(NSString *)format, ... NS_FORMAT_FUNCTION(3, 4)
{
    if (level > self.logLevel || level == ECBLogLevelNone || !format)
    {
        return;
    }
    
    va_list args;
    va_start(args, format);
    
    NSMutableString *message = [NSMutableString stringWithFormat:@"[%@]", [[self class] _descriptionForLogLevel:level]];
    
    NSString *tagDescription = [[self class] _descriptionForLoggingTag:tag];
    if (tagDescription)
    {
        [message appendFormat:@"[%@]", tagDescription];
    }
    [message appendFormat:@": %@", format];
    
    NSLogv(message, args);
    
    va_end(args);
}

@end
