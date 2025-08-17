//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#ifndef FILETOOL_PATHOPS_HPP
#define FILETOOL_PATHOPS_HPP

#include "FileOpsAPI.hpp"
#include <filesystem>
#include <vector>

/**
 * @class PathOps
 * @brief Provides static utility functions for filesystem path operations.
 */
class FILE_OPS_API PathOps {
public:
    /**
     * @brief Joins a base path and a relative path into a single path.
     * @param base The base filesystem path.
     * @param relative The relative filesystem path.
     * @return The joined filesystem path.
     */
    static std::filesystem::path join(const std::filesystem::path& base, const std::filesystem::path& relative);

    /**
     * @brief Checks if the path is writable.
     * @param path The filesystem path to check.
     * @return True if writable, false otherwise.
     */
    static bool isWritable(const std::filesystem::path& path);

    /**
     * @brief Checks if the path is readable.
     * @param path The filesystem path to check.
     * @return True if readable, false otherwise.
     */
    static bool isReadable(const std::filesystem::path& path);

    /**
     * @brief Copies multiple files to a destination directory.
     * @param files Vector of file paths to copy.
     * @param destination The target directory.
     * @param overwrite If true, overwrites existing files.
     * @return True if all files were copied successfully, false otherwise.
     */
    static bool copyFiles(const std::vector<std::filesystem::path>& files, const std::filesystem::path& destination, bool overwrite = false);

    /**
     * @brief Removes multiple files.
     * @param files Vector of file paths to remove.
     * @return True if all files were removed successfully, false otherwise.
     */
    static bool removeFiles(const std::vector<std::filesystem::path>& files);
};

#endif // FILETOOL_PATHOPS_HPP