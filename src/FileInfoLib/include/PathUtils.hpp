//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#ifndef FILETOOL_PATHUTILS_HPP
#define FILETOOL_PATHUTILS_HPP

#include "FileInfoAPI.hpp"

#include <filesystem>
#include <string>

class FILE_INFO_API PathUtils {
public:
    static std::string humanReadableSize(uintmax_t bytes);

    static std::string normalizeSeparators(const std::string &path);

    static std::filesystem::path join(const std::filesystem::path &base, const std::filesystem::path &relative);
};


#endif //FILETOOL_PATHUTILS_HPP
