#pragma once

#include "LoggerDefs.hpp"

namespace Syrius{

    using DebugCallback = void(*)(const Message& message);

    class SR_UTILS_API Logger{
    public:
        Logger() = delete;

        static void setDebugCallback(DebugCallback callback);

        static void logMessage(const Message& message);

        static void logInfo(const std::string& source, const std::string& message, const std::string& function, const std::string& file, u32 line);

        static void logWarning(const std::string& source, const std::string& message, const std::string& function, const std::string& file, u32 line);

        static void logError(const std::string& source, const std::string& message, const std::string& function, const std::string& file, u32 line);

        static void logThrow(const std::string& source, const std::string& message, const std::string& function, const std::string& file, u32 line);

    private:
        static DebugCallback m_DebugCallback;

    };

}