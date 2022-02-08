#pragma once

#include "Core/CoreTypes.h"

class TITAN_API BasePlatformMemory
{
public:
    FORCEINLINE static void* Allocate(const Size size, const Size alignment) = delete;
    FORCEINLINE static void  Free(void* ptr) = delete;
};