#pragma once

#include "CoreTypes.h"

class TITAN_API MemoryUtils
{
public:
	template<typename T>
	FORCEINLINE typename static TEnableIf<TIsTriviallyDestructible<T>::Value>::Type DestructItem(T* item)
	{
		/** Nothing */
	}

	template<typename T>
	FORCEINLINE typename static TEnableIf<!TIsTriviallyDestructible<T>::Value>::Type DestructItem(T* item)
	{
		item->~T();
	}
};