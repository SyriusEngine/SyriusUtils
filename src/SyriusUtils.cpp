#include "../include/SyriusUtils/SyriusUtils.hpp"
#include "../include/SyriusUtils/Random.hpp"

namespace Syrius{

    UID generateID(){
        return Random::getRandom<UID>(1, std::numeric_limits<UID>::max());
    }

    void checkFile(const fs::path& file){
        if (!fs::exists(file)){
            throw std::runtime_error("File does not exist: " + file.string());
        }
        if (!fs::is_regular_file(file)){
            throw std::runtime_error("Resource is not a file: " + file.string());
        }
    }

    void checkDirectory(const fs::path& directory){
        if (!fs::exists(directory)){
            throw std::runtime_error("Directory does not exist: " + directory.string());
        }
        if (!fs::is_directory(directory)){
            throw std::runtime_error("Resource is not a directory: " + directory.string());
        }
    }
}