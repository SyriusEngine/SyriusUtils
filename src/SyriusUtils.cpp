#include "../include/SyriusUtils/SyriusUtils.hpp"
#include "../include/SyriusUtils/Random.hpp"
#include "../include/SyriusUtils/Logger/LoggerMacros.hpp"

namespace Syrius{

    UID generateID(){
        return Random::getRandom<UID>(1, std::numeric_limits<UID>::max());
    }

    void checkFile(const fs::path& file){
        if (!fs::exists(file)){
            SR_LOG_THROW("checkFile", "File %s does not exist", file.string().c_str());
        }
        if (!fs::is_regular_file(file)){
            SR_LOG_THROW("checkFile", "Resource %s is not a file", file.string().c_str());
        }
    }

    void checkDirectory(const fs::path& directory){
        if (!fs::exists(directory)){
            SR_LOG_THROW("checkDirectory", "Directory %s does not exist", directory.string().c_str());
        }
        if (!fs::is_directory(directory)){
            SR_LOG_THROW("checkDirectory", "Resource %s is not a directory", directory.string().c_str());
        }
    }
}