#pragma once

namespace Private
{
	template<typename T, bool IsEnum = __is_enum(T)>
	struct TIsTriviallyDestructible;

	template<typename T>
	struct TIsTriviallyDestructible<T, true>
	{
		enum { Value = false };
	};

	template<typename T>
	struct TIsTriviallyDestructible<T, false>
	{
		enum { Value = __has_trivial_destructor(T) };
	};
}

template<typename T>
struct TIsTriviallyDestructible
{
	enum { Value = Private::TIsTriviallyDestructible<T>::Value };
};