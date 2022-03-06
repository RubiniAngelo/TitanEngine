#pragma once

#include "CoreTypes.h"

class TITAN_API BasePlatformStringUtils
{
public:
	FORCEINLINE static int32 Strlen(const Char* str) = delete;

	FORCEINLINE static int32 Strlen(const char* str) = delete;
};