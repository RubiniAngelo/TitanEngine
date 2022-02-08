#pragma once

#include <stdlib.h>

// TODO: Comment this

namespace Internal
{
    template<typename T, bool IsDestructible = __is_enum(T)>
    struct TIsTriviallyConstructible;

    template<typename T>
    struct TIsTriviallyConstructible<T, true>
    {
        const bool Value = false;
    };

    template<typename T>
    struct TIsTriviallyConstructible<T, false>
    {
        const bool Value = __has_trivial_constructor(T);
    };

    /////////////////////////////////////////////////////////////////////

    template<typename T, bool IsDestructible = __is_enum(T)>
    struct TIsTriviallyDestructible;

    template<typename T>
    struct TIsTriviallyDestructible<T, true>
    {
        const bool Value = false;
    };

    template<typename T>
    struct TIsTriviallyDestructible<T, false>
    {
        const bool Value = __has_trivial_destructor(T);
    };
}


/////////////////////////////////////////////////////////////////////

template<typename T>
struct TIsTriviallyConstructible
{
    const bool Value = Internal::TIsTriviallyConstructible<T>::Value;
};


/////////////////////////////////////////////////////////////////////

template<typename T>
struct TIsTriviallyDestructible
{
    const bool Value = Internal::TIsTriviallyDestructible<T>::Value;
};


/////////////////////////////////////////////////////////////////////

// Relies on SFINAE

template<bool Expression, typename Result = void>
struct TEnableIf;

template<typename Result>
struct TEnableIf<false, Result> { };

template<typename Result>
struct TEnableIf<true, Result>
{
    typedef Result Type;
};


/////////////////////////////////////////////////////////////////////

template<typename T, typename U, bool Expression>
struct TSelectIf;

template<typename T, typename U>
struct TSelectIf<T, U, true> 
{ 
    typedef T Value;
};

template<typename T, typename U>
struct TSelectIf<T, U, false>
{
    typedef U Value;
};