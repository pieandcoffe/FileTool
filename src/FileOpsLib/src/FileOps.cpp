//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#include "FileOps.hpp"
#include <fstream>
#include <iterator>
#include <stdexcept>

// Constructor
FileOps::FileOps(const std::filesystem::path& path)
    : m_path(path) {}

bool FileOps::exists() const {
    return std::filesystem::exists(m_path);
}

bool FileOps::copyTo(const std::filesystem::path& destination, bool overwrite) const {
    try {
        if (overwrite) {
            std::filesystem::copy_file(
                m_path, destination,
                std::filesystem::copy_options::overwrite_existing
            );
        } else {
            std::filesystem::copy_file(
                m_path, destination,
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
        std::filesystem::rename(m_path, destination);
        return true;
    } catch (...) {
        return false;
    }
}

bool FileOps::rename(const std::string& newName) {
    try {
        auto newPath = m_path.parent_path() / newName;
        std::filesystem::rename(m_path, newPath);
        m_path = newPath;
        return true;
    } catch (...) {
        return false;
    }
}

bool FileOps::remove() {
    try {
        return std::filesystem::remove(m_path);
    } catch (...) {
        return false;
    }
}

std::string FileOps::readText() const {
    std::ifstream file(m_path);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for reading: " + m_path.string());
    }
    return std::string((std::istreambuf_iterator<char>(file)),
                       std::istreambuf_iterator<char>());
}

std::vector<uint8_t> FileOps::readBinary() const {
    std::ifstream file(m_path, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open file for binary reading: " + m_path.string());
    }
    return std::vector<uint8_t>((std::istreambuf_iterator<char>(file)),
                                std::istreambuf_iterator<char>());
}

bool FileOps::writeText(const std::string& content, bool overwrite) const {
    try {
        if (!overwrite && std::filesystem::exists(m_path)) {
            return false;
        }
        std::ofstream file(m_path, std::ios::trunc);
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
        if (!overwrite && std::filesystem::exists(m_path)) {
            return false;
        }
        std::ofstream file(m_path, std::ios::binary | std::ios::trunc);
        if (!file.is_open()) {
            return false;
        }
        file.write(reinterpret_cast<const char*>(data.data()), data.size());
        return true;
    } catch (...) {
        return false;
    }
}
