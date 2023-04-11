#pragma once

#ifdef GC_PLATFORM_WINDOWS
#ifdef GC_BUILD_DLL
#define GLTCHIUM_API __declspec(dllexport)
#else
#define GLTCHIUM_API __declspec(dllimport)
#endif
#else
#error Gltchium only supports Windows!
#endif