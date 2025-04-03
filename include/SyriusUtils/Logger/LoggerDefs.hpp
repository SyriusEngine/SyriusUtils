#pragma once

#include <fmt/core.h>
#include <string>

#include "../Types/Types.hpp"
#include "../ExportUtils.hpp"

typedef enum SR_MESSAGE_SEVERITY{
    SR_MESSAGE_SEVERITY_NONE        = 0x00,
    SR_MESSAGE_SEVERITY_INFO        = 0x01,
    SR_MESSAGE_SEVERITY_DEBUG       = 0x02,     // For debugging purposes only
    SR_MESSAGE_SEVERITY_PERFORMANCE = 0x03, // For performance related messages

    SR_MESSAGE_SEVERITY_LOW         = 0x10,     // mostly used for messages that are not important
    SR_MESSAGE_SEVERITY_MEDIUM      = 0x11,     // used for messages that are important, but not critical
    SR_MESSAGE_SEVERITY_HIGH        = 0x12,     // used for messages that are critical and (usually) results in program termination
    SR_MESSAGE_SEVERITY_FATAL       = 0x13,     // used for messages that are critical and results in program termination

    SR_MESSAGE_SEVERITY_UNKNOWN = 0xff,     // Sometimes, you just don't know the severity of the message
} SR_MESSAGE_SEVERITY;

namespace Syrius{

    struct Message{
        SR_MESSAGE_SEVERITY severity = SR_MESSAGE_SEVERITY_UNKNOWN;
        std::string source;
        std::string message;
        std::string function;
        std::string file;
        u32 line = 0;
    };

    /**
     * @brief Converts a SR_MESSAGE_SEVERITY enum to a std::string.
     * @param severity Severity enum to convert.
     * @return The severity as string.
     */
    SR_UTILS_API std::string getMessageSeverityString(SR_MESSAGE_SEVERITY severity);

}

template<>
struct fmt::formatter<SR_MESSAGE_SEVERITY> {
    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
        return ctx.begin();
    }

    template<typename FormatContext>
    auto format(const SR_MESSAGE_SEVERITY severity, FormatContext& ctx) const -> decltype(ctx.out()) {
        return fmt::format_to(ctx.out(), "{}", Syrius::getMessageSeverityString(severity));
    }
};