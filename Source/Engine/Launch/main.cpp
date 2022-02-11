#include <iostream>
#include <vector>

#include "Platform/Windows/WindowsInclude.h"
#include "CoreTypes.h"
#include "Math/Math.h"
#include "Memory/Allocator.h"

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

#include <type_traits>

class Prova
{
public:
    Prova(int) { }
};

class Prova2
{
public:

};

typedef int* Ptr;

int main()
{
    printf("%d\n", TIsPOD<Ptr>::Value);
    printf("%d\n", TIsPOD<Ptr>::Value);
}