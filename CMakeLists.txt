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

option(LUNAR_C_FFI "Enables a C-friendly FFI." ON)