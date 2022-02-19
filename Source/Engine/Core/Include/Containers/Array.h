#pragma once

#include "CoreTypes.h"
#include "Allocators/Allocators.h"

template<typename T, typename AllocatorType = THeapAllocator<T>>
class TITAN_API TArray
{
public:
	TArray() : m_Capacity(0), m_Count(0)
	{
		m_Data = nullptr;
	}

	~TArray()
	{
		if (m_Data)
		{
			MemoryUtils::DestructItems(m_Data, m_Count);
			m_Allocator.Free(m_Data);
			m_Data = nullptr;
		}
	}

public:
	FORCEINLINE void Add(const T& item)
	{
		EnsureLength(1);
		MemoryUtils::ConstructItems(&item, m_Data + m_Count, 1);
		m_Count++;
	}

	FORCEINLINE void AddRange(const T* items, const int32 count)
	{
		ASSERT(count >= 0 && items != nullptr);

		EnsureLength(count);
		MemoryUtils::ConstructItems(items, m_Data + m_Count, count);
		m_Count += count;
	}

	FORCEINLINE void Remove(const int32 index)
	{
		ASSERT(index >= 0 && index < m_Count);

		// TODO: Implement this
	}

	FORCEINLINE void RemoveRange(const int32 start, const int32 end)
	{
		ASSERT((start >= 0  && start < end) && (end >= 0 && end < m_Count));

		// TODO: Implement this
	}

	FORCEINLINE void Reserve(const int32 count)
	{
		EnsureLength(count);
	}

	FORCEINLINE T Get(const int32 index) const
	{ 
		ASSERT(index >= 0 && index < m_Count);
		return m_Data[index]; 
	}

	FORCEINLINE const int32 GetCapacity() const 
	{ 
		return m_Capacity; 
	}

	FORCEINLINE const int32 GetCount() const 
	{ 
		return m_Count;
	}

private:

	FORCEINLINE void EnsureLength(const int32 count, bool shouldConstruct = true)
	{
		if (m_Count + count >= m_Capacity)
		{
			const int32 totalCount = Math::Max(m_Capacity * 4, Math::RoundToPowerOf2(m_Count + count));
			T* newArray = m_Allocator.Allocate(totalCount);

			if (m_Data)
			{
				MemoryUtils::MoveItems(m_Data, newArray, totalCount);
				m_Allocator.Free(m_Data);
			}

			m_Data = newArray;
			m_Capacity = totalCount;
		}
	}


private:
	AllocatorType m_Allocator;

	T* 		m_Data;
	int32	m_Capacity;
	int32 	m_Count;
};