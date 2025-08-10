#pragma once

#include <SyriusUtils/Clock/Clock.hpp>
#include <SyriusUtils/Logger/LoggerMacros.hpp>
#include <SyriusUtils/SyriusTypeTraits.hpp>
#include <string>

namespace Syrius {

    template<typename T>
    T fromString(const std::string& str) {
        SR_STATIC_ASSERT_TYPE(T);
        return T{}; // prevent -Wreturn
    }

    template<>
    TimePoint fromString(const std::string& str);

    template<>
    SystemTimePoint fromString(const std::string& str);

    template<>
    Duration fromString(const std::string& str);
}

