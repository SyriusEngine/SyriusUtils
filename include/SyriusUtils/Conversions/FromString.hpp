#pragma once

#include <SyriusUtils/Clock/Clock.hpp>
#include <SyriusUtils/Logger/LoggerMacros.hpp>

namespace Syrius {

    template<typename T>
    T fromString(const std::string& str) {
        static_assert(std::string("fromString not supported for type") + typeid(T).name());
        return T{};
    }

    template<>
    TimePoint fromString(const std::string& str);

    template<>
    Duration fromString(const std::string& str);
}

