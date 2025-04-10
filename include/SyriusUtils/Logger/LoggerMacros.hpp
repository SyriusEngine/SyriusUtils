#pragma once

#include "Logger.hpp"

#define SR_LOG_THROW(source, message, ...) \
    throw std::runtime_error(fmt::format("[{}:{}:{}] [EXCEPTION] [{}]: {}\n", SR_FILE, SR_FUNC, SR_LINE, source, fmt::format(message, ##__VA_ARGS__)));

#define SR_LOG(severity, source, message, ...) \
    if constexpr (sizeof(#__VA_ARGS__) > 1) { \
        Syrius::Logger::log(severity, source, message, SR_FUNC, SR_FILE, SR_LINE, ##__VA_ARGS__); \
    } else { \
        Syrius::Logger::log(severity, source, "{}", SR_FUNC, SR_FILE, SR_LINE, message); \
    }

#define SR_LOG_IF_FALSE(condition, severity, source, message, ...) \
    if (!(condition)){                                        \
        SR_LOG(severity, source, message, ##__VA_ARGS__);           \
    }

#if defined(SR_DEBUG)

#define SR_LOG_INFO(source, message, ...) SR_LOG(SR_MESSAGE_SEVERITY_INFO, source, message, ##__VA_ARGS__)
#define SR_LOG_DEBUG(source, message, ...) SR_LOG(SR_MESSAGE_SEVERITY_DEBUG, source, message, ##__VA_ARGS__)
#define SR_LOG_PERFORMANCE(source, message, ...) SR_LOG(SR_MESSAGE_SEVERITY_PERFORMANCE, source, message, ##__VA_ARGS__)
#define SR_LOG_WARNING(source, message, ...) SR_LOG(SR_MESSAGE_SEVERITY_MEDIUM, source, message, ##__VA_ARGS__)
#define SR_LOG_ERROR(source, message, ...) SR_LOG(SR_MESSAGE_SEVERITY_HIGH, source, message, ##__VA_ARGS__)


#define SR_LOG_INFO_IF_FALSE(condition, source, message, ...) SR_LOG_IF_FALSE(condition, SR_MESSAGE_SEVERITY_INFO, source, message, ##__VA_ARGS__)
#define SR_LOG_DEBUG_IF_FALSE(condition, source, message, ...) SR_LOG_IF_FALSE(condition, SR_MESSAGE_SEVERITY_DEBUG, source, message, ##__VA_ARGS__)
#define SR_LOG_PERFORMANCE_IF_FALSE(condition, source, message, ...) SR_LOG_IF_FALSE(condition, SR_MESSAGE_SEVERITY_PERFORMANCE, source, message, ##__VA_ARGS__)
#define SR_LOG_WARNING_IF_FALSE(condition, source, message, ...) SR_LOG_IF_FALSE(condition, SR_MESSAGE_SEVERITY_MEDIUM, source, message, ##__VA_ARGS__)
#define SR_LOG_ERROR_IF_FALSE(condition, source, message, ...) SR_LOG_IF_FALSE(condition, SR_MESSAGE_SEVERITY_HIGH, source, message, ##__VA_ARGS__)

#else
#define SR_LOG_INFO(source, message, ...)
#define SR_LOG_DEBUG(source, message, ...)
#define SR_LOG_PERFORMANCE(source, message, ...)
#define SR_LOG_WARNING(source, message, ...)
#define SR_LOG_ERROR(source, message, ...)

#define SR_LOG_INFO_IF_FALSE(condition, source, message, ...)
#define SR_LOG_DEBUG_IF_FALSE(condition, source, message, ...)
#define SR_LOG_PERFORMANCE_IF_FALSE(condition, source, message, ...)
#define SR_LOG_WARNING_IF_FALSE(condition, source, message, ...)
#define SR_LOG_ERROR_IF_FALSE(condition, source, message, ...)
#endif
