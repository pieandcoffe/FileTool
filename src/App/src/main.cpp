#include <iostream>

#include "config.hpp"
#include "DirectoryInfo.hpp"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        // report version
        std::cout << argv[0] << " Version " << PROJECT_VERSION_MAJOR << "."
                << PROJECT_VERSION_MINOR << "." << PROJECT_VERSION_PATCH
                << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    DirectoryInfo di = DirectoryInfo(argv[1]);
    for ( auto entry : di.listEntries(false)) {
        std::cout << entry << std::endl;
    }

    return 0;
}
