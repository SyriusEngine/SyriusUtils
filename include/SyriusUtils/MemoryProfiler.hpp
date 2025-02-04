#pragma once

#include "ExportUtils.hpp"
#include "Types/Types.hpp"

#include <cstdlib> // malloc, free

namespace Syrius {

    class SR_UTILS_API MemoryProfiler {
    public:

        static void allocate(Size size);

        static void free(Size size);

        static Size getAllocatedMemory();

        static Size getDeallocatedMemory();

        static Size getCurrentUsage();

    private:
        static Size m_AllocatedMemory;
        static Size m_FreedMemory;
    };

}

#if defined(SR_DEBUG)

inline void* operator new(std::size_t size){
    Syrius::MemoryProfiler::allocate(size);
    return malloc(size);
}

inline void operator delete(void* memory, size_t size) noexcept {
    if (memory != nullptr) {
        Syrius::MemoryProfiler::free(size);
        free(memory);
    }
}

inline void* operator new[](size_t size) {
    Syrius::MemoryProfiler::allocate(size);
    return malloc(size);
}

inline void operator delete[](void* memory, size_t size) noexcept {
    if (memory != nullptr) {
        Syrius::MemoryProfiler::free(size);
        free(memory);
    }
}


#endif