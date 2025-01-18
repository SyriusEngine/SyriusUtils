#pragma once

#include <cstddef>
#include <cstdio>
#include <vector>
#include <string>
#include "PlatformDetection.hpp"

namespace Syrius::Priv {

    template<typename... Args>
    void formatAssert(const char* assertionType, const char* condition, const char* file, const char* func, int line, char const* const message, Args... args){
        if constexpr (sizeof...(args) == 0){
            printf("[%s]: [%s : %s : %i]: Condition: %s failed\n", assertionType, file, func, line, condition);
        }
        else{
            std::size_t size = snprintf(nullptr, 0, message, args...);
            std::vector<char> buffer(size + 1);
            snprintf(buffer.data(), size + 1, message, args...);

            printf("[%s]: [%s : %s : %i]: Condition: %s failed: %s\n", assertionType, file, func, line, condition, buffer.data());
        }
        fflush(stdout); // print message BEFORE program halts
        std::abort();
    }
}

#if defined(SR_DEBUG)

    #define SR_ASSERT(condition, msg, ...) if (!(condition)) Syrius::Priv::formatAssert("ASSERT", #condition, SR_FILE, SR_FUNC, SR_LINE, msg, ##__VA_ARGS__);

    #define SR_PRECONDITION(condition, msg, ...) if (!(condition)) Syrius::Priv::formatAssert("PRECONDITION", #condition, SR_FILE, SR_FUNC, SR_LINE, msg, ##__VA_ARGS__);
    #define SR_POSTCONDITION(condition, msg, ...) if (!(condition)) Syrius::Priv::formatAssert("POSTCONDITION", #condition, SR_FILE, SR_FUNC, SR_LINE, msg, ##__VA_ARGS__);
#else
    #define SR_ASSERT(condition, msg, ...)
    #define SR_PRECONDITION(condition, msg, ...)
    #define SR_POSTCONDITION(condition, msg, ...)
#endif