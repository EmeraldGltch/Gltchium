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

#ifdef GC_ENABLE_ASSERTS
	#define GC_ASSERT(x, ...) { if(!(x)) { GC_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define GC_CORE_ASSERT(x, ...) { if(!(x)) { GC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define GC_ASSERT(x, ...)
	#define GC_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define GC_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)