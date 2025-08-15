cmake_minimum_required(VERSION 3.10)

project(filetool VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

# Output all binaries/libs to a common build folder
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)  # static libs
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)  # shared libs
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)  # executables

message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "Version: ${PROJECT_VERSION}")

if(WIN32)
    message(STATUS "Platform: Windows")
elseif(LINUX)
    message(STATUS "Platform: Linux")
elseif(APPLE)
    message(STATUS "Platform: macOS")
else()
    message(FATAL_ERROR "Unsupported platform")
endif()

message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID} (${CMAKE_CXX_COMPILER})")
message(STATUS "Compiler version: ${CMAKE_CXX_COMPILER_VERSION}")

if(MSVC)
    message(STATUS "MSVC version: ${MSVC_VERSION}")
    message(STATUS "MSVC toolset: ${CMAKE_MSVC_TOOLSET_VERSION}")

    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

    # Set MSVC specific flags
    # /W4 (enable more warnings) and /WX (treat warnings as errors)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
    # /Zi (generate debug information)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Zi")
    # /O2 (optimize for speed), /Ob2 (inline function expansion)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2 /Ob2")
    # /O2 (optimize), /Ob1 (inline only marked functions), and /Zi (debug info)
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} /O2 /Ob1 /Zi")
else()
    # Set GCC/Clang specific flags
    # -Wall (all warnings), -Wextra (extra warnings), -Werror (treat warnings as errors)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pedantic")
    # -g (debug info)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
    # -O2 (optimize for speed)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
    # -O2 (optimize), -g (debug info)
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -O2 -g")
endif()

set(FileInfoLib "${CMAKE_CURRENT_SOURCE_DIR}/src/FileInfoLib")
set(FileOpsLib "${CMAKE_CURRENT_SOURCE_DIR}/src/FileOpsLib")
set(App "${CMAKE_CURRENT_SOURCE_DIR}/src/App")

add_subdirectory(${FileInfoLib})
add_subdirectory(${FileOpsLib})
add_subdirectory(${App})