#include <SyriusUtils/Logger/LoggerDefs.hpp>

namespace Syrius{

    std::string getMessageSeverityString(SR_MESSAGE_SEVERITY severity){
        switch (severity){
            case SR_MESSAGE_SEVERITY_NONE:          return "NONE";
            case SR_MESSAGE_SEVERITY_INFO:          return "INFO";
            case SR_MESSAGE_SEVERITY_DEBUG:         return "DEBUG";
            case SR_MESSAGE_SEVERITY_PERFORMANCE:   return "PERFORMANCE";
            case SR_MESSAGE_SEVERITY_LOW:           return "LOW";
            case SR_MESSAGE_SEVERITY_MEDIUM:        return "MEDIUM";
            case SR_MESSAGE_SEVERITY_HIGH:          return "HIGH";
            case SR_MESSAGE_SEVERITY_FATAL:         return "FATAL";
            default:
                return "UNKNOWN";
        }
    }

}
