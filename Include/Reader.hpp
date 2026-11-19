/*
 * Include/Reader.hpp
 *
 * Intakes script files from FS and does the most basic of
 * processing to ensure the basic syntax of Lua is valid.
 * Since this only cares if the Lua in the file is correct,
 * we don't worry about things like file extensions or flags.
 * (unless those flags cause us grief)
 *
 * SPDX-License-Identifier: zlib
 */

#pragma once

#include <cstdint>
#include <filesystem>
#include <string_view>
#include <fstream>
#include <iostream>
#include <iterator>
#include <cstring>

#include "Utility.hpp"

struct LuaFile {
    std::uint32_t lineCount;
    char* fileContent;
};

// Intakes a string_view path, ensures file existence and loads it to the struct.
FFI L_EXPORT LuaFile* readFromFilesystem(const char* path);

// Frees the file, which cannot be done by the end-user because C/C++ don't mix!
FFI L_EXPORT void freeLuaFile(LuaFile* file);

// Produces the entirety of the source code from the file passed in.
FFI L_EXPORT const char* dumpContents(LuaFile* file);