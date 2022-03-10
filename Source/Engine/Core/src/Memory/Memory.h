#pragma once

#include "CoreTypes.h"
#include "Math/Math.h"
#include "PAL/PlatformMemory.h"

#include <string.h>	// memcpy

#define DEFAULT_ALIGNMENT 16

namespace MemoryUtils
{
	template<typename T>
	typename TRemoveReference<T>::Type&& Move(T&& value)
	{
		return std::move(value);
	}

	template<typename T, typename U>
	void Swap(T& lhs, U& rhs)
	{
		T temp	= Move(lhs);
		lhs		= Move(rhs);
		rhs		= Move(temp);
	}

	template<typename T>
	typename TEnableIf< TIsBitwiseConstructible<T, T>::Value >::Type ConstructItem(const T* source, T* destination)
	{
		Memory::Copy(source, destination, sizeof(T));
	}

	template<typename T>
	typename TEnableIf<!TIsBitwiseConstructible<T, T>::Value >::Type ConstructItem(const T* source, T* destination)
	{
		new (destination) T(*source);
	}

	template<typename T>
	typename TEnableIf< TIsBitwiseConstructible<T, T>::Value >::Type ConstructItems(const T* source, T* destination, uint32 count)
	{
		Memory::Copy(source, destination, count * sizeof(T));
	}

	template<typename T>
	typename TEnableIf<!TIsBitwiseConstructible<T, T>::Value >::Type ConstructItems(const T* source, T* destination, uint32 count)
	{
		while (count--)
		{
			new (destination) T(*source);
			destination++;
			source++;
		}
	}

	template<typename T>
	typename TEnableIf< TIsTriviallyDestructible<T>::Value >::Type DestructItem(T* item)
	{
		// Nothing to do
	}

	template<typename T>
	typename TEnableIf<!TIsTriviallyDestructible<T>::Value >::Type DestructItem(T* item)
	{
		item->~T();
	}

	template<typename T>
	typename TEnableIf< TIsTriviallyDestructible<T>::Value >::Type DestructItems(T* items, uint32 count)
	{
		// Nothing to do
	}

	template<typename T>
	typename TEnableIf<!TIsTriviallyDestructible<T>::Value >::Type DestructItems(T* items, uint32 count)
	{
		while (count--)
		{
			(items++)->~T();
		}
	}

	template<typename T>
	void CopyItems(const T* source, T* destination, uint32 count)
	{
		Memory::Copy(source, destination, count * sizeof(T));
	}
}

/**
 * Interface that defines methods for managing memory.
 */
class TITAN_API Memory
{
public:
	/**
	 * Allocates memory on a specified alignment boundary.
	 */
	static FORCEINLINE void* Allocate(const Size size, const uint8 alignment = DEFAULT_ALIGNMENT)
	{
		AssertMsg(Math::IsPowerOf2(alignment), "The alignment must be a power of two!");
		return Private::Platform::Allocate(size, alignment);
	}

	/**
	 * Frees a block of memory that was allocated.
	 */
	static FORCEINLINE void Free(void* ptr)
	{
		AssertMsg(ptr != nullptr, "The pointer is nullptr!");
		Private::Platform::Free(ptr);
	}

	/**
	 * Copies bytes between buffers.
	 */
	static FORCEINLINE void Copy(const void* source, void* destination, const Size size)
	{
		AssertMsg(source != nullptr && destination != nullptr, "The pointer is nullptr!");
		memcpy(destination, source, size);
	}

};