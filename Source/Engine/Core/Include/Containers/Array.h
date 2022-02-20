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

	TArray(const int32 capacity) : m_Capacity(capacity), m_Count(0)
	{
		Assert(capacity >= 0);

		if (capacity > 0)
		{
			m_Data = m_Allocator.Allocate(other.m_Capacity);
		}
	}

	TArray(const T* data, const int32 count) : m_Capacity(0), m_Count(count)
	{
		Assert(count >= 0);

		m_Data = nullptr;

		if (count > 0)
		{
			EnsureLength(count);
			MemoryUtils::ConstructItems(data, m_Data, count);
		}
	}

	TArray(const TArray& other) : m_Capacity(other.m_Capacity), m_Count(other.m_Count)
	{
		if (other.m_Capacity > 0)
		{
			m_Data = m_Allocator.Allocate(other.m_Capacity);
			MemoryUtils::ConstructItems(other.m_Data, m_Data, other.m_Count);
		}
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
		Assert(count >= 0 && items != nullptr);

		EnsureLength(count);
		MemoryUtils::ConstructItems(items, m_Data + m_Count, count);
		m_Count += count;
	}

	FORCEINLINE void Remove(const int32 index)
	{
		Assert(index >= 0 && index < m_Count);

		MemoryUtils::DestructItem(m_Data + index);
		Memory::Copy(m_Data + index + 1, m_Data + index, (m_Count - 1) - index);

		m_Count--;
	}

	FORCEINLINE void RemoveRange(const int32 start, const int32 end)
	{
		Assert(start >= 0 && end >= 0 && start < end && end < m_Count);

		const int32 count = end - start;

		MemoryUtils::DestructItems(m_Data + start, count);
		MemoryUtils::CopyItems(m_Data + end, m_Data + start, count);

		m_Count -= count;
	}

	FORCEINLINE void Reserve(const int32 count)
	{
		Assert(count >= 0);
		EnsureLength(count);
	}

	FORCEINLINE T Get(const int32 index) const
	{ 
		Assert(index >= 0 && index < m_Count);
		return m_Data[index]; 
	}

	FORCEINLINE int32 GetCapacity() const 
	{ 
		return m_Capacity; 
	}

	FORCEINLINE int32 GetCount() const 
	{ 
		return m_Count;
	}

public:
	// TODO: Implements operators 

private:
	FORCEINLINE void EnsureLength(const int32 count)
	{
		if (m_Count + count >= m_Capacity)
		{
			const int32 totalCount = Math::Max(m_Capacity * 4, Math::RoundToPowerOf2(m_Count + count));
			T* newArray = m_Allocator.Allocate(totalCount);

			if (m_Data)
			{
				MemoryUtils::CopyItems(m_Data, newArray, totalCount);
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