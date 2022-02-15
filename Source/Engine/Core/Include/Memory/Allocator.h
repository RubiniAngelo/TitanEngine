#pragma once

#include "CoreTypes.h"
#include "MemoryUtils.h"
#include "Platform/Memory.h"

// TODO: Implements debug info

/** Default allocator */
template<typename T>
class TAllocator
{
public:
    FORCEINLINE T* Allocate(const TSize count, const uint8 alignment = DEFAULT_ALIGNMENT)
    {
        return (T*)Memory::Allocate(count * sizeof(T), alignment);
    }

    template<typename... ArgsType>
    FORCEINLINE void Construct(T* ptr, ArgsType... args)
    {
        MemoryUtils::ConstructItem(ptr, args...);
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