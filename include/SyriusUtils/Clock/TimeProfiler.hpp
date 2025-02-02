#pragma once

#include "../Types/Types.hpp"
#include <string>
#include <unordered_map>
#include <chrono>

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
         * @brief Get the elapsed time in seconds of the timer with the given name.
         * @param name The name of the timer.
         * @return The elapsed time in seconds.
         */
        static Time getElapsedTimeSeconds(const std::string& name);

        /**
         * @brief Get the elapsed time in milliseconds of the timer with the given name.
         * @param name The name of the timer.
         * @return The elapsed time in milliseconds.
         */
        static Time getElapsedTimeMilliseconds(const std::string& name);

        /**
         * @brief Get the elapsed time in microseconds of the timer with the given name.
         * @param name The name of the timer.
         * @return The elapsed time in microseconds.
         */
        static Time getElapsedTimeMicroseconds(const std::string& name);

        /**
         * @brief Get the elapsed time in nanoseconds of the timer with the given name.
         * @param name The name of the timer.
         * @return The elapsed time in nanoseconds.
         */
        static Time getElapsedTimeNanoseconds(const std::string& name);

        /**
         * @brief Get the elapsed time of all timers.
         * @return A map with the name of the timer as key and the elapsed time as value.
         */
        static std::unordered_map<std::string, std::chrono::duration<double>> getTimes();

    private:
        static std::unordered_map<std::string, std::chrono::time_point<std::chrono::high_resolution_clock>> m_startTime;
        static std::unordered_map<std::string, std::chrono::duration<double>> m_elapsedTime;
    };
}