set(LIB_NAME FileInfoLib)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

message("FileInfoLib INCLUDE_DIR ${INCLUDE_DIR}")

set(SOURCES
        ${SRC_DIR}/DirectoryInfo.cpp
        ${SRC_DIR}/FileInfo.cpp
        ${SRC_DIR}/PathInfo.cpp
        ${SRC_DIR}/PathUtils.cpp
)

set(HEADERS
        ${INCLUDE_DIR}/DirectoryInfo.hpp
        ${INCLUDE_DIR}/FileInfo.hpp
        ${INCLUDE_DIR}/PathInfo.hpp
        ${INCLUDE_DIR}/PathUtils.hpp
)

source_group("Source Files/FileInfoLib" FILES ${SOURCES})
source_group("Header Files/FileInfoLib" FILES ${HEADERS})

add_library(${LIB_NAME} STATIC ${SOURCES} ${HEADERS})

target_include_directories(${LIB_NAME} PUBLIC ${INCLUDE_DIR})