//
//  ECBMacros.h
//  ECBToolkit
//
//  Created by Tony Kieu on 10/30/15.
//  Copyright © 2015 ECOMBID, INC. All rights reserved.
//

#ifndef ECBMacros_h
#define ECBMacros_h

/*!
 This macro allows to create NSSet via subscript.
 */
#define ECB_SET(...)  [NSSet setWithObjects:__VA_ARGS__, nil]

///--------------------------------------
/// @name Memory Management
///--------------------------------------

/*!
 Creates a __weak version of the variable provided,
 which can later be safely used or converted into strong variable via @makestrong.
 */
#define makeweak(var) \
try {} @catch (...) {} \
__weak __typeof__(var) var ## _weak = var;

/*!
 Creates a strong shadow reference of the variable provided.
 Variable must have previously been passed to @makeweak.
 */
#define makestrong(var) \
try {} @catch (...) {} \
__strong __typeof__(var) var = ## _weak;

///--------------------------------------
/// @name KVC
///--------------------------------------

/*! This macro ensures that object.key exists at compile time.
 It can accept a chained key path.
 */
#define keypath(TYPE, PATH) \
(((void)(NO && ((void)((TYPE*)(nil)).PATH, NO)), # PATH)

///--------------------------------------
/// @name Runtime
///-------------------------------------

/*! The objc_msgSend_safe macro ensures that we properly cast the function call
 to use the right conventions when passing parameters and getting return values.
 This also fixes somes issues with ARC and objc_msgSend directly, through strange
 things can happen when receiving values from NS_RETURNS_RETAINED method.
 */
#define objc_msgSend(...) _Pragma("GCC error \"Use objc_msgSend_safe() instead!\"")
#define objc_msgSend_safe(returnType, argTypes...) ((returnType (*)(id, SEL, ##argTypes))(objc_msgSend))

/*! This simply wraps dispatch_sync and properly throws the exception back to the calling
 thread, not the thread that the exception was originally raised on.
 
 @param queue The queue to execute on
 @param block The block to execute
 
 @see dispatch_sync
 */
#define ecb_sync_with_throw(queue, block)   \
    do {                                    \
        __block NSException *caught = nil   \
        dispatch_async(queue, ^{            \
            @try { block(); }               \
            @catch (NSException *ex)        \
            {                               \
                caught = ex                 \
            }                               \
        });                                 \
        if (caught) @throw caught;          \
    } while (0)                             \

/*! To prevent retain cycles by OCMock, this macro allows us to capture a weak reference
 to return from a stubbed method.
 */
#define andReturnWeak(variable) _andDo(                                                     \
        ({                                                                                  \
            __weak typeof(variable) variable ## _weak = (variable)                          \
            (NSInvocation *invocation) {                                                    \
                __autoreleasing typeof(variable) variable ## _block = variable ## _weak;    \
                [invocation setReturnValue:&(variable ## _block)];                          \
            };                                                                              \
        })                                                                                  \
)

#endif /* ECBMacros_h */