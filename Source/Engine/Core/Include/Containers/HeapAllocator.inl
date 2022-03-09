template<typename T, uint8 Alignment>
THeapAllocator<T, Alignment>::THeapAllocator()
{
    m_Data = nullptr;
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, uint8 Alignment>
THeapAllocator<T, Alignment>::~THeapAllocator()
{
    if (IsAllocated())
    {
        Free();
    }
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, uint8 Alignment>
FORCEINLINE void THeapAllocator<T, Alignment>::Allocate(const SizeType elements)
{
    if (IsAllocated())
    {
        Free();
    }

    m_Data = (T*)Memory::Allocate(elements * sizeof(T), Alignment);
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, uint8 Alignment>
FORCEINLINE void THeapAllocator<T, Alignment>::Free()
{
    Memory::Free(m_Data);
    m_Data = nullptr;
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, uint8 Alignment>
FORCEINLINE void THeapAllocator<T, Alignment>::Resize(const SizeType oldElementsCount, const SizeType newElementsCount)
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

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, uint8 Alignment>
FORCEINLINE bool THeapAllocator<T, Alignment>::IsAllocated() const
{
    return m_Data != nullptr;
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, uint8 Alignment>
FORCEINLINE const T* THeapAllocator<T, Alignment>::GetData() const
{
    return m_Data;
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, uint8 Alignment>
FORCEINLINE T* THeapAllocator<T, Alignment>::GetData()
{
    return m_Data;
}