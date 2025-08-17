//
// Created by Kyrylo Pylinskyi on 15/08/2025.
//

#include "DirectoryInfo.hpp"
#include <iterator>
#include <algorithm>
#include <numeric>
#include <fstream>

DirectoryInfo::DirectoryInfo(const std::filesystem::path &p) : PathInfo(p) {
}

std::vector<std::filesystem::path> DirectoryInfo::listEntries(bool recursive) const {
    std::vector<std::filesystem::path> entries;
    if (!isDirectory()) return entries;

    if (recursive) {
        for (const auto &entry: std::filesystem::recursive_directory_iterator(m_path)) {
            entries.push_back(entry.path());
        }
    } else {
        for (const auto &entry: std::filesystem::directory_iterator(m_path)) {
            entries.push_back(entry.path());
        }
    }
    return entries;
}

std::vector<std::filesystem::path> DirectoryInfo::listFiles(bool recursive) const {
    std::vector<std::filesystem::path> files;
    auto entries = listEntries(recursive);
    for (const auto &entry: entries) {
        if (std::filesystem::is_regular_file(entry)) {
            files.push_back(entry);
        }
    }
    return files;
}

std::vector<std::filesystem::path> DirectoryInfo::listDirectories(bool recursive) const {
    std::vector<std::filesystem::path> dirs;
    const auto entries = listEntries(recursive);
    for (const auto &entry: entries) {
        if (std::filesystem::is_directory(entry)) {
            dirs.push_back(entry);
        }
    }
    return dirs;
}

size_t DirectoryInfo::fileCount(bool recursive) const {
    return listFiles(recursive).size();
}

size_t DirectoryInfo::directoryCount(bool recursive) const {
    return listDirectories(recursive).size();
}

uintmax_t DirectoryInfo::totalSize(bool recursive) const {
    uintmax_t total = 0;
    auto files = listFiles(recursive);
    for (const auto &file: files) {
        std::error_code ec;
        total += std::filesystem::file_size(file, ec);
    }
    return total;
}
