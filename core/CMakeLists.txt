cmake_minimum_required(VERSION 3.0.2)

project(core)

FILE(GLOB_RECURSE HEADERS include/ *.h)
FILE(GLOB_RECURSE SOURCES src/ *.cpp)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE include)

add_custom_target(${PROJECT_NAME}-ide SOURCES ${HEADERS} ${SOURCES})
