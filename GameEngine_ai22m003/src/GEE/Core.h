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