//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#ifndef FILETOOL_PATHINFO_HPP
#define FILETOOL_PATHINFO_HPP

#include <filesystem>
#include <memory>

#include "FileInfoAPI.hpp"

/**
 * @class PathInfo
 * @brief Provides information and utilities for a filesystem path.
 */
class FILE_INFO_API PathInfo {
public:
    /**
     * @brief Constructs a PathInfo object with the given path.
     * @param p The filesystem path to be managed.
     */
    explicit PathInfo(const std::filesystem::path &p);

    /**
     * @brief Checks if the path exists in the filesystem.
     * @return True if the path exists, false otherwise.
     */
    bool exists() const;

    /**
     * @brief Checks if the path refers to a regular file.
     * @return True if the path is a file, false otherwise.
     */
    bool isFile() const;

    /**
     * @brief Checks if the path refers to a directory.
     * @return True if the path is a directory, false otherwise.
     */
    bool isDirectory() const;

    /**
     * @brief Checks if the path is a symbolic link.
     * @return True if the path is a symbolic link, false otherwise.
     */
    bool isSymLink() const;

    /**
     * @brief Gets the filename component of the path.
     * @return The filename as a string.
     */
    std::string filename() const;

    /**
     * @brief Gets the file extension of the path.
     * @return The extension as a string.
     */
    std::string extension() const;

    /**
     * @brief Gets the parent directory of the path.
     * @return The parent path.
     */
    std::filesystem::path parentPath() const;

    /**
     * @brief Gets the permissions of the path.
     * @return The permissions as a std::filesystem::perms value.
     */
    std::filesystem::perms permissions() const;

protected:
    /**
     * @brief The underlying filesystem path.
     */
    std::unique_ptr<std::filesystem::path> m_pPath;
};

#endif // FILETOOL_PATHINFO_HPP