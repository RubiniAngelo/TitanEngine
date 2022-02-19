#pragma once

/**
 * Check if the given types are equal.
 */
template<typename T, typename U>	
struct TAreTypesEqual
{ 
	enum { Value = false }; 
};

template<typename T>				
struct TAreTypesEqual<T, T>	{ enum { Value = true }; };