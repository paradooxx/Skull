#pragma once

#ifdef SK_PLATFORM_WINDOWS
	#ifdef SK_BUILD_DLL
		#define SKULL_API _declspec(dllexport)
	#else
		#define SKULL_API _declspec(dllimport)
	#endif
#else
	#error Skull only Supports Windows
#endif