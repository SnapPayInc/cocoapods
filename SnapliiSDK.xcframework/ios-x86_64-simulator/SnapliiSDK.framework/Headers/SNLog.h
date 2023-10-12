//
//  SNLog.h
//  SnapPay
//
//  Created by Tony on 2023-10-02.
//  Copyright © 2023 Snaplii. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SNLogLevel.h"

NS_ASSUME_NONNULL_BEGIN

#define SNLogDebug(frmt, ...) [SNLog debug:__FILE__ function:__PRETTY_FUNCTION__ line:__LINE__ format:(frmt), ## __VA_ARGS__]

#define SNLogInfo(frmt, ...) [SNLog info: __FILE__ function: __PRETTY_FUNCTION__ line: __LINE__ format: (frmt), ## __VA_ARGS__]

#define SNLogError(frmt, ...)                                 \
[SNLog error: __FILE__                                     \
    function: __PRETTY_FUNCTION__                               \
        line: __LINE__                                     \
        format: (frmt), ## __VA_ARGS__]

#define SNLogFatal(frmt, ...) [SNLog fatal: __FILE__ function: __PRETTY_FUNCTION__ line: __LINE__ format: (frmt), ## __VA_ARGS__]

@interface SNLog : NSObject

+ (void)debug:(const char *)file
     function:(const char *)function
         line:(NSUInteger)line
       format:(NSString *)format, ...;

+ (void)info:(const char *)file
    function:(const char *)function
        line:(NSUInteger)line
      format:(NSString *)format, ...;

+ (void)error:(const char *)file
     function:(const char *)function
         line:(NSUInteger)line
       format:(NSString *)format, ...;

+ (void)fatal:(const char *)file
     function:(const char *)function
         line:(NSUInteger)line
       format:(NSString *)format, ...;

// used for swift
+ (void)log:(SN_LOG_LEVEL)flag
       file:(const char *)file
   function:(const char *)function
       line:(NSUInteger)line
     format:(NSString *)format
       args:(va_list)args;

@end

NS_ASSUME_NONNULL_END
