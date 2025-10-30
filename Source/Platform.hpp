#pragma once

/*
	platform.hpp - useful macros for detecting various operating systems
	provides macros PLATFORM(NAME), GESTALT_API
*/

#if defined(_WIN32) || defined(_WIN64)
#define GESTALT_IS_PLATFORM_WIN 1
#endif // _WIN32

#if defined(__linux__)
#define GESTALT_IS_PLATFORM_LINUX 1
#endif

#if defined(__APPLE__) && defined(__MACH__)
#define GESTALT_IS_PLATFORM_DARWIN 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR == 1
#define GESTALT_IS_PLATFORM_IOS
#define GESTALT_IS_PLATFORM_IOS_XCODE_SIMULATOR
#elif TARGET_OS_IPHONE == 1
#define GESTALT_IS_PLATFORM_IOS
#elif TARGET_OS_MAC == 1
#define GESTALT_IS_PLATFORM_MAC
#endif
#endif // defined(__APPLE__) && defined(__MACH__)

#ifndef GESTALT_IS_PLATFORM_WIN
#define GESTALT_IS_PLATFORN_WIN 0
#endif // GESTALT_IS_PLATFORN_WIN

#ifndef GESTALT_IS_PLATFORM_LINUX
#define GESTALT_IS_PLATFORM_LINUX 0
#endif // GESTALT_IS_PLATFORM_LINUX

#ifndef GESTALT_IS_PLATFORM_DARWIN
#define GESTALT_IS_PLATFORM_DARWIN 0
#endif // GESTALT_IS_PLATFORM_DARWIN

#ifndef GESTALT_IS_PLATFORM_IOS
#define GESTALT_IS_PLATFORM_IOS 0
#endif // GESTALT_IS_PLATFORM_IOS

#ifndef GESTALT_IS_PLATFORM_IOS_XCODE_SIMULATOR
#define GESTALT_IS_PLATFORM_IOS_XCODE_SIMULATOR 0
#endif // GESTALT_IS_PLATFORM_IOS_XCODE_SIMULATOR

#ifndef GESTALT_IS_PLATFORM_MAC
#define GESTALT_IS_PLATFORM_MAC 0
#endif // GESTALT_IS_PLATFORM_MAC

// PLATFORM(NAME) - compile-time check for specific operating system
// usage:
//     #if PLATFORM(WIN)
//     // Windows-specific stuff
//     #elif PLATFORM(DARWIN)
//     // MacOS-specific stuff
//     #elif PLATFORM(LINUX)
//     printf("Not supported :D\n);
//     exit(1);
//     #endif
#define PLATFORM(NAME) GESTALT_IS_PLATFORM_##NAME

#ifdef __cplusplus
#define GESTALT_EXTERN extern "C"
#else
#define GESTALT_EXTERN
#endif // __cplusplus

#if PLATFORM(WIN)
#ifdef GESTALT_DLL_EXPORT
#define GESTALT_API __declspec(dllexport)
#else
#define GESTALT_API __declspec(dllimport)
#endif // GESTALT_DLL_EXPORT
#else
#define GESTALT_API GESTALT_EXTERN
#endif // PLATFORM(WIN)

#define GESTALT_C_API GESTALT_EXTERN GESTALT_API