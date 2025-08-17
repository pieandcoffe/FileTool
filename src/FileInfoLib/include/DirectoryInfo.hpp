//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#ifndef FILETOOL_DIRECTORYINFO_HPP
#define FILETOOL_DIRECTORYINFO_HPP

#include <vector>
#include <filesystem>

#include "FileInfoAPI.hpp"
#include "PathInfo.hpp"

/**
 * @class DirectoryInfo
 * @brief Provides utilities for directory inspection and statistics.
 */
class FILE_INFO_API DirectoryInfo : public PathInfo {
public:
    DirectoryInfo(const std::filesystem::path &p);
    
    /**
     * @brief Lists all entries (files and directories) in the directory.
     * @param recursive If true, lists entries recursively.
     * @return Vector of paths to all entries.
     */
    std::vector<std::filesystem::path> listEntries(bool recursive = false) const;

    /**
     * @brief Lists all files in the directory.
     * @param recursive If true, lists files recursively.
     * @return Vector of paths to all files.
     */
    std::vector<std::filesystem::path> listFiles(bool recursive = false) const;

    /**
     * @brief Lists all directories in the directory.
     * @param recursive If true, lists directories recursively.
     * @return Vector of paths to all directories.
     */
    std::vector<std::filesystem::path> listDirectories(bool recursive = false) const;

    /**
     * @brief Counts the number of files in the directory.
     * @param recursive If true, counts files recursively.
     * @return Number of files.
     */
    size_t fileCount(bool recursive = false) const;

    /**
     * @brief Counts the number of directories in the directory.
     * @param recursive If true, counts directories recursively.
     * @return Number of directories.
     */
    size_t directoryCount(bool recursive = false) const;

    /**
     * @brief Calculates the total size of all files in the directory.
     * @param recursive If true, includes files in subdirectories.
     * @return Total size in bytes.
     */
    uintmax_t totalSize(bool recursive = false) const;
};

#endif // FILETOOL_DIRECTORYINFO_HPP