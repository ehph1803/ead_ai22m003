#pragma once

#ifdef GEE_PLATFORM_WINDOWS
	#ifdef GEE_BUILD_DLL
		#define GEE_API __declspec(dllexport)
	#else
		#define GEE_API __declspec(dllimport)
	#endif
#else
	#error GEE only supports Windows!
#endif

#ifdef GEE_ENABLE_ASSERTS
	#define GEE_ASSERT(x, ...) { if(!(x)) { GEE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define GEE_CORE_ASSERT(x, ...) { if(!(x)) { GEE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define GEE_ASSERT(x, ...)
	#define GEE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1<<x)