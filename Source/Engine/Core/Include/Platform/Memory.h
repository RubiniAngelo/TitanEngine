#pragma once

#include "Defines.h"

#if PLATFORM_WINDOWS
#   include "Windows/WindowsMemory.h"
#else
#   error "Memory implementation is missing!"
#endif