#pragma once

// Relies on SFINAE (Substitution Failure Is Not An Error)

template<bool Condition, typename Result = void>
struct TEnableIf;

template<typename Result>
struct TEnableIf<false, Result>
{
	/** Do nothing */
};

template<typename Result>
struct TEnableIf<true, Result>
{
	typedef Result Type;
};