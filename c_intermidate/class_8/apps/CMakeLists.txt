# version 3.11 or later of CMake or needed later for installing GoogleTest
# so let's require it now.
cmake_minimum_required(VERSION 3.11-3.18)

project(main)

set(CMAKE_BUILD_TYPE Debug)  # Set the build type to Debug

# Add the -g flag to the compiler flags to enable debugging symbols
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_executable(main main.c)
# We need hello.h and the hello library
target_link_libraries(main
    PRIVATE lab)

# Tell C++ compiler to use C++20 features. We don't actually use any of them.
target_compile_features(main PUBLIC cxx_std_20)