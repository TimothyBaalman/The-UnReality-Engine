#pragma once

#ifdef UR_PLATFORM_WINDOWS
	#ifdef UR_BUILD_DLL
		#define UR_API __declspec(dllexport)
	#else 
		#define UR_API __declspec(dllimport)
	#endif // UR_BUILD_DLL
#else
	#error UnReality Currently Only Supports Windows!
#endif // UR_PLATFORM_WINDOWS

#define BIT(x) (1 << x)