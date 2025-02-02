#pragma once

#include "PlatformDetection.hpp"
#include "ExportUtils.hpp"
#include "Conditions.hpp"
#include "ResourceView.hpp"

#include "Types/Types.hpp"
#include "Types/SymbolicTypes.hpp"

#include "Logger/LoggerDefs.hpp"
#include "Logger/Logger.hpp"
#include "Logger/LoggerMacros.hpp"

#include "Clock/Clock.hpp"

#include <filesystem>

namespace Syrius{

    namespace fs = std::filesystem;

    /**
     * @brief Generates a random UID excluding 0.
     * @return random UID.
     */
    SR_UTILS_API UID generateID();

    /**
     * @brief Checks if a file exists or that the resource is indeed a file (not a directory).
     * @param file The file to check.
     * @throws std::runtime_error if the file does not exist or is not a file.
     */
    SR_UTILS_API void checkFile(const fs::path& file);

    /**
     * @brief Checks if a directory exists or that the resource is indeed a directory (not a file).
     * @param directory
     */
    SR_UTILS_API void checkDirectory(const fs::path& directory);

}