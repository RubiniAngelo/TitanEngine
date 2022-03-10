#pragma once

#include "CorePCH.h"

namespace Platform
{
	namespace Graphics
	{
		void* CreateWindow(const String& title, const int32 width, const int32 height);
		void UpdateWindow();
		void DestroyWindow(const String& windowClass);
	}
}

#if PLATFORM_WINDOWS
#	include "Private/Win32/Win32Windows.inl"
#else
#	error "Window implementation is missing!"
#endif