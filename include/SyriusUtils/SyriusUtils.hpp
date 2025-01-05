#pragma once

#include "PlatformDetection.hpp"
#include "Types.hpp"
#include "ResourceView.hpp"
#include "ExportUtils.hpp"

namespace Syrius{

    /**
     * @brief Generates a random UID excluding 0.
     * @param seed If the seed is set to 0, a random seed will be selected.
     * @return random UID.
     */
    SR_UTILS_API UID generateID(u64 seed = 0);

}