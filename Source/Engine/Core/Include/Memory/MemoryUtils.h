#pragma once

#include "CoreTypes.h"

class TITAN_API MemoryUtils
{
public:
	template<typename T>
	FORCEINLINE static TEnableIf<TIsTriviallyConstructible<T>> Construct(T* ptr)
	{

	}


};