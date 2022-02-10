#pragma once

#include "CoreTypes.h"
#include "Memory/Allocator.h"

template<typename T, typename AllocatorType>
class TITAN_API TArray
{
public:
	TArray();
	TArray(const TSize Size);
	TArray(const TArray<T>& Other)
	{

	}

private:
	AllocatorType m_Allocator;
};