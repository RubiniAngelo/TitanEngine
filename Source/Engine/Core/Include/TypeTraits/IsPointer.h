#pragma once

template<typename T>
struct TIsPointer;

template<typename T>
struct TIsPointer
{
	enum { Value = false };
};

template<typename T>
struct TIsPointer<T*>
{
	enum { Value = true };
};

template<typename T>
struct TIsPointer<T**>
{
	enum { Value = true };
};