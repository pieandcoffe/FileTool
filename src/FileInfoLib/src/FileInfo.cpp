//
// Created by Kyrylo Pylinskyi on 15/08/2025.
//

#include "FileInfo.hpp"
#include <filesystem>
#include <fstream>
#include <sstream>
#include <iomanip>

FileInfo::FileInfo(const std::filesystem::path &p) : PathInfo(p) {
}

uintmax_t FileInfo::size() const {
    std::error_code ec;
    return std::filesystem::is_regular_file(m_path) ? std::filesystem::file_size(m_path, ec) : 0;
}

std::string FileInfo::sizeHumanReadable() const {
    uintmax_t bytes = size();
    static const char* sizes[] = { "B", "KB", "MB", "GB", "TB" };
    int order = 0;
    double len = static_cast<double>(bytes);
    while (len >= 1024 && order < 4) {
        order++;
        len /= 1024;
    }
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << len << " " << sizes[order];
    return oss.str();
}

std::chrono::system_clock::time_point FileInfo::creationTime() const {
    std::error_code ec;
    if (!std::filesystem::exists(m_path)) {
        return std::chrono::system_clock::time_point{};
    }

    auto ftime = std::filesystem::last_write_time(m_path, ec);

    // Convert to system_clock::time_point
    return std::chrono::time_point_cast<std::chrono::system_clock::duration>(
        ftime - decltype(ftime)::clock::now() + std::chrono::system_clock::now()
    );
}

std::chrono::system_clock::time_point FileInfo::lastModifiedTime() const {
    std::error_code ec;
    if (!std::filesystem::exists(m_path)) {
        return std::chrono::system_clock::time_point{};
    }

    auto ftime = std::filesystem::last_write_time(m_path, ec);

    return std::chrono::time_point_cast<std::chrono::system_clock::duration>(
        ftime - decltype(ftime)::clock::now() + std::chrono::system_clock::now()
    );
}


std::chrono::system_clock::time_point FileInfo::lastAccessedTime() const {
    // Not portable: std::filesystem does not provide last access time in C++17
    return std::chrono::system_clock::time_point{};
}

std::string FileInfo::mimeType() const {
    // Not portable: C++17 std::filesystem does not provide MIME type
    // You may use platform-specific code or external libraries
    return {};
}