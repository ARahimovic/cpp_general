cmake_minimum_required(VERSION 3.16)

project(myStringClasss LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(myString
    myString.cpp
    myString.hpp
)

target_include_directories(myString
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_options(myString
    PRIVATE
        $<$<CXX_COMPILER_ID:GNU,Clang>:-Wall -Wextra -Wpedantic>
)
