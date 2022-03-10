#pragma once

#include "CorePCH.h"

#include "PAL/PlatformWindow.h"

class TITAN_API Window
{
public:
	int32 Create(String title, int32 width, int32 height)
	{
		m_Title = title;
		m_WindowHandle = Private::Platform::CreateWindow(title, width, height);

		return 1;
	}

	int32 Update() 
	{ 
		Private::Platform::UpdateWindow();

		return 1;
	}

	int32 Destroy()
	{
		Private::Platform::DestroyWindow(m_Title);

		return 1;
	}

private:
	void* m_WindowHandle;
	String m_Title;
};