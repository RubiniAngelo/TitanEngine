#pragma once

#include "CoreTypes.h"
#include "MemoryUtils.h"
#include "Platform/Memory.h"
#include "Containers/Array.h"

/** Default allocator */
template<typename T>
class Allocator
{
public:
    FORCEINLINE T* Allocate(const TSize count, const uint8 alignment = DEFAULT_ALIGNMENT)
    {
        return (T*)Memory::Allocate(count * sizeof(T), alignment);
    }

    FORCEINLINE void Construct(T* ptr)
    {

    }

    FORCEINLINE void Destruct(T* ptr)
    {
        MemoryUtils::DestructItem(ptr);
    }

    FORCEINLINE void Free(T* ptr)
    {
        Memory::Free(ptr);
    }
};