//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#ifndef FILETOOL_DIRECTORYOPS_HPP
#define FILETOOL_DIRECTORYOPS_HPP

#include <filesystem>
#include "FileOpsAPI.hpp"

/**
 * @class DirectoryOps
 * @brief Provides operations for manipulating directories, such as creation, removal, copying, and moving.
 */
class FILE_OPS_API DirectoryOps {
public:
    /**
     * @brief Constructs a DirectoryOps object for the given path.
     * @param path The directory path to operate on.
     */
    explicit DirectoryOps(const std::filesystem::path& path);

    /**
     * @brief Checks if the directory exists.
     * @return True if the directory exists, false otherwise.
     */
    bool exists() const;

    /**
     * @brief Creates the directory.
     * @param recursive If true, creates parent directories as needed.
     * @return True if creation was successful, false otherwise.
     */
    bool create(bool recursive = true);

    /**
     * @brief Removes the directory and all its contents.
     * @param recursive If true, removes all contents recursively.
     * @return True if removal was successful, false otherwise.
     */
    bool remove(bool recursive = true);

    /**
     * @brief Removes all contents but keeps the directory itself.
     * @return True if the directory was emptied successfully, false otherwise.
     */
    bool empty();

    /**
     * @brief Copies the directory to a destination.
     * @param destination The target path.
     * @param recursive If true, copies contents recursively.
     * @param overwrite If true, overwrites existing files.
     * @return True if copy was successful, false otherwise.
     */
    bool copyTo(const std::filesystem::path& destination, bool recursive = true, bool overwrite = false);

    /**
     * @brief Moves the directory to a destination.
     * @param destination The target path.
     * @param overwrite If true, overwrites existing files.
     * @return True if move was successful, false otherwise.
     */
    bool moveTo(const std::filesystem::path& destination, bool overwrite = false);

private:
    /**
     * @brief The underlying directory path.
     */
    std::filesystem::path m_path;
};

#endif // FILETOOL_DIRECTORYOPS_HPP