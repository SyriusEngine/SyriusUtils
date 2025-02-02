#include <chrono>
#include "../../include/SyriusUtils/Clock/Clock.hpp"

namespace Syrius{

    Time getTimeSeconds(){
        return std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    }

    Time getTimeMilliseconds(){
        return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    }

    Time getTimeMicroseconds(){
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    }

    Time getTimeNanoseconds(){
        return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
    }

}
