#pragma once

#include "CoreTypes.h"
#include "MemoryUtils.h"
#include "Platform/Memory.h"

// TODO: Implements debug info

/** Default allocator */
template<typename T>
class THeapAllocator
{
public:
    FORCEINLINE T* Allocate(const TSize count, const uint8 alignment = DEFAULT_ALIGNMENT)
    {
        return (T*)Memory::Allocate(count * sizeof(T), alignment);
    }

    FORCEINLINE void Free(T* ptr)
    {
        Memory::Free(ptr);
    }
};