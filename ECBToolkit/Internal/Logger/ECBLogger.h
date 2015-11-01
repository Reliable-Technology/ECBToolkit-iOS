//
//  ECBLogger.h
//  ECBToolkit
//
//  Created by Tony Kieu on 10/31/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ECBConstants.h"

typedef uint8_t ECBLoggingTag;

@interface ECBLogger : NSObject

@property (assign, atomic) ECBLogLevel logLevel;

///--------------------------------------
/// @name Shared Logger
///--------------------------------------

/*!
 A shared instance of 'ECBLogger' that should be used for all logging.
 
 @returns A shared singleton instance of 'ECBLogger'
 */
+ (instancetype)sharedLogger;

///--------------------------------------
/// @name Logging Messages
///--------------------------------------

/*!
 Logs a message at a specific level for a tag.
 If current logging level doesn't include this level - this method does nothing
 
 @param level   Logging Level
 @param tag     Logging Tag
 @param format  Format to use for the log message.
 */
- (void)logMessageWithLevel:(ECBLogLevel)level
                        tag:(ECBLoggingTag)tag
                     format:(NSString *)format, ... NS_FORMAT_FUNCTION(3, 4);
@end
