#pragma once

#include "PlatformDetection.hpp"

#if defined(SR_PLATFORM_WIN64)
    #if defined(SR_UTILS_IMPORT)
        #define SR_UTILS_API __declspec(dllimport)
    #else
        #if defined(SR_UTILS_EXPORT)
            #define SR_UTILS_API __declspec(dllexport)
        #else
            #define SR_UTILS_API __declspec(dllexport)
        #endif
    #endif
#else
    #define SR_UTILS_API

#endif