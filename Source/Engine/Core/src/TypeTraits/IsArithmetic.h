#pragma once

#include "Misc/BasicTypes.h"

#include "RemoveCV.h"

template<typename T> struct TIsArithmetic		{ enum { Value = false }; };

// template<> struct TIsArithmetic<int8>		{ enum { Value = true }; };		// Char already defined
template<> struct TIsArithmetic<int16>			{ enum { Value = true }; };
template<> struct TIsArithmetic<int32>			{ enum { Value = true }; };
template<> struct TIsArithmetic<int64>			{ enum { Value = true }; };
template<> struct TIsArithmetic<long>			{ enum { Value = true }; };
template<> struct TIsArithmetic<float>			{ enum { Value = true }; };
template<> struct TIsArithmetic<double>			{ enum { Value = true }; };

template<> struct TIsArithmetic<uint8>			{ enum { Value = true }; };
template<> struct TIsArithmetic<uint16>			{ enum { Value = true }; };
template<> struct TIsArithmetic<uint32>			{ enum { Value = true }; };
template<> struct TIsArithmetic<uint64>			{ enum { Value = true }; };
template<> struct TIsArithmetic<unsigned long>	{ enum { Value = true }; };

template<> struct TIsArithmetic<bool>			{ enum { Value = true }; };
template<> struct TIsArithmetic<char>			{ enum { Value = true }; };

#if CXX_VERSION >= 20
	template<> struct TIsArithmetic<char8_t>	{ enum { Value = true }; };
#endif

template<> struct TIsArithmetic<char16_t>		{ enum { Value = true }; };
template<> struct TIsArithmetic<char32_t>		{ enum { Value = true }; };
template<> struct TIsArithmetic<wchar_t>		{ enum { Value = true }; };

template<typename T> 
struct TIsArithmetic<const T>					{ enum { Value = TIsArithmetic<T>::Value }; };

template<typename T>
struct TIsArithmetic<volatile T>				{ enum { Value = TIsArithmetic<T>::Value }; };

template<typename T>
struct TIsArithmetic<const volatile T>			{ enum { Value = TIsArithmetic<T>::Value }; };