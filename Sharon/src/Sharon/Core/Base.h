#pragma once

#ifdef SHARON_PLATFORM_WINDOWS
#ifdef SHARON_DYNAMIC_LINK
    #ifdef SHARON_BUILD_DLL
        #define SHARON_API __declspec(dllexport)
    #else
        #define SHARON_API __declspec(dllimport)
    #endif
#else
    #define SHARON_API
#endif
#else
    #error Sharon supports only Windows :<
#endif

#ifdef SHARON_DEBUG
    #define SHARON_ENABLE_ASSERTS
#endif

#ifdef SHARON_ENABLE_ASSERTS
    #define SHARON_ASSERT(x, ...) { if(!(x)) { SHARON_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
    #define SHARON_CORE_ASSERT(x, ...) { if(!(x)) { SHARON_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
    #define SHARON_ASSERT(x, ...)
    #define SHARON_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define SHARON_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)