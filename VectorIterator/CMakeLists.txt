cmake_minimum_required(VERSION 3.28.0)
project(vector)
set(SOURCES
    ./Tests.cpp
    ./main.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(vector
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)
