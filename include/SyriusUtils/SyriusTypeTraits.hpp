#pragma once

#include <type_traits>

namespace Syrius {

    template<typename T>
    struct always_false : std::false_type {};
}

#define SR_STATIC_ASSERT_TYPE(type) static_assert(Syrius::always_false<type>::value, SR_FUNC "not supported for type")