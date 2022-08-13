cmake_minimum_required(VERSION 3.0.2)

project(example)

FILE(GLOB HEADERS *.h)
FILE(GLOB SOURCES *.cpp)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME} core)
