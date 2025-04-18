#pragma once

#include <SyriusUtils/Clock/TimeProfiler.hpp>

#if defined(SR_DEBUG)

#define SR_START_TIMER(name) Syrius::TimeProfiler::start(name)
#define SR_STOP_TIMER(name) Syrius::TimeProfiler::stop(name)
#define SR_GET_TIME(name) Syrius::TimeProfiler::getElapsedTime(name)

#else

#define SR_START_TIMER(name)
#define SR_STOP_TIMER(name)
#define SR_GET_TIME(name)

#endif