#pragma once

#include "Core/CoreTypes.h"

#include <memory.h>

class TITAN_API BasePlatformMemory
{
public:
    FORCEINLINE static void* Allocate(const TSize Size, const TSize Alignment) = delete;
    FORCEINLINE static void  Free(void* Pointer) = delete;

public:
    FORCEINLINE static void* Copy(const void* From, void* To, const TSize Size)
    {
        ASSERT(Size > 0, "The size must be greater than 0!");
        return memcpy(To, From, Size);
    }

    FORCEINLINE static void* Move(const void* From, void* To, const TSize Size)
    {
        ASSERT(Size > 0, "The size must be greater than 0!");
        return memmove(To, From, Size);
    }
};