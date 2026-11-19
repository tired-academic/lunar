/*
 * Source/Reader.cpp
 *
 * Implementation of the intake process, reading in files and producing
 * structs the program can actually recognize. 
 */

#include "Reader.hpp"

FFI L_EXPORT LuaFile* readFromFilesystem(const char* path) {
    if (!path) return nullptr;

    std::filesystem::path actualPath = std::string(path);

    std::ifstream istream(actualPath, std::ios::binary);
    if (!istream) {
        std::cerr << "Unable to open file '" << path << "'\n";
        return nullptr;
    }

    std::string fileContent(
        (std::istreambuf_iterator<char>(istream)),
        std::istreambuf_iterator<char>()
    );

    if (!istream.bad()) {
        std::cerr << "Unable to read file: '" << path << "'\n";
        return nullptr;
    }

    std::uint32_t lineCount = 0;

    for (char c : fileContent) {
        if (c == '\n') ++lineCount;
    }

    if (!fileContent.empty() && fileContent.back() != '\n') {
        ++lineCount;
    }

    auto* f = new LuaFile{};
    f->lineCount = lineCount;
    f->fileContent = new char[fileContent.size() + 1];

    std::memcpy(f->fileContent, fileContent.data(), fileContent.size());
    f->fileContent[fileContent.size()] = '\0';

    return f;
}

FFI L_EXPORT void freeLuaFile(LuaFile* file) {
    if (!file) return;
    delete[] file->fileContent;
    delete file;
}

FFI L_EXPORT const char* dumpContents(const LuaFile* file) {
    return file ? file->fileContent : nullptr;
}