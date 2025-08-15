//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#ifndef FILETOOL_FILEINFO_HPP
#define FILETOOL_FILEINFO_HPP
#include "PathInfo.hpp"

class FileInfo : PathInfo {
public:
    using PathInfo::PathInfo;

    uintmax_t size() const;

    std::string sizeHumanReadable() const;

    std::chrono::system_clock::time_point creationTime() const;

    std::chrono::system_clock::time_point lastModifiedTime() const;

    std::chrono::system_clock::time_point lastAccessedTime() const;

    std::string checksumSHA256() const;

    std::string mimeType() const;
};

#endif //FILETOOL_FILEINFO_HPP
