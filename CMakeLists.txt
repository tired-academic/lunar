# Lunar is a C++ implementation of the Lua programming language
# (C) 2026 tired-academic
# SPDX-License-Identifier: zlib

cmake_minimum_required(VERSION 3.28)
project(
    Lunar
    LANGUAGES C CXX
    VERSION 0.0.1
)

if(${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
    message(FATAL_ERROR "In-source builds are not supported!")
endif()

option(LUNAR_C_FFI "Enables a C-friendly FFI for use in C-family projects." ON)

if(NOT LUNAR_C_FFI)
    message(STATUS "Disabling the C FFI...")
endif()

if(LUNAR_C_FFT)
    file(GLOB_RECURSE lunar-source
        LIST_DIRECTORIES FALSE
        CONFIGURE_DEPENDS
        ${CMAKE_SOURCE_DIR}/Source/**
    )
else()
    # No FFI, no need for 'Source/FFI/*.c' to be globbed in
    file(GLOB lunar-source
        LIST_DIRECTORIES FALSE
        CONFIGURE_DEPENDS
        ${CMAKE_SOURCE_DIR}/Source/*.cpp)
endif()

file(GLOB_RECURSE lunar-headers
    LIST_DIRECTORIES FALSE
    CONFIGURE_DEPENDS
    ${CMAKE_SOURCE_DIR}/Include/*.hpp
)