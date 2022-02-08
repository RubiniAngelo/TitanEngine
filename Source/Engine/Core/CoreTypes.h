#pragma once

#include "Platform/Defines.h"
#include "Misc/BasicTypes.h"

#if TITAN_EXPORT
#   define TITAN_API DLLEXPORT
#else
#   define TITAN_API
#endif

#undef ASSERT

// TODO Rework this

#if !defined(TITAN_RELEASE)
#   define TITAN_RELEASE 0
#endif

#define TITAN_DEBUG !TITAN_RELEASE

// TODO: Log ERROR
#if TITAN_DEBUG
#   define ASSERT(Condition, Message) \
        if(!(Condition)) \
        { \
            PLATFORM_DEBUG_BREAK; \
        }
#else
#   define ASSERT(Condition, Message)
#endif