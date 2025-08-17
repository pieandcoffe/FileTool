//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#include "PathInfo.hpp"
#include <filesystem>

PathInfo::PathInfo(const std::filesystem::path &p) {
    m_path = std::filesystem::canonical(p);
}

bool PathInfo::exists() const {
    return std::filesystem::exists(m_path);
}

bool PathInfo::isFile() const {
    return std::filesystem::is_regular_file(m_path);
}

bool PathInfo::isDirectory() const {
    return std::filesystem::is_directory(m_path);
}

bool PathInfo::isSymLink() const {
    return std::filesystem::is_symlink(m_path);
}

std::string PathInfo::filename() const {
    return m_path.filename().string();
}

std::string PathInfo::extension() const {
    return m_path.extension().string();
}

std::filesystem::path PathInfo::parentPath() const {
    return m_path.parent_path();
}

std::filesystem::perms PathInfo::permissions() const {
    std::error_code ec;
    return std::filesystem::status(m_path, ec).permissions();
}