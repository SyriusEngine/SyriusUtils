#include <SyriusUtils/Conversions/FromString.hpp>
#include <sstream>
#include <iomanip>

namespace Syrius {

    static const std::string s_FROM_STRING_LOGGER = "FromString";

    template<>
    TimePoint fromString(const std::string& str) {
        const std::string format = "%Y-%m-%d %H:%M:%S";

        std::tm timeInfo = {};
        std::istringstream ss(str);
        ss >> std::get_time(&timeInfo, format.c_str());
        if (ss.fail()) {
            SR_LOG_THROW(s_FROM_STRING_LOGGER, "Failed to parse string {} to a TimePoint", str);
        }

#if defined(SR_PLATFORM_WIN64)
        const std::time_t tt = _mkgmtime(&timeInfo);
#else
        const std::time_t tt = timegm (&timeInfo);
#endif

        using namespace std::chrono;

        const time_point<system_clock, Duration> point = system_clock::from_time_t(tt);
        return TimePoint(duration_cast<TimePoint::duration>(point.time_since_epoch()));
    }

    template<>
    SystemTimePoint fromString<SystemTimePoint>(const std::string& str) {
        const std::string format = "%Y-%m-%d %H:%M:%S";

        std::tm timeInfo = {};
        std::istringstream ss(str);
        ss >> std::get_time(&timeInfo, format.c_str());
        if (ss.fail()) {
            SR_LOG_THROW(s_FROM_STRING_LOGGER, "Failed to parse string {} to a system_clock::time_point", str);
        }

#if defined(SR_PLATFORM_WIN64)
        std::time_t tt = _mkgmtime(&timeInfo);
#else
        std::time_t tt = timegm(&timeInfo);
#endif

        return std::chrono::system_clock::from_time_t(tt);
    }

    template<>
    Duration fromString(const std::string& str) {
        double value = 0.0;
        std::istringstream ss(str);
        ss >> value;
        if (ss.fail()) {
            SR_LOG_THROW(s_FROM_STRING_LOGGER, "Failed to parse string {} to a Duration", str)
        }
        return Duration(value);

    }

}
