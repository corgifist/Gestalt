#pragma once

#include <iostream>

#include "Platform.h"
#include "Feature.h"

// strip down Windows.h to achieve faster compilation times
#if PLATFORM(WIN)
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

// include a small amount of commonly used standard library headers
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <memory>

// heavily used by Gestalt's C API
// C does not have exception handling so that's the only way of checking errors
#define GESTALT_SUCCESS 0
#define GESTALT_ERROR 1

using GestaltResult = int;

GESTALT_C_API void GestaltC();

namespace Gestalt {
	void NamespaceTest();
} // namespace gestalt