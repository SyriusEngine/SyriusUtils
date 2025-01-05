#pragma once

#include <cstdint>
#include <cstddef>
#include <memory>

typedef uint8_t u8;
typedef int8_t i8;
typedef uint16_t u16;
typedef int16_t i16;
typedef uint32_t u32;
typedef int32_t i32;
typedef uint64_t u64;
typedef int64_t i64;

typedef size_t Size;
typedef size_t Index;
typedef u64 Time;

namespace Syrius{

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