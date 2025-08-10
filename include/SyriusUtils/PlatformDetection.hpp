#pragma once

// Identify OS
#if defined(WIN64) || defined(_WIN64) || defined(WIN32)
    #define SR_PLATFORM_WIN64 // TODO: This is ambiguous since WIN32 is also defined in the if statement

#elif defined(__linux__)
    #define SR_PLATFORM_LINUX

#else
    #error "Platform not supported"
#endif

// Identify toolchain
#if defined(_MSC_VER)
    #define SR_COMPILER_MSVC

    // This is some bs right here but it works
    #define and &&
    #define or ||

    #define SR_FILE __FILE__
    #define SR_LINE __LINE__
    #define SR_FUNC __FUNCSIG__

#elif defined(__MINGW64__)
    #define SR_COMPILER_MINGW_W64

    #define SR_FILE __FILE__
    #define SR_LINE __LINE__
    #define SR_FUNC __FUNCTION__

#elif defined(__GNUC__)
    #define SR_COMPILER_GCC

    #define SR_FILE __FILE__
    #define SR_LINE __LINE__
    #define SR_FUNC __PRETTY_FUNCTION__

#elif defined(__clang__)
    #define SR_COMPILER_CLANG

    #define SR_FILE __FILE__
    #define SR_LINE __LINE__
    #define SR_FUNC __PRETTY_FUNCTION__

#else
    #error "Compiler is not supported"
#endif

namespace Syrius::Priv{

    template <typename... Args>
    constexpr bool hasVariadicArgs(Args&&...) { return sizeof...(Args) > 0; }
}



