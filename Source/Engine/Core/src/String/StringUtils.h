#pragma once

#include "CoreTypes.h"

#include "PAL/PlatformString.h"

/**
 * Interface that defines methods for managing C-style string.
 */
class TITAN_API StringUtils
{
public:
	/**
	 * Returns the length of the string.
	 * 
	 * @param str - The string to get the length from
	 */
	static int32 Length(const Char* str)
	{
		AssertMsg(str != nullptr, "The string is nullptr!");
		return Private::Platform::Strlen(str);
	}

	/**
	 * Returns the length of the string.
	 * 
	 * @param str - The string to get the length from
	 */
	static int32 Length(const char* str)
	{
		AssertMsg(str != nullptr, "The string is nullptr!");
		return strlen(str);
	}
};