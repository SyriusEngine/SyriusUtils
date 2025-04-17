#pragma once

#include <SyriusUtils/Logger/LoggerDefs.hpp>
#include <fmt/core.h>

namespace Syrius{

    using DebugCallback = void(*)(const Message& message);

    void defaultLogger(const Message& message);

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
                        const std::string& function, const std::string& file, u32 line, Args&&... args){
            Message msg;
            msg.message = fmt::format(message, std::forward<Args>(args)...);
            msg.severity = severity;
            msg.source = source;
            msg.function = function;
            msg.file = file;
            msg.line = line;
            logMessage(msg);
        }

    private:
        static DebugCallback m_DebugCallback;

    };

    class SyriusAssert: public std::exception {
    public:
        template<typename... Args>
        SyriusAssert(const std::string& assertionType, const std::string& source, const std::string& message,
                        const std::string& function, const std::string& file, u32 line, Args&&... args){
            m_Message.message = fmt::format(message, std::forward<Args>(args)...);
            m_Message.severity = SR_MESSAGE_SEVERITY_FATAL;
            m_Message.source = source;
            m_Message.function = function;
            m_Message.file = file;
            m_Message.line = line;
            fmt::print("[{}:{}:{}] [{}] [{}]: {}\n", file, function, line, assertionType, source, m_Message.message);
        }

        [[nodiscard]] const char* what() const noexcept override {
            return m_Message.message.c_str();
        }

        [[nodiscard]] const Message& getMessage() const {
            return m_Message;
        }

    private:
        Message m_Message;
    };

}