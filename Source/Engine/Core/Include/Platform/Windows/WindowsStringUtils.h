#pragma once

#include "CoreTypes.h"
#include "Platform/Base/BasePlatformStringUtils.h"

#include "WindowsInclude.h"
#include <stringapiset.h>

class TITAN_API WindowsStringUtils : public BasePlatformStringUtils
{
public:
	FORCEINLINE static int32 Strlen(const char* str)
	{
		return strlen(str);
	}

	FORCEINLINE static int32 Strlen(const Char* str)
	{
		return wcslen(str);
	}
};

typedef WindowsStringUtils StringUtils;