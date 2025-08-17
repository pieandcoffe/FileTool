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

    // Rule of five (needed because of unique_ptr)

    // Default virtual destructor
    virtual ~PathInfo();

    // Non-copyable
    PathInfo(const PathInfo&) = delete;
    PathInfo& operator=(const PathInfo&) = delete;

    // Movable
    PathInfo(PathInfo&&) noexcept = default;
    PathInfo& operator=(PathInfo&&) noexcept = default;

    /**
     * @brief Checks if the path exists in the filesystem.
     * @return True if the path exists, false otherwise.
     */
    [[nodiscard]]
    bool exists() const;

    /**
     * @brief Checks if the path refers to a regular file.
     * @return True if the path is a file, false otherwise.
     */
    [[nodiscard]]
    bool isFile() const;

    /**
     * @brief Checks if the path refers to a directory.
     * @return True if the path is a directory, false otherwise.
     */
    [[nodiscard]]
    bool isDirectory() const;

    /**
     * @brief Checks if the path is a symbolic link.
     * @return True if the path is a symbolic link, false otherwise.
     */
    [[nodiscard]]
    bool isSymLink() const;

    /**
     * @brief Gets the filename component of the path.
     * @return The filename as a string.
     */
    [[nodiscard]]
    std::string filename() const;

    /**
     * @brief Gets the file extension of the path.
     * @return The extension as a string.
     */
    [[nodiscard]]
    std::string extension() const;

    /**
     * @brief Gets the parent directory of the path.
     * @return The parent path.
     */
    [[nodiscard]]
    std::filesystem::path parentPath() const;

    /**
     * @brief Gets the permissions of the path.
     * @return The permissions as a std::filesystem::perms value.
     */
    [[nodiscard]]
    std::filesystem::perms permissions() const;

protected:
    /// Accessor for derived classes
    [[nodiscard]]
    const std::filesystem::path& path() const;

private:
    class Impl;
    std::unique_ptr<Impl> m_impl;
};

#endif // FILETOOL_PATHINFO_HPP