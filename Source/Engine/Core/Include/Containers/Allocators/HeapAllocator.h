#pragma once

#include "CoreTypes.h"
#include "Memory/Memory.h"

// TODO: Implements debug info

/** Default allocator */
template<typename T, uint8 Alignment = DEFAULT_ALIGNMENT>
class THeapAllocator
{
public:
    /** 
     * Integer type used to work with containers, such as indexes and counts.
     * Must be signed.
     */
    using SizeType = int32;

public:
    THeapAllocator()
    {
        m_Data = nullptr;
    }

    ~THeapAllocator()
    {
        if (IsAllocated())
        {
            Free();
        }
    }

    FORCEINLINE void Allocate(const SizeType elements)
    {
        if (IsAllocated())
        {
            Free();
        }

        m_Data = (T*)Memory::Allocate(elements * sizeof(T), Alignment);
    }

    FORCEINLINE void Free()
    {
        Memory::Free(m_Data);
        m_Data = nullptr;
    }

    FORCEINLINE void Resize(const SizeType oldElementsCount, const SizeType newElementsCount)
    {
        if (newElementsCount > 0)
        {
            T* data = (T*)Memory::Allocate(newElementsCount * sizeof(T), Alignment);

            if (oldElementsCount > 0)
            {
                MemoryUtils::CopyItems(m_Data, data, oldElementsCount);
                Memory::Free(m_Data);
            }

            m_Data = data;
        }
    }

public:
    FORCEINLINE bool IsAllocated() const
    {
        return m_Data != nullptr;
    }

    FORCEINLINE const T* GetData() const
    {
        return m_Data;
    }

    FORCEINLINE T* GetData()
    {
        return m_Data;
    }

private:
    T* m_Data;
};