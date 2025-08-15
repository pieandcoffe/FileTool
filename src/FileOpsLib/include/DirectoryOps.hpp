//
// Created by Kyrylo Pylinskyi on 14/08/2025.
//

#ifndef FILETOOL_DIRECTORYOPS_HPP
#define FILETOOL_DIRECTORYOPS_HPP

class DirectoryOps {
public:
    explicit DirectoryOps(const std::filesystem::path& path);

    bool exists() const;
    bool create(bool recursive = true);
    bool remove(bool recursive = true); // removes directory and all contents
    bool empty(); // removes all contents but keeps the directory

    bool copyTo(const std::filesystem::path& destination, bool recursive = true, bool overwrite = false);
    bool moveTo(const std::filesystem::path& destination, bool overwrite = false);

private:
    std::filesystem::path m_path;
};

#endif //FILETOOL_DIRECTORYOPS_HPP