//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#ifndef FILETOOL_DIRECTORYINFO_HPP
#define FILETOOL_DIRECTORYINFO_HPP

#include "FileInfoAPI.hpp"

#include "PathInfo.hpp"

class FILE_INFO_API DirectoryInfo : PathInfo {
public:
    std::vector<std::filesystem::path> listEntries(bool recursive = false) const;

    std::vector<std::filesystem::path> listFiles(bool recursive = false) const;

    std::vector<std::filesystem::path> listDirectories(bool recursive = false) const;

    size_t fileCount(bool recursive = false) const;

    size_t directoryCount(bool recursive = false) const;

    uintmax_t totalSize(bool recursive = false) const;
};

#endif //FILETOOL_DIRECTORYINFO_HPP
