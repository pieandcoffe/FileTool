//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#include "PathOps.hpp"
#include <fstream>

std::filesystem::path PathOps::join(const std::filesystem::path& base, const std::filesystem::path& relative) {
    return base / relative;
}

bool PathOps::isWritable(const std::filesystem::path& path) {
    try {
        // If path is a directory → test by trying to create a temp file inside
        if (std::filesystem::is_directory(path)) {
            auto testFile = path / ".writetest.tmp";
            std::ofstream file(testFile);
            if (file.is_open()) {
                file.close();
                std::filesystem::remove(testFile);
                return true;
            }
            return false;
        }

        // If path is a file → try opening it for append
        std::ofstream file(path, std::ios::app);
        return file.is_open();
    } catch (...) {
        return false;
    }
}

bool PathOps::isReadable(const std::filesystem::path& path) {
    try {
        std::ifstream file(path);
        return file.is_open();
    } catch (...) {
        return false;
    }
}

bool PathOps::copyFiles(const std::vector<std::filesystem::path>& files,
                        const std::filesystem::path& destination,
                        bool overwrite) {
    try {
        if (!std::filesystem::exists(destination) || !std::filesystem::is_directory(destination)) {
            return false;
        }

        for (const auto& f : files) {
            if (!std::filesystem::exists(f)) {
                return false;
            }

            auto dest = destination / f.filename();
            if (overwrite) {
                std::filesystem::copy_file(f, dest, std::filesystem::copy_options::overwrite_existing);
            } else {
                std::filesystem::copy_file(f, dest, std::filesystem::copy_options::skip_existing);
            }
        }
        return true;
    } catch (...) {
        return false;
    }
}

bool PathOps::removeFiles(const std::vector<std::filesystem::path>& files) {
    try {
        for (const auto& f : files) {
            if (!std::filesystem::remove(f)) {
                return false;
            }
        }
        return true;
    } catch (...) {
        return false;
    }
}
