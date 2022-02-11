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
        enum { Value = false; };
    };

    template<typename T>
    struct TIsTriviallyConstructible<T, false>
    {
        enum { Value = __has_trivial_constructor(T) };
    };

    /////////////////////////////////////////////////////////////////////

    template<typename T, bool IsDestructible = __is_enum(T)>
    struct TIsTriviallyDestructible;

    template<typename T>
    struct TIsTriviallyDestructible<T, true>
    {
        enum { Value = false; };
    };

    template<typename T>
    struct TIsTriviallyDestructible<T, false>
    {
        enum { Value = __has_trivial_destructor(T) };
    };
}


/////////////////////////////////////////////////////////////////////

template<typename T>
struct TIsTriviallyConstructible
{
    enum { Value = Internal::TIsTriviallyConstructible<T>::Value };
};


/////////////////////////////////////////////////////////////////////

template<typename T>
struct TIsTriviallyDestructible
{
    enum { Value = Internal::TIsTriviallyDestructible<T>::Value };
};


/////////////////////////////////////////////////////////////////////

// Relies on SFINAE

template<bool Condition, typename Result = void> 
struct TEnableIf;

template<typename Result>
struct TEnableIf<false, Result> { };

template<typename Result>
struct TEnableIf<true, Result>
{
    typedef Result Type;
};


/////////////////////////////////////////////////////////////////////

template<typename T, typename U, bool Condition>
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

/////////////////////////////////////////////////////////////////////

// Check if the type is a pod (plain old data structure, i.e. structs or classes that only have variables)

template<typename T>
struct TIsPOD
{
    enum { Value = __is_pod(T) || __is_enum(T) };
};