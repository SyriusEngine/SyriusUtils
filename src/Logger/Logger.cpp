#include "../../include/SyriusUtils/Logger/Logger.hpp"

#include <iostream>

namespace Syrius{

    void defaultLogMessage(const Message& message){
        std::string msg = "[Syrius::Logger]";
        msg += " [" + message.file + " : " + message.function + " : " + std::to_string(message.line) + "] ";
        msg += "[" + getMessageSeverityString(message.severity) + "] ";
        msg += "[" + message.source + "]: ";
        msg += message.message;
        std::cout << msg << std::endl;
    }

    DebugCallback Logger::m_DebugCallback = defaultLogMessage;

    void Logger::setDebugCallback(DebugCallback callback){
        m_DebugCallback = callback;
    }

    void Logger::logMessage(const Message& message){
        m_DebugCallback(message);
    }

    void Logger::logInfo(const std::string& source, const std::string& message, const std::string& function, const std::string& file, u32 line){
        Message msg;
        msg.severity = SR_MESSAGE_SEVERITY_INFO;
        msg.source = source;
        msg.message = message;
        msg.function = function;
        msg.file = file;
        msg.line = line;
        logMessage(msg);
    }

    void Logger::logWarning(const std::string& source, const std::string& message, const std::string& function, const std::string& file, u32 line){
        Message msg;
        msg.severity = SR_MESSAGE_SEVERITY_MEDIUM;
        msg.source = source;
        msg.message = message;
        msg.function = function;
        msg.file = file;
        msg.line = line;
        logMessage(msg);
    }

    void Logger::logError(const std::string& source, const std::string& message, const std::string& function, const std::string& file, u32 line){
        Message msg;
        msg.severity = SR_MESSAGE_SEVERITY_HIGH;
        msg.source = source;
        msg.message = message;
        msg.function = function;
        msg.file = file;
        msg.line = line;
        logMessage(msg);
    }

    void Logger::logThrow(const std::string &source, const std::string &message, const std::string &function, const std::string &file, u32 line) {
        Message msg;
        msg.severity = SR_MESSAGE_SEVERITY_FATAL;
        msg.source = source;
        msg.message = message;
        msg.function = function;
        msg.file = file;
        msg.line = line;
        logMessage(msg);
        std::abort();
    }

}
