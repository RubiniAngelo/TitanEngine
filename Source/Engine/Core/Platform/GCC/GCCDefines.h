#pragma once

#define PLATFORM_COMPILER_GCC 1

#define PLATFORM_DEBUG_BREAK __builtin_trap()
#define PLATFORM_LANG_VERSION __cplusplus

#define FORCEINLINE __attribute__((always_inline))
#define FORCENOINLINE __attribute__((noinline))
#define INLINE __inline__
#define CONSTEXPR constexpr
#define NOEXCEPT noexcept
#define NORETURN __attribute__((noreturn))
#define RESTRICT __restrict__
#define DLLEXPORT __attribute__ ((dllexport)) 
#define DLLIMPORT __attribute__ ((dllimport))