# Core Module

set(CORE_SOURCE
    src/String/Private/Encoding.cpp
)

target_sources(${PROJECT_NAME} PRIVATE ${CORE_SOURCE})

target_include_directories(${PROJECT_NAME} PUBLIC src)