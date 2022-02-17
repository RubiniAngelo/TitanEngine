#pragma once

#include "CoreTypes.h"
#include "Allocators/Allocators.h"

template<typename T, typename AllocatorType = THeapAllocator<T>>
class TITAN_API TArray
{
public:
	FORCEINLINE void Add(const T& item)
	{

	}

	FORCEINLINE void AddRange(const T* items, const int32 count)
	{

	}

	FORCEINLINE void Remove(const int32 index)
	{

	}

	FORCEINLINE void RemoveRange(const int32 start, const int32 count)
	{

	}

	FORCEINLINE void Reserve(const int32 count)
	{

	}

public:
	FORCEINLINE const T Get(const int32 index) const 
	{ 
		ASSERT(index < 0, "The index must be greater than 0!");
		ASSERT(index > m_Count, "The index is greater than the array count!");
		return m_Data[index]; 
	}

	FORCEINLINE const int32 GetCapacity() const NOEXCEPT { return m_Capacity; }
	FORCEINLINE const int32 GetCount() const NOEXCEPT { return m_Count; }

private:
	AllocatorType m_Allocator;

	T* 		m_Data;
	int32 	m_Capacity;
	int32 	m_Count;
};