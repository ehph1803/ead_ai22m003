#pragma once

#ifdef GE_PLATFORM_WINDOWS
	#ifdef GE_BUILD_DLL
		#define GEEHM_API __declspec(dllexport)
	#else
		#define GEEHM_API __declspec(dllimport)
	#endif
#else
	#error GE_Ehm only supports Windows!
#endif