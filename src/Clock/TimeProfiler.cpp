#include "../../include/SyriusUtils/Clock/TimeProfiler.hpp"

namespace Syrius{

    std::unordered_map<std::string, std::chrono::time_point<std::chrono::high_resolution_clock>> TimeProfiler::m_startTime;
    std::unordered_map<std::string, std::chrono::duration<double>> TimeProfiler::m_elapsedTime;

    void TimeProfiler::start(const std::string &name) {
        m_startTime[name] = std::chrono::high_resolution_clock::now();
    }

    void TimeProfiler::stop(const std::string &name) {
        auto stopTime = std::chrono::high_resolution_clock::now();
        m_elapsedTime[name] = stopTime - m_startTime[name];
    }

    Time TimeProfiler::getElapsedTimeSeconds(const std::string &name) {
        return std::chrono::duration_cast<std::chrono::seconds>(m_elapsedTime[name]).count();
    }

    Time TimeProfiler::getElapsedTimeMilliseconds(const std::string &name) {
        return std::chrono::duration_cast<std::chrono::milliseconds>(m_elapsedTime[name]).count();
    }

    Time TimeProfiler::getElapsedTimeMicroseconds(const std::string &name) {
        return std::chrono::duration_cast<std::chrono::microseconds>(m_elapsedTime[name]).count();
    }

    Time TimeProfiler::getElapsedTimeNanoseconds(const std::string &name) {
        return std::chrono::duration_cast<std::chrono::nanoseconds>(m_elapsedTime[name]).count();
    }

    std::unordered_map<std::string, std::chrono::duration<double>> TimeProfiler::getTimes() {
        return m_elapsedTime;
    }
}
