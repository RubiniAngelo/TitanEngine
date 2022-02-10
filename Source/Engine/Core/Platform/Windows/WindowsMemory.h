#pragma once

#include "Platform/Base/BasePlatformMemory.h"
#include "Math/Math.h"

#include <malloc.h>

class TITAN_API WindowsMemory final : public BasePlatformMemory
{
public:
    /** Allocates memory on a specified alignment boundary */
    FORCEINLINE static void* Allocate(const TSize Size, const uint8 Alignment)
    {
        ASSERT(Math::IsPowerOf2(Alignment), "The alignment must be a power of two!");
        return _aligned_malloc(Size, Alignment);
    }

    /** Frees a block of memory that was allocated */
    FORCEINLINE static void Free(void* Pointer)
    {
        ASSERT(Pointer != nullptr, "The pointer is nullptr!");
        return _aligned_free(Pointer);
    }
};

typedef WindowsMemory Memory;