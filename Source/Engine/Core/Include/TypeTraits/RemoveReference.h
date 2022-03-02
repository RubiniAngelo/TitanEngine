#pragma once

/** 
 * It will remove any references from a given type. 
 */
template<typename T> struct TRemoveReference		{ typedef T Type; };
template<typename T> struct TRemoveReference<T&>	{ typedef T Type; };
template<typename T> struct TRemoveReference<T&&>	{ typedef T Type; };