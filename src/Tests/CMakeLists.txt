set(TEST_RUNNER_TARGET_NAME ${PROJECT_NAME}TestRunner)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")

set(SOURCES
        ${SRC_DIR}/main.cpp
)

source_group("Source Files/Tests" FILES ${SOURCES})

add_executable(${TEST_RUNNER_TARGET_NAME} ${SOURCES})

target_compile_definitions(${TEST_RUNNER_TARGET_NAME} PUBLIC _IMPORTING)

target_include_directories(${TEST_RUNNER_TARGET_NAME} PUBLIC ${INCLUDE_DIR})

target_link_libraries(${TEST_RUNNER_TARGET_NAME}
        PRIVATE
        ${FILE_INFO_LIB_NAME}
        ${FILE_OPS_LIB_NAME}
)