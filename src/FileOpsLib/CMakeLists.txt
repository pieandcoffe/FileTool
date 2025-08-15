set(LIB_NAME FileOpsLib)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

set(SOURCES
        ${SRC_DIR}/DirectoryOps.cpp
        ${SRC_DIR}/FileOps.cpp
        ${SRC_DIR}/PathOps.cpp
)

set(HEADERS
        ${INCLUDE_DIR}/DirectoryOps.hpp
        ${INCLUDE_DIR}/FileOps.hpp
        ${INCLUDE_DIR}/PathOps.hpp
)

source_group("Source Files/FileOpsLib" FILES ${SOURCES})
source_group("Header Files/FileOpsLib" FILES ${HEADERS})

add_library(${LIB_NAME} STATIC ${SOURCES} ${HEADERS})

target_include_directories(${LIB_NAME} PUBLIC ${INCLUDE_DIR})