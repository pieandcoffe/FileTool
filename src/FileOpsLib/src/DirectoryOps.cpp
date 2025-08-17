//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#include "DirectoryOps.hpp"
#include <filesystem>
#include <system_error>

DirectoryOps::DirectoryOps(const std::filesystem::path& path)
    : m_path(path) {}

bool DirectoryOps::exists() const {
    return std::filesystem::exists(m_path);
}

bool DirectoryOps::create(bool recursive) {
    std::error_code ec;
    if (recursive)
        return std::filesystem::create_directories(m_path, ec);
    else
        return std::filesystem::create_directory(m_path, ec);
}

bool DirectoryOps::remove(bool recursive) {
    std::error_code ec;
    if (recursive)
        return std::filesystem::remove_all(m_path, ec) > 0;
    else
        return std::filesystem::remove(m_path, ec);
}

bool DirectoryOps::empty() {
    std::error_code ec;
    if (!std::filesystem::is_directory(m_path, ec)) return false;
    for (const auto& entry : std::filesystem::directory_iterator(m_path, ec)) {
        std::filesystem::remove_all(entry.path(), ec);
    }
    return true;
}

bool DirectoryOps::copyTo(const std::filesystem::path& destination, bool recursive, bool overwrite) {
    std::error_code ec;
    if (!exists()) return false;
    if (recursive) {
        std::filesystem::copy(m_path, destination,
            overwrite ? std::filesystem::copy_options::recursive | std::filesystem::copy_options::overwrite_existing
                      : std::filesystem::copy_options::recursive,
            ec);
    } else {
        std::filesystem::copy(m_path, destination,
            overwrite ? std::filesystem::copy_options::overwrite_existing
                      : std::filesystem::copy_options::none,
            ec);
    }
    return !ec;
}

bool DirectoryOps::moveTo(const std::filesystem::path& destination, bool overwrite) {
    std::error_code ec;
    if (overwrite && std::filesystem::exists(destination, ec)) {
        std::filesystem::remove_all(destination, ec);
    }
    std::filesystem::rename(m_path, destination, ec);
    return !ec;
}