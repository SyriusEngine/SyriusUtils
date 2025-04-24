#pragma once

#include <SyriusUtils/ExportUtils.hpp>
#include <SyriusUtils/MemoryProfiler.hpp>
#include <SyriusUtils/PlatformDetection.hpp>
#include <SyriusUtils/ResourceView.hpp>
#include <SyriusUtils/Math.hpp>

#include <SyriusUtils/Types/Types.hpp>
#include <SyriusUtils/Types/SymbolicTypes.hpp>

#include <SyriusUtils/Logger/LoggerDefs.hpp>
#include <SyriusUtils/Logger/Logger.hpp>
#include <SyriusUtils/Logger/LoggerMacros.hpp>
#include <SyriusUtils/Logger/Conditions.hpp>

#include <SyriusUtils/Clock/Clock.hpp>

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