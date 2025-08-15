#include "config.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        // report version
        std::cout << argv[0] << " Version " << PROJECT_VERSION_MAJOR << "."
                << PROJECT_VERSION_MINOR << "." << PROJECT_VERSION_PATCH
                << std::endl;
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }
    return 0;
}
