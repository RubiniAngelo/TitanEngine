cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

project(TitanEngine VERSION 0.0.1)

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Engine)

add_executable(${PROJECT_NAME}
    ${SOURCE_DIR}/Launch/main.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${SOURCE_DIR}
)