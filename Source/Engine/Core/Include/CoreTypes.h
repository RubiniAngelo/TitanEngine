#pragma once

#include "Platform/Defines.h"
#include "TypeTraits/TypeTraits.h"
#include "Misc/BasicTypes.h"

#if TITAN_EXPORT
#   define TITAN_API DLLEXPORT
#else
#   define TITAN_API
#endif

#undef ASSERT

// TODO Rework this

#if !defined(TITAN_RELEASE_BUILD)
#   define TITAN_RELEASE_BUILD 0
#endif

#define TITAN_DEBUG_BUILD !TITAN_RELEASE_BUILD

#define DEFAULT_ALIGNMENT 16

// TODO: Log ERROR
#if TITAN_DEBUG_BUILD
#   define ASSERT(Condition, Message) \
        if(!(Condition)) \
        { \
            PLATFORM_DEBUG_BREAK; \
        }

#   define ASSERT(Condition) \
        if (!(Condition)) \
        { \
            PLATFORM_DEBUG_BREAK; \
        }

#else
#   define ASSERT(Condition, Message)
#   define ASSERT(Condition)
#endif