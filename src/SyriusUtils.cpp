#include "../include/SyriusUtils/SyriusUtils.hpp"
#include "../include/SyriusUtils/Random.hpp"

namespace Syrius{

    UID generateID(){
        return Random::getRandom<UID>(1, std::numeric_limits<UID>::max());
    }
}