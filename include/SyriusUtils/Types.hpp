#pragma once

#include <cstdint>
#include <cstddef>
#include <memory>

using u8 = uint8_t;
using i8 = int8_t;
using u16 = uint16_t;
using i16 = int16_t;
using u32 = uint32_t;
using i32 = int32_t;
using u64 = uint64_t;
using i64 = int64_t;

using Size = std::size_t;
using Index = std::size_t;
using Time = std::size_t;

namespace Syrius{

    using UID = u64;

    template<typename T>
    using UP = std::unique_ptr<T>;

    template<typename T>
    using SP = std::shared_ptr<T>;

    template<typename T, typename... Args>
    inline UP<T> createUP(Args&&... args){
        return std::make_unique<T>(args...);
    }

    template<typename T, typename... Args>
    inline SP<T> createSP(Args&&... args){
        return std::make_shared<T>(args...);
    }

}