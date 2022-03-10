#pragma once

#include "IsReference.h"
#include "AreTypesEqual.h"
#include "RemoveCV.h"
#include "IsTriviallyConstructible.h"

/**
 * Checks if type T is bitwise constructible from type U.
 * 
 * That is, it tests if it is possible to create an instance 
 * of T memcopying U, without having to use the constructor.
 */
template<typename T, typename U>
struct TIsBitwiseConstructible
{
	static_assert(
		!TIsReference<T>::Value &&
		!TIsReference<U>::Value,

		"TIsBitwiseConstructible cannot accept a reference type"
	);

	static_assert(
		TAreTypesEqual<T, typename TRemoveCV<T>::Type>::Value &&
		TAreTypesEqual<U, typename TRemoveCV<U>::Type>::Value,

		"TIsBitwiseConstructible cannot accept a qualified type"
	);

	// It is generally assumed that it is not bitwise constructable 
	enum { Value = false };
};

template<typename T, typename U>
struct TIsBitwiseConstructible<const T, U> : TIsBitwiseConstructible<T, U> { };

template<typename T, typename U>
struct TIsBitwiseConstructible<const T*, U*> : TIsBitwiseConstructible<T, U> { };

template<typename T> struct TIsBitwiseConstructible<T, T>
{ 
	// If T is trivially constructible, it can always be bitwise constructed
	enum { Value = TIsTriviallyConstructible<T>::Value }; 
};

template<typename T> struct TIsBitwiseConstructible<const T , T >	{ enum { Value = true }; };
template<typename T> struct TIsBitwiseConstructible<const T*, T*>	{ enum { Value = true }; };



// Signed types and their unsigned equivalents are always bitwise constructable
template<> struct TIsBitwiseConstructible<int8 , uint8 > { enum { Value = true }; };
template<> struct TIsBitwiseConstructible<int16, uint16> { enum { Value = true }; };
template<> struct TIsBitwiseConstructible<int32, uint32> { enum { Value = true }; };
template<> struct TIsBitwiseConstructible<int64, uint64> { enum { Value = true }; };

template<> struct TIsBitwiseConstructible<uint8 , int8 > { enum { Value = true }; };
template<> struct TIsBitwiseConstructible<uint16, int16> { enum { Value = true }; };
template<> struct TIsBitwiseConstructible<uint32, int32> { enum { Value = true }; };
template<> struct TIsBitwiseConstructible<uint64, int64> { enum { Value = true }; };