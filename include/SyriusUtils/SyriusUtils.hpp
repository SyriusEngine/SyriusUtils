#pragma once

#include "PlatformDetection.hpp"
#include "Types.hpp"
#include "ResourceView.hpp"
#include "ExportUtils.hpp"


namespace Syrius{

    #if defined(SR_DEBUG)
        SR_UTILS_API const static bool s_SyriusDebugMode = true;
    #else
        SR_UTILS_API const static bool s_SyriusDebugMode = false;
    #endif

    int add(int a, int b);
}