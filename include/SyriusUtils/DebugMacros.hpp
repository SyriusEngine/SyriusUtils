#pragma once

#include <cstddef>
#include <cstdio>
#include <vector>
#include <string>
#include "PlatformDetection.hpp"

namespace Syrius{

    namespace Priv{
        template<typename... Args>
        void format_assert(const char* condition, const char* file, const char* func, int line, const char* message, Args... args){
            std::size_t size = snprintf(nullptr, 0, message, args...);
            std::vector<char> buffer(size + 1);
            snprintf(buffer.data(), size + 1, message, args...);

            printf("[ASSERT]: [%s : %s : %i]: Condition: %s failed: %s\n", file, func, line, buffer.data());
            fflush(stdout); // print message BEFORE program halts
            std::abort();
        }
    }
}

#if defined(SR_DEBUG)

    #define SR_ASSERT(condition, msg, ...)                                                              \
        if (!(condition)) {                                                                             \
            if constexpr (sizeof(#__VA_ARGS__)){                                                        \
                Syrius::Priv::format_assert(#condition, SR_FILE, SR_FUNC, SR_LINE, msg, ##__VA_ARGS__); \
            }                                                                                           \
            else{                                                                                       \
                Syrius::Priv::format_assert(#condition, SR_FILE, SR_FUNC, SR_LINE, "%s", msg);          \
            }                                                                                           \
        }

    #define SR_PRECONDITION(condition, msg, ...) SR_ASSERT(condition, msg, ##__VA_ARGS__)
    #define SR_POSTCONDITION(condition, msg, ...) SR_ASSERT(condition, msg, ##__VA_ARGS__)
#else
    #define SR_ASSERT(condition, msg, ...)
    #define SR_PRECONDITION(condition, msg, ...)
    #define SR_POSTCONDITION(condition, msg, ...)
#endif