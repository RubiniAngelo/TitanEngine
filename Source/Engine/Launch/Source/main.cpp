#include <iostream>

#include "Containers/Array.h"

#include <chrono>

class Profiler
{
public:
	template<typename... T>
	static void Start(const char* msg, T... args)
	{
		printf("[Start]\t%s\n", msg, args...);
		m_Start = std::chrono::high_resolution_clock::now();
	}

	template<typename... T>
	static void Stop(const char* msg, T... args)
	{
		m_End = std::chrono::high_resolution_clock::now();
		printf("[End]\t%s\n", msg, args...);
	}

	static void PrintResult()
	{
		printf("Elapsed Time: %llums\n\n", (m_End - m_Start).count() / 1000);
	}

private:
	static std::chrono::steady_clock::time_point m_Start;
	static std::chrono::steady_clock::time_point m_End;
};

std::chrono::steady_clock::time_point Profiler::m_Start;
std::chrono::steady_clock::time_point Profiler::m_End;

#include "Platform/StringUtils.h"

void ConvertWideCharToUTF8(const wchar_t* src, char* dst, TSize size)
{
	char current = *src++;

	while (size--)
	{
		if (current <= 0x7F)
		{
			*dst++ = current;
		}
	}
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);

	const wchar_t* winTitleW = L"WideTitle è";
	char* winTitle = new char[13];
	StringUtils::ConvertWideCharToMultiByte(winTitleW, winTitle, 13);

	printf("%s", winTitle);

	delete[] winTitle;

    return 0;
}