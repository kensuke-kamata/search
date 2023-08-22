cmake_minimum_required(VERSION 3.3.0)
project(002 VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRC
    main.cpp
    ${CMAKE_SOURCE_DIR}/../../env/Maze.cpp
)

include_directories(
    ${CMAKE_SOURCE_DIR}/../../algo
    ${CMAKE_SOURCE_DIR}/../../env
)

add_executable(${PROJECT_NAME} ${SRC})

target_compile_options(${PROJECT_NAME} PRIVATE
  -Wall -Wextra -Wpedantic -Werror
)
