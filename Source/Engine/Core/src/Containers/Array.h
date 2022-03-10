#pragma once

#include "CoreTypes.h"
#include "HeapAllocator.h"

template<typename T, typename AllocatorType = THeapAllocator<T>>
class TITAN_API TArray
{
	using SizeType = typename AllocatorType::SizeType;

public:
	TArray() : m_Capacity(0), m_Count(0) { }

	TArray(const SizeType capacity)
	{
		if (capacity > 0)
		{
			m_Allocator.Allocate(capacity);
		}
	}

	TArray(const T* data, const SizeType count)
	{
		Assert(data != nullptr);

		if (count > 0)
		{
			EnsureLength(count);
			MemoryUtils::ConstructItems(data, m_Allocator.GetData(), count);
		}
	}

	TArray(const TArray& other)
	{
		if (other.m_Capacity > 0)
		{
			m_Allocator.Allocate(other.m_Capacity);
			MemoryUtils::ConstructItems(other.m_Allocator.GetData(), m_Allocator.GetData(), other.m_Count);
		}
	}

	~TArray()
	{
		if (m_Allocator.IsAllocated())
		{
			MemoryUtils::DestructItems(m_Allocator.GetData(), m_Count);
		}
	}

public:

	/**
	 * Add a new element to the array.
	 * 
	 * @param item - Item to add
	 */
	void Add(const T item)
	{
		EnsureLength(1);
		MemoryUtils::ConstructItem(&item, m_Allocator.GetData() + m_Count);
		m_Count++;
	}

	/**
	 * Add a new elements to the array.
	 * 
	 * @param items - Items to add
	 * @param count - Count of items to add
	 */
	void AddRange(const T* items, const SizeType count)
	{
		Assert(items != nullptr);

		if (count > 0)
		{
			EnsureLength(count);
			MemoryUtils::ConstructItems(items, m_Allocator.GetData() + m_Count, count);
			m_Count += count;
		}
	}

	/**
	 * Remove an element from the array based on a given index.
	 * 
	 * @param index - Index of the item to remove (start from 0)
	 */
	void Remove(const SizeType index)
	{
		AssertMsg(index >= 0 && index < m_Count, "The index exceeds the size of the array!");

		const T* data = m_Allocator.GetData();
		MemoryUtils::DestructItem(data + index);
		MemoryUtils::CopyItems(data + index + 1, data + index, (m_Count - 1) - index);

		m_Count--;
	}


	void RemoveRange(const SizeType start, const SizeType end)
	{
		Assert(start >= 0 && end >= 0 && start < end&& end < m_Count);

		const T* data = m_Allocator.GetData();
		const SizeType count = end - start;

		MemoryUtils::DestructItems(data + start, count);
		MemoryUtils::CopyItems(data + end, data + start, count);

		m_Count -= count;
	}

	void Reserve(const SizeType count)
	{
		Assert(count >= 0);

		EnsureLength(count);
	}

	void Clear()
	{
		m_Count = 0;
	}

public:
	FORCEINLINE const T& ElementAt(const SizeType index) const
	{
		Assert(index >= 0 && index < m_Count);

		return *(m_Allocator.GetData() + index);
	}

	FORCEINLINE T& ElementAt(const SizeType index)
	{
		Assert(index >= 0 && index < m_Count);

		return *(m_Allocator.GetData() + index);
	}

	FORCEINLINE SizeType GetCapacity() const
	{
		return m_Capacity;
	}

	FORCEINLINE SizeType GetCount() const
	{
		return m_Count;
	}

	FORCEINLINE const T* ToArray() const
	{
		return m_Allocator.GetData();
	}

	FORCEINLINE T* ToArray()
	{
		return m_Allocator.GetData();
	}

public:
	bool operator==(const TArray<T, AllocatorType>& other)
	{
		AssertMsg(false, "Not implemented yet!");
		return false;
	}

	bool operator!=(const TArray<T, AllocatorType>& other)
	{
		return !(*this == other);
	}

	TArray<T, AllocatorType>& operator=(TArray<T, AllocatorType>& other)
	{
		// Check if it's another array
		if (this != &other)
		{
			if (m_Count > 0)
			{
				MemoryUtils::DestructItems(m_Allocator.GetData(), m_Count);
				m_Allocator.Free();
			}

			m_Capacity = other.m_Capacity;
			m_Count = other.m_Count;

			m_Allocator.Allocate(m_Capacity);
			MemoryUtils::CopyItems(other.m_Allocator.GetData(), m_Allocator.GetData(), m_Count);

		}

		return *this;
	}

	const T& operator[](SizeType index) const
	{
		return ElementAt(index);
	}

	T& operator[](SizeType index)
	{
		return ElementAt(index);
	}

private:
	void EnsureLength(const SizeType count)
	{
		if (m_Count + count >= m_Capacity)
		{
			const SizeType newCapacity = Math::Max(m_Capacity * 4, Math::RoundToPowerOf2(m_Count + count));

			m_Allocator.Resize(m_Capacity, newCapacity);
			m_Capacity = newCapacity;
		}
	}

private:
	AllocatorType m_Allocator;

	SizeType m_Capacity;
	SizeType m_Count;
};