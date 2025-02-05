#pragma once

#include <stdexcept>

#include "LoggerDefs.hpp"
#include <vector>

namespace Syrius{

    using DebugCallback = void(*)(const Message& message);

    class SR_UTILS_API Logger{
    public:
        Logger() = delete;

        /**
         * @brief Allows the user to set a custom callback function that will be called when a message is logged.
         * @param callback Function pointer to the custom callback function.
         */
        static void setDebugCallback(DebugCallback callback);

        /**
         * @brief Logs a message and calls the callback function.
         * @param message The message to log.
         */
        static void logMessage(const Message& message);

        /**
         * @brief Creates a new message object and logs it. This function is used by various macro's that provide
         *        compile time constants such as file, function and line.
         * @tparam Args Optional arguments to log.
         * @param severity Severity of the message.
         * @param source What component in the Syrius framework logs the message?
         * @param message Extra info/description.
         * @param function Which function logged the message.
         * @param file In which file is this function located?
         * @param line On what line did the logging take place?
         * @param args Optional arguments to log.
         */
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
                throw std::runtime_error(msg.message);
            }
        }

    private:
        static DebugCallback m_DebugCallback;

    };

}