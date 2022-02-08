#pragma once

#include "Core/CoreTypes.h"

// TODO: Comment this

class TITAN_API Math
{
public:
    template<typename T, typename U>
    FORCEINLINE static typename TSelectIf<T, U, (sizeof(T) >= sizeof(U))>::Value Max(T lhs, U rhs) NOEXCEPT
    {
        return (lhs > rhs) ? lhs : rhs;
    }

    template<typename T, typename U>
    FORCEINLINE static typename TSelectIf<T, U, sizeof(T) >= sizeof(U)>::Value Min(T lhs, U rhs) NOEXCEPT
    {
        return (lhs < rhs) ? lhs : rhs;
    }

    template<typename T>
    FORCEINLINE static bool IsPowerOfTwo(const T& value)
    {
        return value == 0 ? false : (value & (value - 1)) == 0;
    }
};