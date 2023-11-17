cmake_minimum_required(VERSION 3.13)

project(test-app)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include_directories("mifi-logger/api")

add_subdirectory(mifi-logger)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(test-app PUBLIC mifi-logger)
target_include_directories(test-app PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/mifi-logger/api")