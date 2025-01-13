#pragma once

#include <random>

#include "Types/Types.hpp"


namespace Syrius {

    class Random {
    public:
        static void setSeed(u64);

        static u64 getSeed();

        template<typename T>
        static T getRandom(const T min = std::numeric_limits<T>::min(), const T max = std::numeric_limits<T>::max()) {
            static_assert(std::is_floating_point_v<T> or std::is_integral_v<T>, "Unsupported type for random number generation.");
            if constexpr (std::is_floating_point_v<T>) {
                std::uniform_real_distribution<T> dis(min, max);
                return dis(m_Engine);
            } else if constexpr (std::is_integral_v<T>) {
                std::uniform_int_distribution<T> dis(min, max);
                return dis(m_Engine);
            }
        }

    private:
        static u64 m_Seed;
        static std::mt19937_64 m_Engine;
    };

}