//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#ifndef FILETOOL_PATHOPS_HPP
#define FILETOOL_PATHOPS_HPP
#include <filesystem>

class PathOps {
public:
    static std::filesystem::path join(const std::filesystem::path& base, const std::filesystem::path& relative);
    static bool isWritable(const std::filesystem::path& path);
    static bool isReadable(const std::filesystem::path& path);

    static bool copyFiles(const std::vector<std::filesystem::path>& files, const std::filesystem::path& destination, bool overwrite = false);
    static bool removeFiles(const std::vector<std::filesystem::path>& files);
};

#endif //FILETOOL_PATHOPS_HPP