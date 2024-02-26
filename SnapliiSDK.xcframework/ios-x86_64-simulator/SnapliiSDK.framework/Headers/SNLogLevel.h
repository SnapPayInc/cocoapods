//
//  SNLogLevel.h
//  SnapPay
//
//  Created by Tony on 2023-10-03.
//  Copyright © 2023 Snaplii. All rights reserved.
//

/**
flag 系统默认枚举值的位移范围是 0 到 4，不要和宿主 app 的自定义枚举重复
*/

typedef NSUInteger SN_LOG_LEVEL;

#undef DDLogError
#undef DDLogWarn
#undef DDLogInfo
#undef DDLogDebug
#undef DDLogVerbose

static const NSUInteger SN_LOG_FLAG_FATAL = 1 << 10;
static const NSUInteger SN_LOG_FLAG_ERROR = 1 << 11;
static const NSUInteger SN_LOG_FLAG_WARN = 1 << 12;
static const NSUInteger SN_LOG_FLAG_INFO = 1 << 13;
static const NSUInteger SN_LOG_FLAG_DEBUG = 1 << 14;
static const NSUInteger SN_LOG_FLAG_VERBOSE = 1 << 15;

static const NSUInteger SN_LOG_LEVEL_FATAL = SN_LOG_FLAG_FATAL; // 0...000001
static const NSUInteger SN_LOG_LEVEL_ERROR = SN_LOG_FLAG_ERROR | SN_LOG_LEVEL_FATAL; // 0...000011
static const NSUInteger SN_LOG_LEVEL_WARN = SN_LOG_FLAG_WARN | SN_LOG_LEVEL_ERROR; // 0...000111
static const NSUInteger SN_LOG_LEVEL_INFO = SN_LOG_FLAG_INFO | SN_LOG_LEVEL_WARN; // 0...001111
static const NSUInteger SN_LOG_LEVEL_DEBUG = SN_LOG_FLAG_DEBUG | SN_LOG_LEVEL_INFO; // 0...011111
static const NSUInteger SN_LOG_LEVEL_VERBOSE = SN_LOG_FLAG_VERBOSE | SN_LOG_LEVEL_DEBUG; // 0...111111

// context 系统默认是0，不要和宿主 app 的自定义 context 重复
static const NSUInteger SN_LOG_CONTEXT = 777;
