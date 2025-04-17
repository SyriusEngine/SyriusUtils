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

}