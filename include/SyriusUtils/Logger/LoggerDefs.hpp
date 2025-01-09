#pragma once

#include "../Types.hpp"
#include "../ExportUtils.hpp"

#include <string>

namespace Syrius{

    typedef enum SR_MESSAGE_SEVERITY{
        SR_MESSAGE_SEVERITY_NONE    = 0x00,
        SR_MESSAGE_SEVERITY_INFO    = 0x01,
        SR_MESSAGE_SEVERITY_LOW     = 0x02,     // mostly used for messages that are not important
        SR_MESSAGE_SEVERITY_MEDIUM  = 0x03,     // used for messages that are important, but not critical
        SR_MESSAGE_SEVERITY_HIGH    = 0x04,     // used for messages that are critical and (usually) results in program termination
        SR_MESSAGE_SEVERITY_FATAL   = 0x05,     // used for messages that are critical and results in program termination

        SR_MESSAGE_SEVERITY_UNKNOWN = 0xff,     // Sometimes, you just don't know the severity of the message
    } SR_MESSAGE_SEVERITY;

    struct Message{
        SR_MESSAGE_SEVERITY severity;
        std::string source;
        std::string message;
        std::string function;
        std::string file;
        u32 line;
    };

    SR_UTILS_API std::string getMessageSeverityString(SR_MESSAGE_SEVERITY severity);

}