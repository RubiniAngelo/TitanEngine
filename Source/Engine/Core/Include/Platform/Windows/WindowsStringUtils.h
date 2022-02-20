#pragma once

#include "CoreTypes.h"
#include "Platform/Base/BasePlatformStringUtils.h"

#include "WindowsInclude.h"
#include <stringapiset.h>

class TITAN_API WindowsStringUtils : public BasePlatformStringUtils
{
public:
	FORCEINLINE static int32 ConvertWideCharToMultiByte(const wchar_t* source, char* destination, const TSize count)
	{
		// Win32 API: https://docs.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-widechartomultibyte
		return WideCharToMultiByte(CP_UTF8, 0, source, -1, destination, count, nullptr, nullptr);
	}

	FORCEINLINE static int32 ConvertMultiByteToWideChar(const char* source, wchar_t* destination, const TSize count)
	{
		// Win32 API: https://docs.microsoft.com/en-us/windows/win32/api/stringapiset/nf-stringapiset-multibytetowidechar
		return MultiByteToWideChar(CP_UTF8, 0, source, -1, destination, count);
	}
};

typedef WindowsStringUtils StringUtils;