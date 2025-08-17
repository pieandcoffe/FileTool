//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#include "PathUtils.hpp"
#include <sstream>
#include <iomanip>

std::string PathUtils::humanReadableSize(uintmax_t bytes) {
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

std::string PathUtils::normalizeSeparators(const std::string &path) {
    std::string normalized = path;
#ifdef _WIN32
    std::replace(normalized.begin(), normalized.end(), '/', '\\');
#else
    std::replace(normalized.begin(), normalized.end(), '\\', '/');
#endif
    return normalized;
}

std::filesystem::path PathUtils::join(const std::filesystem::path &base, const std::filesystem::path &relative) {
    return base / relative;
}