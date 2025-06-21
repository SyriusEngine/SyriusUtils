#pragma once

#include <SyriusUtils/Clock/Clock.hpp>

namespace Syrius {

    /**
     * @brief Converts a TimePoint to an ISO8601 formatted string.
     * @param tp TimePoint to convert
     * @param format String format
     * @return
     */
    std::string toString(TimePoint tp, const std::string& format = "%Y-%m-%d %H:%M:%S");

    std::string toString(Duration duration);
}