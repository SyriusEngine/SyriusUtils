#include "../include/SyriusUtils/SyriusUtils.hpp"
#include <random>

namespace Syrius{

    UID generateID(u64 seed){
        if (seed == 0){
            seed = std::random_device{}();
        }
        std::mt19937_64 mtEngine(seed);
        std::uniform_int_distribution<u64> dist(1, std::numeric_limits<u64>::max());
        return dist(mtEngine);
    }
}