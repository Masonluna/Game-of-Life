#pragma once

#ifdef SCB_ENABLE_ASSERTS
	#define SCB_ASSERT(x, ...) { if (!(x)) { SCB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define SCB_CORE_ASSERT(x, ...) { if (!(x)) { SCB_CORE_ERROR("Assertion Failed: {0}", __ VA_ARGS__); __debugbreak();) }}
#else
	#define SCB_ASSERT(x, ...)
	#define SCB_CORE_ASSERT(x, ...)
#endif
