#pragma once

#include "CoreTypes.h"

// TODO: Implement ConstructItemInRange and DestructItemInRange (ASAP)

namespace MemoryUtils
{
	template<typename T, typename... ArgsType>
	FORCEINLINE typename TEnableIf<TIsTriviallyConstructible<T>::Value>::Type ConstructItem(T* item, ArgsType... args)
	{
		// Nothing to do
	}

	template<typename T, typename... ArgsType>
	FORCEINLINE typename TEnableIf<!TIsTriviallyConstructible<T>::Value>::Type ConstructItem(T* item, ArgsType... args)
	{
		item = new T(args...);
	}

	template<typename T>
	FORCEINLINE typename TEnableIf<TIsTriviallyDestructible<T>::Value>::Type DestructItem(T* item)
	{
		// Nothing to do
	}

	template<typename T>
	FORCEINLINE typename TEnableIf<!TIsTriviallyDestructible<T>::Value>::Type DestructItem(T* item)
	{
		item->~T();
	}
}