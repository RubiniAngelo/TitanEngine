#pragma once

#if _MSC_VER > 1800 // Required at least VS15
#    include "MSC/MSCPlatform.h"
#elif __clang__
#    error "Compiler not implemented yet!"
#elif __GNUC__
#    error "Compiler not implemented yet!"
#endif

#if _WIN32
#   include "Windows/WindowsPlatform.h"
#else
#   error "Platform implementation is missing!"
#endif

#if PLATFORM_LANG_VERSION == 202002L
#  define CXX_VERSION 20
#elif PLATFORM_LANG_VERSION == 201703L
#  define CXX_VERSION 17
#elif PLATFORM_LANG_VERSION == 201402L
#  define CXX_VERSION 14
#else
#  error "Titan requires at least C++ 14!"
#endif


/** Define and set missing macros */

#ifndef PLATFORM_COMPILER_MSC
#   define PLATFORM_COMPILER_MSC 0
#endif

#ifndef PLATFORM_WINDOWS
#   define PLATFORM_WINDOWS 1
#endif

#ifndef PLATFORM_ARCH_64BITS
#   define PLATFORM_ARCH_64BITS 0
#endif

#ifndef PLATFORM_ARCH_32BITS
#   define PLATFORM_ARCH_32BITS 0
#endif