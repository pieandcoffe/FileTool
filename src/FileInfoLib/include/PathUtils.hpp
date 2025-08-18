//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#ifndef FILETOOL_PATHUTILS_HPP
#define FILETOOL_PATHUTILS_HPP

#include <filesystem>
#include <string>

#include "FileInfoAPI.hpp"

/**
 * @class PathUtils
 * @brief Provides static utility functions for filesystem path manipulation.
 */
class PathUtils {
public:
    /**
     * @brief Converts a file size in bytes to a human-readable string (e.g., "1.2 MB").
     * @param bytes File size in bytes.
     * @return Human-readable file size string.
     */
    FILE_INFO_API static std::string humanReadableSize(uintmax_t bytes);

    /**
     * @brief Normalizes path separators to the platform's default.
     * @param path The input path as a string.
     * @return The normalized path string.
     */
    FILE_INFO_API static std::string normalizeSeparators(const std::string &path);

    /**
     * @brief Joins a base path and a relative path into a single path.
     * @param base The base filesystem path.
     * @param relative The relative filesystem path.
     * @return The joined filesystem path.
     */
    FILE_INFO_API static std::filesystem::path join(const std::filesystem::path &base, const std::filesystem::path &relative);
};

#endif