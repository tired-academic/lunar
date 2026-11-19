/*
 * Include/Utility.hpp
 *
 * Utilities for the project, export macros, weird hacks, whatever
 * is needed.
 *
 * SPDX-License-Identifier: zlib
 */

#pragma once

#if defined(_WIN32) || defined(_WIN64)
    #define L_EXPORT __declspec(dllexport)
#elif defined(__linux__) || defined(__APPLE__)
    #define L_EXPORT __attribute__((visibility("default")))
#else
    #warning "Unknown system, assuming Linux-like defaults!"
    #define L_EXPORT __attribute__((visibility("default")))
#endif /* L_EXPORT */

#ifdef LUNAR_C_FFI
    #define FFI extern "C"
#else
    #define FFI
#endif /* LUNAR_C_FFI */

#if defined(_WIN32) || defined(_WIN64)
    #ifndef NOMINMAX
        #define NOMINMAX
    #endif /* NOMINMAX */
    
    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif /* WIN32_LEAN_AND_MEAN */
#endif
