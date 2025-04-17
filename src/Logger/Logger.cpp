#include <SyriusUtils/Logger/Logger.hpp>

namespace Syrius{

    void defaultLogger(const Message& message){
        fmt::print("[{}:{}:{}] [{}] [{}]: {}\n",
            message.file, message.function, message.line,
            message.source, message.severity, message.message);
    }

    DebugCallback Logger::m_DebugCallback = defaultLogger;

    void Logger::setDebugCallback(DebugCallback callback){
        m_DebugCallback = callback;
    }

    void Logger::logMessage(const Message& message){
        m_DebugCallback(message);
    }

}
