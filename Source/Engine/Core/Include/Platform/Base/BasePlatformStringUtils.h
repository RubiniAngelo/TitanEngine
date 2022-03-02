#pragma once

#include "CoreTypes.h"

class TITAN_API BasePlatformStringUtils
{
public:
	FORCEINLINE static int32 ConvertWideCharToMultiByte(const wchar_t* source, char* destination, const Size count) = delete;
	FORCEINLINE static int32 ConvertMultiByteToWideChar(const char* source, wchar_t* destination, const Size count) = delete;
};