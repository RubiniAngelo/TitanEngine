#pragma once

#include "PlatformDefines.h"
#include "CoreTypes.h"

namespace Private
{
	namespace Platform
	{
		void* Allocate(const Size size, const Size alignment);
		void Free(void* ptr);
	}
}

#if PLATFORM_WINDOWS
#	include "Private/Win32/Win32Memory.inl"
#else
#   error "Memory implementation is missing!"
#endif