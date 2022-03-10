#include <malloc.h>

namespace Private
{
	namespace Platform
	{
		FORCEINLINE void* Allocate(const Size size, const Size alignment)
		{
			return _aligned_malloc(size, alignment);
		}

		FORCEINLINE void Free(void* ptr)
		{
			_aligned_free(ptr);
		}
	}
}