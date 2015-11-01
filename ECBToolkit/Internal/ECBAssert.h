//
//  ECBAssert.h
//  ECBToolkit
//
//  Created by Tony Kieu on 11/1/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#import "ECBMacros.h"

#ifndef ECBAssert_h
#define ECBAssert_h

/*!
 Raises an `NSInvalidArgumentException` if the `condition` does not pass.
 Use `description` to supply the way to fix the exception.
 */
#define ECBParameterAssert(condition, description, ...) \
    do { \
        if (!(condition)) { \
            [NSException raise:NSInvalidArgumentException \
                        format:description, ##__VA_ARGS__]; \
        } \
    } while(0)

/*!
 Raises an `NSRangeException` if the `condition` does not pass.
 Use `description` to supply the way to fix the exception.
 */
#define ECBRangeAssert(condtion, description, ...) \
    do { \
        if (!(condition)) { \
            [NSException raise:NSRangeException \
                        format:description, ##__VA_ARGS__]; \
        } \
    } while(0)

/*!
 Raises an `NSInternalInconsistencyException` if the `condition` does not pass.
 Use `description` to supply the way to fix the exception.
 */
#define ECBConsistencyAssert(condition, description, ...) \
    do { \
        if (!(condition)) { \
            [NSException raise:NSInternalInconsistencyException \
                        format:description, ##__VA_ARGS__]; \
        } \
    } while(0)

/*! 
 Always raises `NSInternalInconsistencyException` with details about the method
 used and class that received the message.
 */
#define ECBNotDesignatedInitializer() \
    do { \
        ECBConsistencyAssert(NO, \
                             @"%@ is not the designated initializer for the instances of %@.", \
                             NSStringFromSelector(_cmd), \
                             NSStringFromClass([self class])); \
        return nil; \
    } while (0)

/*!
 Raises `NSInternalInconsistencyException` if current thread is not main thread.
 */
#define ECBAssertMainThread() \
    do { \
        ECBConsistencyAssert([NSThread isMainThread], @"This method must be called on the main thread."); \
    } while (0)

/*! 
 Raises `NSInternalInconsistencyException` if current thread is not the required on.
 */
#define ECBAssertIsOnThread(thread) \
    do { \
        ECBConsistencyAssert([NSThread currentThread] == thread, \
                             @"This method must be called on thread: %@", thread); \
    } while (0)

#endif /* ECBAssert_h */
