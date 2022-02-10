#pragma once

#include "CoreTypes.h"

#include <memory.h>

class TITAN_API BasePlatformMemory
{
public:
    FORCEINLINE static void* Allocate(const TSize Size, const uint8 Alignment) = delete;
    FORCEINLINE static void  Free(void* Pointer) = delete;

public:
    FORCEINLINE static void* Copy(const void* InSource, void* OutTarget, const TSize Size)
    {
        ASSERT(Size > 0, "The size must be greater than 0!");
        return memcpy(OutTarget, Source, Size);
    }
};
