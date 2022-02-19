#pragma once

namespace Private
{
	template<bool Left, bool... Right>
	struct TOr;

	template<bool... Right>
	struct TOr<true, Right...>
	{
		enum { Value = true };
	};

	template<bool... Right>
	struct TOr<false, Right...>
	{
		enum { Value = TOr<Right...>::Value };
	};

	template<>
	struct TOr<false, false>
	{
		enum { Value = false };
	};
}

template<bool... Conditions>
struct TOr
{
	enum { Value = Private::TOr<Conditions...>::Value };
};