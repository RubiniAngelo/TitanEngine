#pragma once

#include "CoreTypes.h"
#include "Array.h"

template<typename AllocatorType = THeapAllocator<char>>
class TITAN_API String
{
public:
	String() : m_Length(0)
	{
		
	}

	String(const char* str)
	{
		m_Data.AddRange(str);
	}

	String(const wchar_t* str)
	{

	}

public:
	FORCEINLINE int32 GetLength() const
	{
		return m_Data.GetCount();
	}

private:
	char* EncodeUTF8(const char* str);

private:
	TArray<char, AllocatorType> m_Data;
};