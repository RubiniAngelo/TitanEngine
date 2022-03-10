#pragma once

#include "PlatformDefines.h"
#include "CoreTypes.h"

namespace Private
{
	namespace Platform
	{
		Size Strlen(const Char* str);
	}
}

#if PLATFORM_WINDOWS
#	include "Private/Win32/Win32String.inl"
#else
#	error "String implementation is missing!"
#endif