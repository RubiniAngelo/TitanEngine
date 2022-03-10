#include <iostream>
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

#include "CorePCH.h"
#include "Window.h"

#include <thread>

int main()
{
    Window win;
    Window win2;
    win.Create("Prova123", 360, 360);
    win2.Create("Prova123", 360, 360);

    while (true)
    {
        win.Update();
        win2.Update();
    }

    win.Destroy();
    win2.Destroy();

    return 0;
}