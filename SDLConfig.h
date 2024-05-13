// #define PLATFORM_WIN32 1 // For Windows (you can change 'Win32' to your specific build configuration)
// #define PLATFORM_LINUX 1

#ifndef SDL_CONFIG_H // Ensure this file is only included once
#define SDL_CONFIG_H

#ifdef PLATFORM_WIN32 // This should be defined by your build system for Windows builds
#include "SDL.h"      // Use the 'raw' SDL header if available, typically for native Windows support
#elif defined(PLATFORM_LINUX) || defined(__linux__) || defined(__ANDROID__)
#include <SDL2/SDL.h> // Include SDL2 for Linux and other POSIX-like systems
#else
#error "Unsupported platform"

#endif
#endif
