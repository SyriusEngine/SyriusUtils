#pragma once

#include "../Types/Types.hpp"
#include "../ExportUtils.hpp"

namespace Syrius{

    /**
     * @brief Returns the current time in seconds.
     * @return Time in seconds.
     */
    SR_UTILS_API Time getTimeSeconds();

    /**
     * @brief Returns the current time in milliseconds.
     * @return Time in milliseconds.
     */
    SR_UTILS_API Time getTimeMilliseconds();

    /**
     * @brief Returns the current time in microseconds.
     * @return Time in microseconds.
     */
    SR_UTILS_API Time getTimeMicroseconds();

    /**
     * @brief Returns the current time in nanoseconds.
     * @return Time in nanoseconds.
     */
    SR_UTILS_API Time getTimeNanoseconds();

}