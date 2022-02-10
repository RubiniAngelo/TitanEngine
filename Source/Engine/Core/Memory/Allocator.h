#pragma once

#include "Core/CoreTypes.h"
#include "Core/Platform/Memory.h"
#include "Core/Containers/Array.h"

/** Default allocator */
template<typename T>
class Allocator
{
public:
    FORCEINLINE T* Allocate(const TSize Size, const uint8 Alignment = DEFAULT_ALIGNMENT)
    {
        return (T*)Memory::Allocate(Size, Alignment);
    }

    FORCEINLINE void Free(T* Pointer)
    {
        Memory::Free(Pointer);
    }
};