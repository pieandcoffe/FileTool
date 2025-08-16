//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#ifndef FILETOOL_FILEOPS_HPP
#define FILETOOL_FILEOPS_HPP

#include "FileOpsAPI.hpp"

#include <filesystem>
#include <string>
#include <vector>


class FILE_OPS_API FileOps {
public:
    explicit FileOps(const std::filesystem::path& path);

    bool exists() const;

    // Basic file operations
    bool copyTo(const std::filesystem::path& destination, bool overwrite = false) const;
    bool moveTo(const std::__fs::filesystem::path& destination, bool overwrite = false) const;
    bool rename(const std::string& newName);
    bool remove();

    // Optional file content operations
    std::string readText() const;
    std::vector<uint8_t> readBinary() const;
    bool writeText(const std::string& content, bool overwrite = true) const;
    bool writeBinary(const std::vector<uint8_t>& data, bool overwrite = true) const;

private:
    std::filesystem::path m_path;
};


#endif //FILETOOL_FILEOPS_HPP