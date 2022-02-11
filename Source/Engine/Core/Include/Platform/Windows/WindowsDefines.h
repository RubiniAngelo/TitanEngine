#pragma once

#define PLATFORM_WINDOWS 1

#if _WIN64
#   define PLATFORM_ARCH_64BITS 1
#else
#   define PLATFORM_ARCH_32BITS 1
#endif