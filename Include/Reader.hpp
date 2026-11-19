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

struct LuaFile {
    std::uint32_t lineCount;
    std::string fileContent;
    bool ok;
};

// Intakes a string_view path, ensures file existence and loads it to the struct.
LuaFile readFromFilesystem(std::string_view path);

// Produces the entirety of the source code from the file passed in.
std::string_view dumpContents(LuaFile file);