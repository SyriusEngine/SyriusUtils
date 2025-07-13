#include <SyriusUtils/Conversions/ToString.hpp>
#include <sstream>
#include <iomanip>

namespace Syrius {

    std::string toString(const TimePoint tp, const std::string& format) {
        using namespace std::chrono;

        const system_clock::time_point systemTimePoint = system_clock::time_point(duration_cast<system_clock::duration>(tp.time_since_epoch()));
        const std::time_t tt = std::chrono::system_clock::to_time_t(systemTimePoint);
        const tm tmVal = *gmtime(&tt);
        std::stringstream ss;
        ss << std::put_time(&tmVal, format.c_str());
        return ss.str();
    }

    std::string toString(const SystemTimePoint tp, const std::string &format) {
        const std::time_t tt = std::chrono::system_clock::to_time_t(tp);
        const std::tm tmVal = *std::gmtime(&tt); // Use std::localtime(&tt) for local time
        std::stringstream ss;
        ss << std::put_time(&tmVal, format.c_str());
        return ss.str();
    }

    std::string toString(const Duration duration) {
        std::ostringstream ss;
        ss << duration.count();
        return ss.str();
    }

}
