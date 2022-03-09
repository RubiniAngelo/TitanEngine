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
    THeapAllocator();

    ~THeapAllocator();

    void Allocate(const SizeType elements);

    void Free();

    void Resize(const SizeType oldElementsCount, const SizeType newElementsCount);

public:
    bool IsAllocated() const;

    const T* GetData() const;

    T* GetData();

private:
    T* m_Data;
};

#include "HeapAllocator.inl"