#pragma once

namespace Private
{
	template<bool Left, bool... Right>
	struct TAnd;

	template<bool... Right>
	struct TAnd<true, Right...>
	{
		enum { Value = Private::TAnd<Right...>::Value };
	};

	template<bool... Right>
	struct TAnd<false, Right...>
	{
		enum { Value = false };
	};

	template<>
	struct TAnd<true, true>
	{
		enum { Value = true };
	};
}

template<bool... Conditions>
struct TAnd 
{ 
	enum { Value = Private::TAnd<Conditions...>::Value }; 
};