#include <iostream>
#include <vector>

#include "Core/Platform/Windows/WindowsInclude.h"
#include "Core/CoreTypes.h"
#include "Core/Math/Math.h"
#include "Core/Memory/Allocator.h"

// Just a temp code

#include <chrono>

auto start = std::chrono::high_resolution_clock::now();

void StartProfiling()
{
    start = std::chrono::high_resolution_clock::now();
}

void StopProfiling()
{
    printf("%llums\n", (std::chrono::high_resolution_clock::now() - start).count());
}

int main()
{

}
