#pragma once

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