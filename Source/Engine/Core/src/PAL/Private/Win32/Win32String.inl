#include <string.h>

namespace Private
{
	namespace Platform
	{
		FORCEINLINE Size Strlen(const Char* str)
		{
			return wcslen(str);
		}
	}
}