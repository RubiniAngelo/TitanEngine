#pragma once

namespace Private
{
	template<typename T, bool IsEnum = __is_enum(T)>
	struct TIsTriviallyConstructible;

	template<typename T>
	struct TIsTriviallyConstructible<T, true>
	{
		enum { Value = false };
	};

	template<typename T>
	struct TIsTriviallyConstructible<T, false>
	{
		enum { Value = __has_trivial_constructor(T) };
	};
}

template<typename T>
struct TIsTriviallyConstructible
{
	enum { Value = Private::TIsTriviallyConstructible<T>::Value };
};