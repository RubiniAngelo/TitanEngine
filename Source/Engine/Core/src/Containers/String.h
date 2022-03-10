#pragma once

#include "CoreTypes.h"
#include "String/Encoding.h"
#include "Array.h"

// TODO: Rework this

class TITAN_API String
{
	using Allocator = THeapAllocator<char>;
	using SizeType = typename Allocator::SizeType;

public:
	String() = default;

	String(const char* str)
	{
		// TODO: Encode the str in UTF-8
		m_Data.AddRange(str, StringUtils::Length(str));
		m_Data.Add('\0');
	}

	String(const Char* str)
	{
		char* encodedStr = Encoding::ConvertUTF8(str, StringUtils::Length(str));
		m_Data.AddRange(encodedStr, StringUtils::Length(str));
		Memory::Free(encodedStr);

		m_Data.Add('\0');
	}

public:
	FORCEINLINE SizeType GetLength() const
	{
		return m_Data.GetCount();
	}

	FORCEINLINE const char* ToArray() const
	{
		return m_Data.ToArray();
	}

public:
	void operator=(const char* str)
	{
		m_Data.Clear();
		m_Data.AddRange(str, StringUtils::Length(str));
		m_Data.Add('\0');
	}

	void operator=(const Char* str)
	{
		m_Data.Clear();

		char* encodedStr = Encoding::ConvertUTF8(str, StringUtils::Length(str));
		m_Data.AddRange(encodedStr, StringUtils::Length(str));
		Memory::Free(encodedStr);

		m_Data.Add('\0');
	}

private:
	TArray<char, Allocator> m_Data;
};