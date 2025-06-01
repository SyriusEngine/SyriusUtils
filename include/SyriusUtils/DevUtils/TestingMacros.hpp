#pragma once

#if defined(SR_TESTING)

#define SR_GET_PRIVATE_MEMBER(CLASS, MEMBER) \
    public: \
    inline const decltype(CLASS::MEMBER)& get_##MEMBER() const { return MEMBER; }

#endif