#pragma once

#include "CoreTypes.h"
#include "Memory/Allocator.h"

template<typename T, typename AllocatorType>
class TITAN_API TArray
{
public:
	TArray();
	TArray(const TSize size);
	TArray(const TArray<T, AllocatorType>& other)
	{

	}

private:
	AllocatorType m_Allocator;
};