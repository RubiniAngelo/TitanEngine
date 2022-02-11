#pragma once

#include "Platform/Base/BasePlatformMemory.h"
#include "Math/Math.h"

#include <malloc.h>

class TITAN_API WindowsMemory final : public BasePlatformMemory
{
public:
    /** Allocates memory on a specified alignment boundary */
    FORCEINLINE static void* Allocate(const TSize size, const uint8 alignment)
    {
        ASSERT(size > 0, "The size must be greater than 0!");
        ASSERT(Math::IsPowerOf2(alignment), "The alignment must be a power of two!");
        return _aligned_malloc(size, alignment);
    }

    /** Frees a block of memory that was allocated */
    FORCEINLINE static void Free(void* ptr)
    {
        ASSERT(ptr != nullptr, "The pointer is nullptr!");
        return _aligned_free(ptr);
    }
};

typedef WindowsMemory Memory;