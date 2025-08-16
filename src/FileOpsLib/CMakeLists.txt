set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

set(SOURCES
        ${SRC_DIR}/DirectoryOps.cpp
        ${SRC_DIR}/FileOps.cpp
        ${SRC_DIR}/PathOps.cpp
)

set(HEADERS
        ${INCLUDE_DIR}/FileOpsAPI.hpp
        ${INCLUDE_DIR}/DirectoryOps.hpp
        ${INCLUDE_DIR}/FileOps.hpp
        ${INCLUDE_DIR}/PathOps.hpp
)

source_group("Source Files/FileOpsLib" FILES ${SOURCES})
source_group("Header Files/FileOpsLib" FILES ${HEADERS})

add_library(${FILE_OPS_LIB_NAME} SHARED ${SOURCES} ${HEADERS})

target_compile_definitions(${FILE_OPS_LIB_NAME} PUBLIC _EXPORTING)

target_include_directories(${FILE_OPS_LIB_NAME} PUBLIC ${INCLUDE_DIR})