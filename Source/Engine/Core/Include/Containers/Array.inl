template<typename T, typename AllocatorType>
TArray<T, AllocatorType>::TArray() : m_Capacity(0), m_Count(0)
{

}

template<typename T, typename AllocatorType>
TArray<T, AllocatorType>::TArray(const SizeType capacity) : m_Capacity(capacity), m_Count(0)
{
	if (capacity > 0)
	{
		m_Allocator.Allocate(capacity);
	}
}

template<typename T, typename AllocatorType>
TArray<T, AllocatorType>::TArray(const T* data, const SizeType count) : m_Capacity(0), m_Count(count)
{
	Assert(data != nullptr);

	if (count > 0)
	{
		EnsureLength(count);
		MemoryUtils::ConstructItems(data, m_Allocator.GetData(), count);
	}
}

template<typename T, typename AllocatorType>
TArray<T, AllocatorType>::TArray(const TArray& other) : m_Capacity(other.m_Capacity), m_Count(other.m_Count)
{
	if (other.m_Capacity > 0)
	{
		m_Allocator.Allocate(other.m_Capacity);
		MemoryUtils::ConstructItems(other.m_Allocator.GetData(), m_Allocator.GetData(), other.m_Count);
	}
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, typename AllocatorType>
TArray<T, AllocatorType>::~TArray()
{
	if (m_Allocator.IsAllocated())
	{
		MemoryUtils::DestructItems(m_Allocator.GetData(), m_Count);
	}
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, typename AllocatorType>
FORCEINLINE void TArray<T, AllocatorType>::Add(const T& item)
{
	EnsureLength(1);
	MemoryUtils::ConstructItem(&item, m_Allocator.GetData() + m_Count);
	m_Count++;
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, typename AllocatorType>
FORCEINLINE void TArray<T, AllocatorType>::AddRange(const T* items, const SizeType count)
{
	Assert(items != nullptr);

	if (count > 0)
	{
		EnsureLength(count);
		MemoryUtils::ConstructItems(items, m_Allocator.GetData() + m_Count, count);
		m_Count += count;
	}
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, typename AllocatorType>
FORCEINLINE void TArray<T, AllocatorType>::Remove(const SizeType index)
{
	AssertMsg(index >= 0 && index < m_Count, "The index exceeds the size of the array!");

	const T* data = m_Allocator.GetData();
	MemoryUtils::DestructItem(data + index);
	MemoryUtils::CopyItems(data + index + 1, data + index, (m_Count - 1) - index);

	m_Count--;
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, typename AllocatorType>
FORCEINLINE void TArray<T, AllocatorType>::RemoveRange(const SizeType start, const SizeType end)
{
	Assert(start >= 0 && end >= 0 && start < end && end < m_Count);

	const T* data = m_Allocator.GetData();
	const SizeType count = end - start;

	MemoryUtils::DestructItems(data + start, count);
	MemoryUtils::CopyItems(data + end, data + start, count);

	m_Count -= count;
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, typename AllocatorType>
FORCEINLINE void TArray<T, AllocatorType>::Reserve(const SizeType count)
{
	Assert(count >= 0);

	EnsureLength(count);
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, typename AllocatorType>
FORCEINLINE T& TArray<T, AllocatorType>::ElementAt(const SizeType index)
{ 
	Assert(index >= 0 && index < m_Count);

	return *(m_Allocator.GetData() + index);
}

template<typename T, typename AllocatorType>
FORCEINLINE const T& TArray<T, AllocatorType>::ElementAt(const SizeType index) const
{
	Assert(index >= 0 && index < m_Count);

	return *(m_Allocator.GetData() + index);
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, typename AllocatorType>
FORCEINLINE typename TArray<T, AllocatorType>::SizeType TArray<T, AllocatorType>::GetCapacity() const 
{
	return m_Capacity; 
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, typename AllocatorType>
FORCEINLINE typename TArray<T, AllocatorType>::SizeType TArray<T, AllocatorType>::GetCount() const
{
	return m_Count;
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, typename AllocatorType>
bool TArray<T, AllocatorType>::operator==(const TArray<T, AllocatorType>& other)
{
	AssertMsg(false, "Not implemented yet!");
	return false;
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, typename AllocatorType>
bool TArray<T, AllocatorType>::operator!=(const TArray<T, AllocatorType>& other)
{
	return !(*this == other);
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, typename AllocatorType>
TArray<T, AllocatorType>& TArray<T, AllocatorType>::operator=(TArray<T, AllocatorType>& other)
{
	// Check if it's another array
	if (this != &other)
	{
		if (m_Count > 0)
		{
			MemoryUtils::DestructItems(m_Allocator.GetData(), m_Count);
			m_Allocator.Free();
		}

		m_Capacity	= other.m_Capacity;
		m_Count		= other.m_Count;

		m_Allocator.Allocate(m_Capacity);
		MemoryUtils::CopyItems(other.m_Allocator.GetData(), m_Allocator.GetData(), m_Count);

	}

	return *this;
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, typename AllocatorType>
const T& TArray<T, AllocatorType>::operator[](SizeType index) const
{
	return ElementAt(index);
}

template<typename T, typename AllocatorType>
T& TArray<T, AllocatorType>::operator[](SizeType index)
{
	return ElementAt(index);
}

// ---------------------------------------------------------------------------------------------------------------- //

template<typename T, typename AllocatorType>
FORCEINLINE void TArray<T, AllocatorType>::EnsureLength(const SizeType count)
{
	if (m_Count + count >= m_Capacity)
	{
		const SizeType newCapacity = Math::Max(m_Capacity * 4, Math::RoundToPowerOf2(m_Count + count));

		m_Allocator.Resize(m_Capacity, newCapacity);
		m_Capacity = newCapacity;
	}
}