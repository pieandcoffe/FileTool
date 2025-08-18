//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#include "FileOps.hpp"
#include <fstream>
#include <iterator>
#include <stdexcept>

struct FileOps::Impl {
public:
    explicit Impl(const std::filesystem::path& p)
        : m_path(std::filesystem::canonical(p)) {}

    static std::unique_ptr<Impl, ImplDeleter> makeImpl(const std::filesystem::path &p) {
        return std::unique_ptr<Impl, ImplDeleter>(std::make_unique<Impl>(p).release());
    }

    std::filesystem::path m_path;
};

// custom deleter definition
void FileOps::ImplDeleter::operator()(const Impl* p) const noexcept {
    delete p;
}

// Constructor
FileOps::FileOps(const std::filesystem::path& path)
    : m_impl(Impl::makeImpl(path)) {}

FileOps::~FileOps() = default;

bool FileOps::exists() const {
    return std::filesystem::exists(path());
}

bool FileOps::copyTo(const std::filesystem::path& destination, bool overwrite) const {
    try {
        if (overwrite) {
            std::filesystem::copy_file(
                path(), destination,
                std::filesystem::copy_options::overwrite_existing
            );
        } else {
            std::filesystem::copy_file(
                path(), destination,
                std::filesystem::copy_options::skip_existing
            );
        }
        return true;
    } catch (...) {
        return false;
    }
}

bool FileOps::moveTo(const std::filesystem::path& destination, bool overwrite) const {
    try {
        if (overwrite && std::filesystem::exists(destination)) {
            std::filesystem::remove(destination);
        }
        std::filesystem::rename(path(), destination);
        return true;
    } catch (...) {
        return false;
    }
}

bool FileOps::rename(const std::string& newName) {
    try {
        auto newPath = path().parent_path() / newName;
        std::filesystem::rename(path(), newPath);
        path() = newPath;
        return true;
    } catch (...) {
        return false;
    }
}

bool FileOps::remove() {
    try {
        return std::filesystem::remove(path());
    } catch (...) {
        return false;
    }
}

std::string FileOps::readText() const {
    std::ifstream file(path());
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for reading: " + path().string());
    }
    return std::string((std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>());
}

std::vector<uint8_t> FileOps::readBinary() const {
    std::ifstream file(path(), std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for binary reading: " + path().string());
    }
    return std::vector<uint8_t>((std::istreambuf_iterator<char>(file)),
                                std::istreambuf_iterator<char>());
}

bool FileOps::writeText(const std::string& content, bool overwrite) const {
    try {
        if (!overwrite && std::filesystem::exists(path())) {
            return false;
        }
        std::ofstream file(path(), std::ios::trunc);
        if (!file.is_open()) {
            return false;
        }
        file << content;
        return true;
    } catch (...) {
        return false;
    }
}

bool FileOps::writeBinary(const std::vector<uint8_t>& data, bool overwrite) const {
    try {
        if (!overwrite && std::filesystem::exists(path())) {
            return false;
        }
        std::ofstream file(path(), std::ios::binary | std::ios::trunc);
        if (!file.is_open()) {
            return false;
        }
        file.write(reinterpret_cast<const char*>(data.data()), data.size());
        return true;
    } catch (...) {
        return false;
    }
}

std::filesystem::path FileOps::path() const {
    return m_impl->m_path;
}
