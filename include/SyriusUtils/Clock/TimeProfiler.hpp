#pragma once

#include "../Types/Types.hpp"
#include <string>
#include <unordered_map>
#include <chrono>

#include "Clock.hpp"

namespace Syrius{

    class TimeProfiler{
    public:
        /**
         * @brief Start the timer with the given name. If the timer is already running, it will reset the timer.
         *        If no timer with the given name exists, it will create a new one.
         * @param name The name of the (new) timer.
         */
        static void start(const std::string& name);

        /**
         * @brief Stop the timer with the given name. If the timer is not running, it will do nothing.
         * @param name The name of the timer to stop.
         */
        static void stop(const std::string& name);

        /**
         * @brief Get the elapsed time of all timers.
         * @return A map with the name of the timer as key and the elapsed time as value.
         */
        static const std::unordered_map<std::string, Duration>& getTimes();

    private:
        static std::unordered_map<std::string, TimePoint> m_startTime;
        static std::unordered_map<std::string, Duration> m_elapsedTime;
    };
}
