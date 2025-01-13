#pragma once

#include "PlatformDetection.hpp"
#include "ExportUtils.hpp"
#include "Conditions.hpp"

#include "Types/Types.hpp"
#include "Types/SymbolicTypes.hpp"

#include "Logger/LoggerDefs.hpp"
#include "Logger/Logger.hpp"
#include "Logger/LoggerMacros.hpp"

#include "ResourceView.hpp"

namespace Syrius{

    /**
     * @brief Generates a random UID excluding 0.
     * @return random UID.
     */
    SR_UTILS_API UID generateID();

}