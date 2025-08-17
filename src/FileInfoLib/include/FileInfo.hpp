//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#ifndef FILETOOL_FILEINFO_HPP
#define FILETOOL_FILEINFO_HPP

#include <chrono>

#include "FileInfoAPI.hpp"
#include "PathInfo.hpp"

/**
 * @class FileInfo
 * @brief Provides utilities for file inspection and metadata.
 */
class FILE_INFO_API FileInfo : public PathInfo {
public:
    /**
     * @brief Default constructor.
     */
    FileInfo(const std::filesystem::path &p);

    /**
     * @brief Gets the size of the file in bytes.
     * @return File size in bytes.
     */
    uintmax_t size() const;

    /**
     * @brief Gets the file size in a human-readable format (e.g., "1.2 MB").
     * @return File size as a string.
     */
    std::string sizeHumanReadable() const;

    /**
     * @brief Gets the creation time of the file.
     * @return Creation time as a std::chrono::system_clock::time_point.
     */
    std::chrono::system_clock::time_point creationTime() const;

    /**
     * @brief Gets the last modification time of the file.
     * @return Last modified time as a std::chrono::system_clock::time_point.
     */
    std::chrono::system_clock::time_point lastModifiedTime() const;

    /**
     * @brief Gets the last accessed time of the file.
     * @return Last accessed time as a std::chrono::system_clock::time_point.
     */
    std::chrono::system_clock::time_point lastAccessedTime() const;

    /**
     * @brief Calculates the SHA-256 checksum of the file.
     * @return SHA-256 checksum as a string.
     */
    std::string checksumSHA256() const;

    /**
     * @brief Gets the MIME type of the file.
     * @return MIME type as a string.
     */
    std::string mimeType() const;
};

#endif // FILETOOL_FILEINFO_HPP