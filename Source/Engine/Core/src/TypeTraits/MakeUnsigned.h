#pragma once

#include "IsArithmetic.h"
#include "EnableIf.h"
#include "IsSame.h"
#include "And.h"

template<typename T> struct TMakeUnsigned;

template<> struct TMakeUnsigned<int8>	{ typedef unsigned char Type; };
template<> struct TMakeUnsigned<int16>	{ typedef uint16 Type; };
template<> struct TMakeUnsigned<int32>	{ typedef uint32 Type; };
template<> struct TMakeUnsigned<int64>	{ typedef uint64 Type; };
template<> struct TMakeUnsigned<long>	{ typedef unsigned long Type; };

template<typename T>
struct TMakeUnsigned<const T>			{ typedef typename TMakeUnsigned<T>::Type Type; };

template<typename T>
struct TMakeUnsigned<volatile T>		{ typedef typename TMakeUnsigned<T>::Type Type; };

template<typename T>
struct TMakeUnsigned<const volatile T>	{ typedef typename TMakeUnsigned<T>::Type Type; };