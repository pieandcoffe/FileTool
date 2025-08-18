//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#include "PathInfo.hpp"
#include <filesystem>

class PathInfo::PathInfoImpl {
public:
    explicit PathInfoImpl(const std::filesystem::path& p)
        : m_path(std::filesystem::canonical(p)) {}

    std::filesystem::path m_path;
};

PathInfo::PathInfo(const std::filesystem::path &p)
    : m_impl(std::make_unique<PathInfoImpl>(p)) {}

PathInfo::~PathInfo() = default;

PathInfo::PathInfo(PathInfo &&) noexcept = default;
PathInfo & PathInfo::operator=(PathInfo &&) noexcept = default;

bool PathInfo::exists() const {
    return std::filesystem::exists(path());
}

bool PathInfo::isFile() const {
    return std::filesystem::is_regular_file(path());
}

bool PathInfo::isDirectory() const {
    return std::filesystem::is_directory(path());
}

bool PathInfo::isSymLink() const {
    return std::filesystem::is_symlink(path());
}

std::string PathInfo::filename() const {
    return path().filename().string();
}

std::string PathInfo::extension() const {
    return path().extension().string();
}

std::filesystem::path PathInfo::parentPath() const {
    return path().parent_path();
}

std::filesystem::perms PathInfo::permissions() const {
    std::error_code ec;
    return std::filesystem::status(path(), ec).permissions();
}

const std::filesystem::path & PathInfo::path() const {
    return m_impl->m_path;
}
