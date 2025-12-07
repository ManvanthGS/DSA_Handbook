cmake_minimum_required(VERSION 3.16)
project(DSA_Handbook LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Library Sources
set(DSA_SOURCES
    # ---------- Data Structures ----------
    src/data_structures/arrays/array.cpp
)

add_library(dsa_lib ${DSA_SOURCES})

target_include_directories(dsa_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Add executable
add_executable(dsa_app src/main.cpp)
target_link_libraries(dsa_app PRIVATE dsa_lib)

# Enable Test Framework
enable_testing()
add_subdirectory(tests)
