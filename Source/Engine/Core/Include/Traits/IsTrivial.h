#pragma once

#include "IsEnum.h"
//
//namespace Private
//{
//    template<typename T, bool IsDestructible = __is_enum(T)>
//    struct TIsTriviallyConstructible;
//
//    template<typename T>
//    struct TIsTriviallyConstructible<T, true>
//    {
//        enum { Value = false; };
//    };
//
//    template<typename T>
//    struct TIsTriviallyConstructible<T, false>
//    {
//        enum { Value = __has_trivial_constructor(T) };
//    };
//}
//
//template<typename T>
//struct TIsTriviallyConstructible
//{
//    enum { Value = Private::TIsTriviallyConstructible<T>::Value };
//};
//
/////////////////////////////////////////////////////////////////////
//
//namespace Private
//{
//    template<typename T, bool IsDestructible = TIsEnum<T>::Value>
//    struct TIsTriviallyDestructible;
//
//    template<typename T>
//    struct TIsTriviallyDestructible<T, true>
//    {
//        enum { Value = false; };
//    };
//
//    template<typename T>
//    struct TIsTriviallyDestructible<T, false>
//    {
//        enum { Value = __has_trivial_destructor(T) };
//    };
//}
//
//template<typename T>
//struct TIsTriviallyDestructible
//{
//    enum { Value = Private::TIsTriviallyDestructible<T>::Value };
//};
//
/////////////////////////////////////////////////////////////////////
//
//template<typename T>
//struct TIsTrivial
//{
//    enum { Value = (TIsTriviallyConstructible<T>::Value && TIsTriviallyDestructible<T>::Value) };
//};