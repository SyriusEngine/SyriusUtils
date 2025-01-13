#pragma once

#include "LoggerDefs.hpp"
#include <vector>

namespace Syrius{

    using DebugCallback = void(*)(const Message& message);

    class SR_UTILS_API Logger{
    public:
        Logger() = delete;

        static void setDebugCallback(DebugCallback callback);

        static void logMessage(const Message& message);

        template<typename... Args>
        static void log(SR_MESSAGE_SEVERITY severity, const std::string& source, const std::string& message,
                        const std::string& function, const std::string& file, u32 line, Args... args){
            Message msg;
            if constexpr (sizeof...(args) != 0 ){
                std::size_t size = snprintf(nullptr, 0, message.c_str(), args...);
                std::vector<char> buffer(size + 1);
                snprintf(buffer.data(), size + 1, message.c_str(), args...);
                std::string formattedMessage(buffer.data());

                msg.message = formattedMessage;
            }
            else{
                msg.message = message;
            }
            msg.severity = severity;
            msg.source = source;
            msg.function = function;
            msg.file = file;
            msg.line = line;
            logMessage(msg);
            if (severity == SR_MESSAGE_SEVERITY_FATAL){
                std::abort();
            }
        }

    private:
        static DebugCallback m_DebugCallback;

    };

}