#include <SyriusUtils/Clock/TimeProfiler.hpp>

namespace Syrius{

    std::unordered_map<std::string, TimePoint> TimeProfiler::m_startTime;
    std::unordered_map<std::string, Duration> TimeProfiler::m_elapsedTime;

    void TimeProfiler::start(const std::string &name) {
        m_startTime[name] = getTime();
    }

    void TimeProfiler::stop(const std::string &name) {
        const TimePoint stopTime = getTime();
        m_elapsedTime[name] = stopTime - m_startTime[name];
    }

    Duration TimeProfiler::getElapsedTime(const std::string &name) {
        auto it = m_elapsedTime.find(name);
        if (it != m_elapsedTime.end()) {
            return it->second;
        }
        return Duration(0);
    }

    const std::unordered_map<std::string, Duration>& TimeProfiler::getTimes() {
        return m_elapsedTime;
    }
}
