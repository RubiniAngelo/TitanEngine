#pragma once

#define PLATFORM_COMPILER_MSC 1

#define PLATFORM_DEBUG_BREAK __debugbreak()
#define PLATFORM_LANG_VERSION _MSVC_LANG

#define FORCEINLINE __forceinline
#define FORCENOINLINE __declspec(noinline)
#define INLINE __inline
#define CONSTEXPR constexpr
#define NOEXCEPT noexcept
#define NORETURN __declspec(noreturn)
#define RESTRICT __restrict
#define DLLEXPORT __declspec(dllexport) 
#define DLLIMPORT __declspec(dllimport)
