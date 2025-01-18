#include "../../include/SyriusUtils/Logger/Logger.hpp"

#include <iostream>
#include <sstream>

namespace Syrius{

    void defaultLogMessage(const Message& message){
        std::stringstream ss;
        ss << "[Syrius::Logger]";
        ss <<  " [" << message.file << " : " << message.function << " : " << std::to_string(message.line) << "] ";
        ss << "[" << getMessageSeverityString(message.severity) << "] ";
        ss << "[" << message.source << "]: ";
        ss << message.message;
        std::cout << ss.str() << std::endl;
    }

    DebugCallback Logger::m_DebugCallback = defaultLogMessage;

    void Logger::setDebugCallback(DebugCallback callback){
        m_DebugCallback = callback;
    }

    void Logger::logMessage(const Message& message){
        m_DebugCallback(message);
    }

}
