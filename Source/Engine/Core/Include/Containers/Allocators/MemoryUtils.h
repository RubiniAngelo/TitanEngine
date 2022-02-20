#pragma once

#include "CoreTypes.h"

namespace MemoryUtils
{
	template<typename T>
	FORCEINLINE typename TEnableIf< TIsBitwiseConstructible<T, T>::Value >::Type ConstructItem(const T* source, T* destination)
	{
		Memory::Copy(source, destination, sizeof(T));
	}

	template<typename T>
	FORCEINLINE typename TEnableIf< !TIsBitwiseConstructible<T, T>::Value >::Type ConstructItem(const T* source, T* destination)
	{
		new (destination) T(*source);
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////

	template<typename T>
	FORCEINLINE typename TEnableIf< TIsBitwiseConstructible<T, T>::Value >::Type ConstructItems(const T* source, T* destination, uint32 count)
	{
		Memory::Copy(source, destination, count * sizeof(T));
	}

	template<typename T>
	FORCEINLINE typename TEnableIf< !TIsBitwiseConstructible<T, T>::Value >::Type ConstructItems(const T* source, T* destination, uint32 count)
	{
		while (count--)
		{
			new (destination) T(*source);
			destination++;
			source++;
		}
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////

	template<typename T>
	FORCEINLINE typename TEnableIf< TIsTriviallyDestructible<T>::Value >::Type DestructItem(T* item)
	{
		// Nothing to do
	}

	template<typename T>
	FORCEINLINE typename TEnableIf< !TIsTriviallyDestructible<T>::Value >::Type DestructItem(T* item)
	{
		item->~T();
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////

	template<typename T>
	FORCEINLINE typename TEnableIf< TIsTriviallyDestructible<T>::Value >::Type DestructItems(T* items, uint32 count)
	{
		// Nothing to do
	}

	template<typename T>
	FORCEINLINE typename TEnableIf< !TIsTriviallyDestructible<T>::Value >::Type DestructItems(T* items, uint32 count)
	{
		while (count--)
		{
			(items++)->~T();
		}
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////

	template<typename T>
	FORCEINLINE void CopyItems(const T* source, T* destination, uint32 count)
	{
		Memory::Copy(source, destination, count * sizeof(T));
	}
}