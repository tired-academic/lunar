# Lunar is a C++ implementation of the Lua programming language
# (C) 2026 tired-academic
# SPDX-License-Identifier: zlib

cmake_minimum_required(VERSION 3.28)
project(
    Lunar
    LANGUAGES C CXX
    VERSION 0.0.1
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR)
    message(FATAL_ERROR "In-source builds are not supported!")
endif()

option(LUNAR_C_FFI "Enables a C-friendly FFI for use in C-family projects. (unused)" ON)
option(LUNAR_LUA_INTERPRETER "Builds Lunar as a binary interpreter for Lua. (unused)" OFF)

file(GLOB lunar-source
    CONFIGURE_DEPENDS
    LIST_DIRECTORIES FALSE
    ${CMAKE_SOURCE_DIR}/Source/*.cpp
    ${CMAKE_SOURCE_DIR}/Source/*.c
)

file(GLOB lunar-headers
    CONFIGURE_DEPENDS
    LIST_DIRECTORIES FALSE
    ${CMAKE_SOURCE_DIR}/Include/*.hpp
    ${CMAKE_SOURCE_DIR}/Include/*.h
)

add_library(Lunar SHARED ${lunar-source} ${lunar-headers})

target_include_directories(Lunar PUBLIC
    ${CMAKE_SOURCE_DIR}/Include
)

target_compile_features(Lunar PUBLIC cxx_std_20)