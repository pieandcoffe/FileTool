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
class PathInfo {
public:
    /**
     * @brief Constructs a PathInfo object with the given path.
     * @param p The filesystem path to be managed.
     */
    FILE_INFO_API explicit PathInfo(const std::filesystem::path &p);

    // Rule of five (needed because of unique_ptr)

    // Default virtual destructor
    FILE_INFO_API virtual ~PathInfo();

    // Non-copyable
    FILE_INFO_API PathInfo(const PathInfo&) = delete;
    FILE_INFO_API PathInfo& operator=(const PathInfo&) = delete;

    // Movable
    FILE_INFO_API PathInfo(PathInfo&&) noexcept = default;
    FILE_INFO_API PathInfo& operator=(PathInfo&&) noexcept = default;

    /**
     * @brief Checks if the path exists in the filesystem.
     * @return True if the path exists, false otherwise.
     */
    [[nodiscard]]
    FILE_INFO_API bool exists() const;

    /**
     * @brief Checks if the path refers to a regular file.
     * @return True if the path is a file, false otherwise.
     */
    [[nodiscard]]
    FILE_INFO_API bool isFile() const;

    /**
     * @brief Checks if the path refers to a directory.
     * @return True if the path is a directory, false otherwise.
     */
    [[nodiscard]]
    FILE_INFO_API bool isDirectory() const;

    /**
     * @brief Checks if the path is a symbolic link.
     * @return True if the path is a symbolic link, false otherwise.
     */
    [[nodiscard]]
    FILE_INFO_API bool isSymLink() const;

    /**
     * @brief Gets the filename component of the path.
     * @return The filename as a string.
     */
    [[nodiscard]]
    FILE_INFO_API std::string filename() const;

    /**
     * @brief Gets the file extension of the path.
     * @return The extension as a string.
     */
    [[nodiscard]]
    FILE_INFO_API std::string extension() const;

    /**
     * @brief Gets the parent directory of the path.
     * @return The parent path.
     */
    [[nodiscard]]
    FILE_INFO_API std::filesystem::path parentPath() const;

    /**
     * @brief Gets the permissions of the path.
     * @return The permissions as a std::filesystem::perms value.
     */
    [[nodiscard]]
    FILE_INFO_API std::filesystem::perms permissions() const;

protected:
    /// Accessor for derived classes
    [[nodiscard]]
    FILE_INFO_API const std::filesystem::path& path() const;

private:
    struct PathInfoImpl;

    std::unique_ptr<PathInfoImpl> m_impl;
};

#endif // FILETOOL_PATHINFO_HPP
