# Core Module

set(CORE_SOURCE
    Source/String/Encoding.cpp
)

target_sources(${PROJECT_NAME} PRIVATE ${CORE_SOURCE})
target_include_directories(${PROJECT_NAME} PUBLIC Include)


# target_include_directories(${PROJECT_NAME} PRIVATE
#    Source
#)