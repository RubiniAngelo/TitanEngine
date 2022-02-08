#pragma once

#include "Core/CoreTypes.h"

// TODO: Comment this

class TITAN_API Math
{
public:
    template<typename T, typename U>
    FORCEINLINE static typename TSelectIf<T, U, (sizeof(T) >= sizeof(U))>::Value Max(T Lhs, U Rhs) NOEXCEPT
    {
        return (Lhs > Rhs) ? Lhs : Rhs;
    }

    template<typename T, typename U>
    FORCEINLINE static typename TSelectIf<T, U, sizeof(T) >= sizeof(U)>::Value Min(T Lhs, U Rhs) NOEXCEPT
    {
        return (Lhs < Rhs) ? Lhs : Rhs;
    }

    template<typename T>
    FORCEINLINE static bool IsPowerOf2(const T& Value)
    {
        return Value == 0 ? false : (Value & (Value - 1)) == 0;
    }

    template<typename T>
    FORCEINLINE static T RoundTo2(const T& Value)
    {
        if (Value < 0)
            return 0;

        T Temp = Value - 1;

        Temp |= Temp >> 1;
        Temp |= Temp >> 2;
        Temp |= Temp >> 4;
        Temp |= Temp >> 8;
        Temp |= Temp >> 16;

        return Temp + 1;
    }
};