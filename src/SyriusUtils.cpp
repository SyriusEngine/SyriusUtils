#include <SyriusUtils/SyriusUtils.hpp>
#include <SyriusUtils/Random.hpp>
#include <SyriusUtils/Logger/LoggerMacros.hpp>

namespace Syrius{

    UID generateID(){
        static UID id = 1;
        return id++;
    }

    void checkFile(const fs::path& file){
        if (!fs::exists(file)){
            SR_LOG_THROW("checkFile", "File {} does not exist", file.string());
        }
        if (!fs::is_regular_file(file)){
            SR_LOG_THROW("checkFile", "Resource {} is not a file", file.string());
        }
    }

    void checkDirectory(const fs::path& directory){
        if (!fs::exists(directory)){
            SR_LOG_THROW("checkDirectory", "Directory {} does not exist", directory.string());
        }
        if (!fs::is_directory(directory)){
            SR_LOG_THROW("checkDirectory", "Resource {} is not a directory", directory.string());
        }
    }
}