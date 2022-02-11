#pragma once

#include "CoreTypes.h"

// TODO: Comment this

class TITAN_API Math
{
public:
    template<typename T, typename U>
    FORCEINLINE static typename TSelectIf<T, U, (sizeof(T) >= sizeof(U))>::Value Max(const T& lhs, const U& rhs) NOEXCEPT
    {
        return (lhs > rhs) ? lhs : rhs;
    }

    template<typename T, typename U>
    FORCEINLINE static typename TSelectIf<T, U, sizeof(T) >= sizeof(U)>::Value Min(const T& lhs, const U& rhs) NOEXCEPT
    {
        return (lhs < rhs) ? lhs : rhs;
    }

    template<typename T>
    FORCEINLINE static bool IsPowerOf2(const T& value) NOEXCEPT
    {
        return value <= 0 ? false : (value & (value - 1)) == 0;
    }

    template<typename T>
    FORCEINLINE static T RoundToPowerOf2(const T& value) NOEXCEPT
    {
        if (value < 0)
            return 0;

        T temp = value - 1;

        temp |= temp >> 1;
        temp |= temp >> 2;
        temp |= temp >> 4;
        temp |= temp >> 8;
        temp |= temp >> 16;

        return temp + 1;
    }
};
