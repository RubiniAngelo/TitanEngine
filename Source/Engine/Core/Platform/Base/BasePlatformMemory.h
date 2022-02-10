#pragma once

#include "Core/CoreTypes.h"

#include <memory.h>

class TITAN_API BasePlatformMemory
{
public:
    FORCEINLINE static void* Allocate(const TSize size, const TSize alignment) = delete;
    FORCEINLINE static void  Free(void* ptr) = delete;

public:
    FORCEINLINE static void* Copy(const void* source, void* target, const TSize size)
    {
        ASSERT(size > 0, "The size must be greater than 0!");
        return memcpy(target, source, size);
    }
};
