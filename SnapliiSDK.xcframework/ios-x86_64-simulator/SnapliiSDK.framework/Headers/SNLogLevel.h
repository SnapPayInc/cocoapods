//
//  SNLogLevel.h
//  SnapPay
//
//  Created by Tony on 2023-10-03.
//  Copyright © 2023 Snaplii. All rights reserved.
//

typedef NSUInteger SN_LOG_LEVEL;

static const NSUInteger SN_LOG_FLAG_FATAL = 1 << 0; // 0...000001
static const NSUInteger SN_LOG_FLAG_ERROR = 1 << 1; // 0...000010
static const NSUInteger SN_LOG_FLAG_WARN = 1 << 2; // 0...000100
static const NSUInteger SN_LOG_FLAG_INFO = 1 << 3; // 0...001000
static const NSUInteger SN_LOG_FLAG_DEBUG = 1 << 4; // 0...010000
static const NSUInteger SN_LOG_FLAG_VERBOSE = 1 << 5; // 0...100000

static const NSUInteger SN_LOG_LEVEL_FATAL = SN_LOG_FLAG_FATAL; // 0...000001
static const NSUInteger SN_LOG_LEVEL_ERROR = SN_LOG_FLAG_ERROR | SN_LOG_LEVEL_FATAL; // 0...000011
static const NSUInteger SN_LOG_LEVEL_WARN = SN_LOG_FLAG_WARN | SN_LOG_LEVEL_ERROR; // 0...000111
static const NSUInteger SN_LOG_LEVEL_INFO = SN_LOG_FLAG_INFO | SN_LOG_LEVEL_WARN; // 0...001111
static const NSUInteger SN_LOG_LEVEL_DEBUG = SN_LOG_FLAG_DEBUG | SN_LOG_LEVEL_INFO; // 0...011111
static const NSUInteger SN_LOG_LEVEL_VERBOSE = SN_LOG_FLAG_VERBOSE | SN_LOG_LEVEL_DEBUG; // 0...111111
