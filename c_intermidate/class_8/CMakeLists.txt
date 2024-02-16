cmake_minimum_required(VERSION 3.11-3.18)

project(
    lab
    VERSION 0.1)

    set(CMAKE_BUILD_TYPE Debug)  # Set the build type to Debug

    # Add the -g flag to the compiler flags to enable debugging symbols
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
    
    add_subdirectory(lab)   # look in hello subdirectory for CMakeLists.txt to process
    add_subdirectory(apps)    # look in apps subdirectory for CMakeLists.txt to process
