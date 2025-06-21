#pragma once

#include <SyriusUtils/Types/Types.hpp>
#include <SyriusUtils/ExportUtils.hpp>

#include <chrono>

namespace Syrius{

    using namespace std::chrono_literals;

    using Duration = std::chrono::duration<double, std::milli>;
    using TimePoint = std::chrono::time_point<std::chrono::high_resolution_clock, Duration>;

    inline TimePoint getTime(){
        return std::chrono::high_resolution_clock::now();
    }

    inline TimePoint timeFromEpoch(const u64 time) {
        return TimePoint(Duration{static_cast<double>(time)});
    }

    inline TimePoint timeFromEpoch(const double time) {
        return TimePoint(Duration{time});
    }

}