#pragma once

#include "../PlatformDetection.hpp"
#include "Logger.hpp"

#if defined(SR_DEBUG)

    #define SR_ASSERT(condition, msg, ...) if (!(condition)) throw Syrius::SyriusAssert("ASSERT", #condition, msg, SR_FUNC, SR_FILE, SR_LINE, ##__VA_ARGS__);

    #define SR_PRECONDITION(condition, msg, ...) if (!(condition)) throw Syrius::SyriusAssert("PRECONDITION", #condition, msg, SR_FUNC, SR_FILE, SR_LINE, ##__VA_ARGS__);
    #define SR_POSTCONDITION(condition, msg, ...) if (!(condition)) throw Syrius::SyriusAssert("POSTCONDITION", #condition, msg, SR_FUNC, SR_FILE, SR_LINE, ##__VA_ARGS__);
#else
    #define SR_ASSERT(condition, msg, ...)
    #define SR_PRECONDITION(condition, msg, ...)
    #define SR_POSTCONDITION(condition, msg, ...)
#endif