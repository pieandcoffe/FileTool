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
class FILE_OPS_API FileOps {
public:
    /**
     * @brief Constructs a FileOps object for the given path.
     * @param path The file path to operate on.
     */
    explicit FileOps(const std::filesystem::path& path);

    // Rule of five (needed because of unique_ptr)

    // Default virtual destructor
    virtual ~FileOps();

    // Non-copyable
    FileOps(const FileOps&) = delete;
    FileOps& operator=(const FileOps&) = delete;

    // Movable
    FileOps(FileOps&&) noexcept = default;
    FileOps& operator=(FileOps&&) noexcept = default;
    
    /**
     * @brief Checks if the file exists.
     * @return True if the file exists, false otherwise.
     */
    [[nodiscard]]
    bool exists() const;

    // Basic file operations

    /**
     * @brief Copies the file to a destination.
     * @param destination The target path.
     * @param overwrite If true, overwrites the destination file if it exists.
     * @return True if copy was successful, false otherwise.
     */
    [[nodiscard]]
    bool copyTo(const std::filesystem::path& destination, bool overwrite = false) const;

    /**
     * @brief Moves the file to a destination.
     * @param destination The target path.
     * @param overwrite If true, overwrites the destination file if it exists.
     * @return True if move was successful, false otherwise.
     */
    [[nodiscard]]
    bool moveTo(const std::filesystem::path& destination, bool overwrite = false) const;

    /**
     * @brief Renames the file.
     * @param newName The new name for the file.
     * @return True if rename was successful, false otherwise.
     */
    bool rename(const std::string& newName);

    /**
     * @brief Removes the file.
     * @return True if removal was successful, false otherwise.
     */
    bool remove();

    // Optional file content operations

    /**
     * @brief Reads the file as text.
     * @return File contents as a string.
     */
    [[nodiscard]]
    std::string readText() const;

    /**
     * @brief Reads the file as binary data.
     * @return File contents as a vector of bytes.
     */
    [[nodiscard]]
    std::vector<uint8_t> readBinary() const;

    /**
     * @brief Writes text content to the file.
     * @param content The text to write.
     * @param overwrite If true, overwrites the file if it exists.
     * @return True if write was successful, false otherwise.
     */
    [[nodiscard]]
    bool writeText(const std::string& content, bool overwrite = true) const;

    /**
     * @brief Writes binary data to the file.
     * @param data The binary data to write.
     * @param overwrite If true, overwrites the file if it exists.
     * @return True if write was successful, false otherwise.
     */
    [[nodiscard]]
    bool writeBinary(const std::vector<uint8_t>& data, bool overwrite = true) const;

protected:
    [[nodiscard]]
    std::filesystem::path path() const;

private:
    class Impl;

    /**
     * @brief The underlying file path.
     */
    std::unique_ptr<Impl> m_impl;
};

#endif // FILETOOL_FILEOPS_HPP