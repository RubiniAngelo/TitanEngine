cmake_minimum_required(VERSION 3.17 FATAL_ERROR)

project(TitanEngine VERSION 0.0.1)

# Cpp Settings
set(CMAKE_CXX_STANDARD 14)

# Project Settings
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Engine)


add_subdirectory(${SOURCE_DIR}/Launch)
add_subdirectory(${SOURCE_DIR}/Core)