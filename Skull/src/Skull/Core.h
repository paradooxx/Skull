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

#ifdef SK_ENABLE_ASSERTS
	#define SK_ASSERT(x, ...) {if(!(x)) {SK_ERROR("Assertion Failed!: {0}", __VA_ARGS_); __debugbreak(); }}
	#define SK_CORE_ASSERT(x, ...) {if(!(x)) {SK_CORE_ERROR("Assertion Failed!: {0}", __VA_ARGS_); __debugbreak(); }}
#else
	#define SK_ASSERT(x, ...)
	#define SK_CORE_ASSERT(x, ...)
#endif
	

#define BIT(x) (1 << x)