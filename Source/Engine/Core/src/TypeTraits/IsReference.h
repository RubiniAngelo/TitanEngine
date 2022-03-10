#pragma once

template<typename T>
struct TIsReference;

template<typename T>
struct TIsReference
{
	enum { Value = false };
};

template<typename T>
struct TIsReference<T&> 
{ 
	enum { Value = true };
};

template<typename T>
struct TIsReference<T&&>
{
	enum { Value = true };
};