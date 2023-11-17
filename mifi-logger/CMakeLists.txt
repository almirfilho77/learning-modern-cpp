cmake_minimum_required(VERSION 3.13)

project(mifi-logger)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/api/")

file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(${PROJECT_NAME} STATIC ${SOURCES})