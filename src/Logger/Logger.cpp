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

}
