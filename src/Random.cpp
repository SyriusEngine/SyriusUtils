#include <SyriusUtils/Random.hpp>

namespace Syrius {

    u64 Random::m_Seed = std::random_device()();
    std::mt19937_64 Random::m_Engine = std::mt19937_64(m_Seed);

    u64 Random::getSeed() {
        return m_Seed;
    }

    void Random::setSeed(const u64 seed) {
        m_Seed = seed;
        m_Engine.seed(m_Seed);
    }
}