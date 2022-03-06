#pragma once

#include "CoreTypes.h"
#include "Array.h"
#include "Platform/PlatformString.h"

template<typename AllocatorType = THeapAllocator<char>>
class TITAN_API String
{
	using SizeType = typename AllocatorType::SizeType;

public:
	String() : m_Length(0)
	{
		
	}

	String(const char* str)
	{
		m_Data.AddRange(str, StringUtils::GetLength(str));
	}

	String(const Char* str)
	{
		m_Data.AddRange(str, StringUtils::GetLength(str));
	}

public:
	FORCEINLINE SizeType GetLength() const
	{
		return m_Data.GetCount();
	}

private:
	
private:
	TArray<char, AllocatorType> m_Data;
};