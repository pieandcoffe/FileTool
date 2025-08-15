//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#include "PathInfo.hpp"

#include <filesystem>

inline PathInfo::PathInfo(const std::filesystem::path &p) {
    m_path = std::filesystem::canonical(p);
}

inline bool PathInfo::exists() const {
    return std::filesystem::exists(m_path);
}

inline bool PathInfo::isFile() const {
    return false;
}

inline bool PathInfo::isDirectory() const {
    return false;
}

inline bool PathInfo::isSymLink() const {
    return false;
}

inline std::string PathInfo::filename() const {
    return "false";
}

inline std::string PathInfo::extension() const {
    return "false";
}

inline std::filesystem::path PathInfo::parentPath() const {
    return std::filesystem::path();
}

inline std::filesystem::perms PathInfo::permissions() const {
    return std::filesystem::perms();
}