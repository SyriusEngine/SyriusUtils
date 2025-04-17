#include <SyriusUtils/MemoryProfiler.hpp>

namespace Syrius {

    Size MemoryProfiler::m_AllocatedMemory = 0;
    Size MemoryProfiler::m_FreedMemory = 0;

    void MemoryProfiler::allocate(Size size) {
        m_AllocatedMemory += size;
    }

    void MemoryProfiler::free(Size size) {
        m_FreedMemory += size;
    }

    Size MemoryProfiler::getAllocatedMemory() {
        return m_AllocatedMemory;
    }

    Size MemoryProfiler::getDeallocatedMemory() {
        return m_FreedMemory;
    }

    Size MemoryProfiler::getCurrentUsage() {
        return m_AllocatedMemory - m_FreedMemory;
    }

}