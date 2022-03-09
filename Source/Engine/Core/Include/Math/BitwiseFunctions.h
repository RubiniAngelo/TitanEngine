#pragma once

#include "CoreTypes.h"

namespace Math
{
	FORCEINLINE CONSTEXPR uint8 Reverse8Bit(const uint8 value) NOEXCEPT
    {
        return
            ((value & 0x1) << 7) | ((value & 0x2) << 5) |
            ((value & 0x4) << 3) | ((value & 0x8) << 1) |
            ((value & 0x10) >> 1) | ((value & 0x20) >> 3) |
            ((value & 0x40) >> 5) | ((value & 0x80) >> 7);
    }
}