#pragma once

#include <random>

#include <SyriusUtils/Types/Types.hpp>
#include <SyriusUtils/ExportUtils.hpp>

namespace Syrius {

    class SR_UTILS_API Random {
    public:
        /**
         * @brief Set the seed for the random number generator.
         * @param seed Seed to set
         */
        static void setSeed(u64);

        /**
         * @brief Get the seed for the random number generator.
         * @return Seed
         */
        static u64 getSeed();

        /**
         * @brief Get a random number between min and max.
         * @tparam T Datatype of the random number (int, float, UID, ...).
         * @param min Lower bound of the random number.
         * @param max Upper bound of the random number.
         * @return The generated random number.
         */
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