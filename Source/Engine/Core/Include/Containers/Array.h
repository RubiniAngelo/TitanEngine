#pragma once

#include "CoreTypes.h"
#include "HeapAllocator.h"

template<typename T, typename AllocatorType = THeapAllocator<T>>
class TITAN_API TArray
{
	using SizeType = typename AllocatorType::SizeType;

public:
	TArray();

	TArray(const SizeType capacity);

	TArray(const T* data, const SizeType count);

	TArray(const TArray& other);

	~TArray();

public:
	void Add(const T& item);

	void AddRange(const T* items, const SizeType count);

	void Remove(const SizeType Index);

	void RemoveRange(const SizeType start, const SizeType end);

	void Reserve(const SizeType count);

public:
	T& ElementAt(const SizeType index);

	const T& ElementAt(const SizeType index) const;

	SizeType GetCapacity() const;

	SizeType GetCount() const;

public:
	bool operator==(const TArray<T, AllocatorType>& other);

	bool operator!=(const TArray<T, AllocatorType>& other);

	TArray<T, AllocatorType>& operator=(TArray<T, AllocatorType>& other);

	const T& operator[](SizeType index) const;

	T& operator[](SizeType index);

private:
	void EnsureLength(const SizeType count);

private:
	AllocatorType m_Allocator;

	SizeType m_Capacity;
	SizeType m_Count;
};

#include "Array.inl"