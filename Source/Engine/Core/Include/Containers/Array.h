#pragma once

#include "CoreTypes.h"
#include "Memory/Allocator.h"

template<typename T, typename AllocatorType = TAllocator<T>>
class TITAN_API TArray
{
public:

private:
	AllocatorType m_Allocator;
};