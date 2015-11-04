//
//  ECBLogging.h
//  ECBToolkit
//
//  Created by Tony Kieu on 10/31/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#ifndef ECBLogging_h
#define ECBLogging_h

#import "ECBLogger.h"
#import "ECBConstants.h"

static const ECBLoggingTag ECBLoggingTagCommon = 0;
static const ECBLoggingTag ECBLoggingTagCrashReporting = 100;

#define ECBLog(level, loggingTag, frmt, ...) \
[[ECBLogger sharedLogger] logMessageWithLevel:level tag:loggingTag format:(frmt), ##__VA_ARGS__]

#define ECBLogError(tag, frmt, ...) \
ECBLog(ECBLogLevelError, (tag), (frmt), ##__VA_ARGS__)

#define ECBLogWarning(tag, frmt, ...) \
ECBLog(ECBLogLevelWarning, (tag), (frmt), ##__VA_ARGS__)

#define ECBLogInfo(tag, frmt, ...) \
ECBLog(ECBLogLevelInfo, (tag), (frmt), ##__VA_ARGS__)

#define ECBLogDebug(tag, frmt, ...) \
ECBLog(ECBLogLevelDebug, (tag), (frmt), ##__VA_ARGS__)

#define ECBLogException(exception) \
ECBLogError(ECBLoggingTagCommon, @"Caught \"%@\" with reason \"%@\"$@", \
exception.name, exception, \
[exception callStackSymbols] ? [NSString stringWithFormat:@":\n%@.", [exception callStackSymbols]] : @"")

#endif /* ECBLogging_h */
