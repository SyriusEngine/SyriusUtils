#pragma once

#include "Logger.hpp"

#define SR_LOG_INFO(source, message) Syrius::Logger::logInfo(source, message, SR_FUNC, SR_FILE, SR_LINE)
#define SR_LOG_WARNING(source, message) Syrius::Logger::logWarning(source, message, SR_FUNC, SR_FILE, SR_LINE)
#define SR_LOG_ERROR(source, message) Syrius::Logger::logError(source, message, SR_FUNC, SR_FILE, SR_LINE)
#define SR_LOG_THROW(source, message) Syrius::Logger::logThrow(source, message, SR_FUNC, SR_FILE, SR_LINE)