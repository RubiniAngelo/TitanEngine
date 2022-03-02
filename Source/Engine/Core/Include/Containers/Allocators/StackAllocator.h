#pragma once

#include "CoreTypes.h"
#include "Memory/Memory.h"

/** Fixed-size allocator */
template<typename T, int32 StackSize = 2048>
class TStackAllocator
{
public:
    FORCEINLINE T* Allocate(const Size count, const uint8 alignment = DEFAULT_ALIGNMENT)
    {
        ASSERT(false, "Not Implemented yet");
        // TODO: Implement
    }

    template<typename... ArgsType>
    FORCEINLINE void Construct(T* ptr, ArgsType... args)
    {
        ASSERT(false, "Not Implemented yet");
        // TODO: Implement
    }

    FORCEINLINE void Destruct(T* ptr)
    {
        ASSERT(false, "Not Implemented yet");
        // TODO: Implement
    }

    FORCEINLINE void Free(T* ptr)
    {
        ASSERT(false, "Not Implemented yet");
        // TODO: Implement
    }
};