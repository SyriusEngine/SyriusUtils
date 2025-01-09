#pragma once

#include "Logger.hpp"

#define SR_LOG(severity, source, message, ...) \
    if constexpr(Syrius::Priv::hasVariadicArgs(__VA_ARGS__)){ \
        Syrius::Logger::log(severity, source, message, SR_FUNC, SR_FILE, SR_LINE, ##__VA_ARGS__); \
    } \
    else{ \
        Syrius::Logger::log(severity, source,  "%s", SR_FUNC, SR_FILE, SR_LINE, message); \
    }

#define SR_LOG_INFO(source, message, ...) SR_LOG(SR_MESSAGE_SEVERITY_INFO, source, message, ##__VA_ARGS__)
#define SR_LOG_WARNING(source, message, ...) SR_LOG(SR_MESSAGE_SEVERITY_MEDIUM, source, message, ##__VA_ARGS__)
#define SR_LOG_ERROR(source, message, ...) SR_LOG(SR_MESSAGE_SEVERITY_HIGH, source, message, ##__VA_ARGS__)
#define SR_LOG_THROW(source, message, ...) SR_LOG(SR_MESSAGE_SEVERITY_FATAL, source, message, ##__VA_ARGS__)

#define SR_LOG_INFO_IF_FALSE(condition, source, message, ...) \
    if (!(condition)){                                        \
        SR_LOG_INFO(source, message, ##__VA_ARGS__);           \
    }

#define SR_LOG_WARNING_IF_FALSE(condition, source, message, ...) \
    if (!(condition)){                                           \
        SR_LOG_WARNING(source, message, ##__VA_ARGS__);           \
    }

#define SR_LOG_ERROR_IF_FALSE(condition, source, message, ...) \
    if (!(condition)){                                         \
        SR_LOG_ERROR(source, message, ##__VA_ARGS__);           \
    }

#define SR_LOG_THROW_IF_FALSE(condition, source, message, ...) \
    if (!(condition)){                                         \
        SR_LOG_THROW(source, message, ##__VA_ARGS__);           \
    }
