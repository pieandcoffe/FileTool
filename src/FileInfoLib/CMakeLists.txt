set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

set(SOURCES
        ${SRC_DIR}/DirectoryInfo.cpp
        ${SRC_DIR}/FileInfo.cpp
        ${SRC_DIR}/PathInfo.cpp
        ${SRC_DIR}/PathUtils.cpp
)

set(HEADERS
        ${INCLUDE_DIR}/FileInfoAPI.hpp
        ${INCLUDE_DIR}/DirectoryInfo.hpp
        ${INCLUDE_DIR}/FileInfo.hpp
        ${INCLUDE_DIR}/PathInfo.hpp
        ${INCLUDE_DIR}/PathUtils.hpp
)

source_group("Source Files/FileInfoLib" FILES ${SOURCES})
source_group("Header Files/FileInfoLib" FILES ${HEADERS})

add_library(${FILE_INFO_LIB_NAME} SHARED ${SOURCES} ${HEADERS})

target_compile_definitions(${FILE_INFO_LIB_NAME} PRIVATE _EXPORTING)

target_include_directories(${FILE_INFO_LIB_NAME} PUBLIC ${INCLUDE_DIR})