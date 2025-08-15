set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Generate config.h from config.h.in
configure_file(${INCLUDE_DIR}/config.h.in ${INCLUDE_DIR}/config.hpp)

set(SOURCES
    ${SRC_DIR}/main.cpp
)

set(HEADERS
    ${INCLUDE_DIR}/config.h
)

source_group("Source Files/App" FILES ${SOURCES})
source_group("Header Files/App " FILES ${HEADERS})

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME}
        PRIVATE
        FileInfoLib
        FileOpsLib
)