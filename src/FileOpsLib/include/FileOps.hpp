//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#ifndef FILETOOL_FILEOPS_HPP
#define FILETOOL_FILEOPS_HPP

#include "FileOpsAPI.hpp"
#include <filesystem>
#include <string>
#include <vector>

/**
 * @class FileOps
 * @brief Provides basic and advanced file operations, including copying, moving, renaming, reading, and writing.
 */
class FileOps {
public:
    /**
     * @brief Constructs a FileOps object for the given path.
     * @param path The file path to operate on.
     */
    FILE_OPS_API explicit FileOps(const std::filesystem::path& path);

    // Rule of five (needed because of unique_ptr)

    // Default virtual destructor
    FILE_OPS_API virtual ~FileOps();

    // Non-copyable
    FILE_OPS_API FileOps(const FileOps&) = delete;
    FILE_OPS_API FileOps& operator=(const FileOps&) = delete;

    // Movable
    FILE_OPS_API FileOps(FileOps&&) noexcept = default;
    FILE_OPS_API FileOps& operator=(FileOps&&) noexcept = default;

    /**
     * @brief Checks if the file exists.
     * @return True if the file exists, false otherwise.
     */
    [[nodiscard]]
    FILE_OPS_API bool exists() const;

    // Basic file operations

    /**
     * @brief Copies the file to a destination.
     * @param destination The target path.
     * @param overwrite If true, overwrites the destination file if it exists.
     * @return True if copy was successful, false otherwise.
     */
    [[nodiscard]]
    FILE_OPS_API bool copyTo(const std::filesystem::path& destination, bool overwrite = false) const;

    /**
     * @brief Moves the file to a destination.
     * @param destination The target path.
     * @param overwrite If true, overwrites the destination file if it exists.
     * @return True if move was successful, false otherwise.
     */
    [[nodiscard]]
    FILE_OPS_API bool moveTo(const std::filesystem::path& destination, bool overwrite = false) const;

    /**
     * @brief Renames the file.
     * @param newName The new name for the file.
     * @return True if rename was successful, false otherwise.
     */
    FILE_OPS_API bool rename(const std::string& newName);

    /**
     * @brief Removes the file.
     * @return True if removal was successful, false otherwise.
     */
    FILE_OPS_API bool remove();

    // Optional file content operations

    /**
     * @brief Reads the file as text.
     * @return File contents as a string.
     */
    [[nodiscard]]
    FILE_OPS_API std::string readText() const;

    /**
     * @brief Reads the file as binary data.
     * @return File contents as a vector of bytes.
     */
    [[nodiscard]]
    FILE_OPS_API std::vector<uint8_t> readBinary() const;

    /**
     * @brief Writes text content to the file.
     * @param content The text to write.
     * @param overwrite If true, overwrites the file if it exists.
     * @return True if write was successful, false otherwise.
     */
    [[nodiscard]]
    FILE_OPS_API bool writeText(const std::string& content, bool overwrite = true) const;

    /**
     * @brief Writes binary data to the file.
     * @param data The binary data to write.
     * @param overwrite If true, overwrites the file if it exists.
     * @return True if write was successful, false otherwise.
     */
    [[nodiscard]]
    FILE_OPS_API bool writeBinary(const std::vector<uint8_t>& data, bool overwrite = true) const;

protected:
    [[nodiscard]]
    FILE_OPS_API std::filesystem::path path() const;

private:
    struct FileOpsImpl;

    std::unique_ptr<FileOpsImpl> m_impl;
};

#endif // FILETOOL_FILEOPS_HPP