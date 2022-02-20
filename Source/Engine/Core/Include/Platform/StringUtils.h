#pragma once

#include "Defines.h"

#if PLATFORM_WINDOWS
#   include "Windows/WindowsStringUtils.h"
#else
#   error "StringUtils implementation is missing!"
#endif