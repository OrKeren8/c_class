cmake_minimum_required(VERSION 3.11-3.18)

project(
    lab
    VERSION 0.1)

add_subdirectory(lab)   # look in hello subdirectory for CMakeLists.txt to process
add_subdirectory(apps)    # look in apps subdirectory for CMakeLists.txt to process
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ADDITIONAL_CFLAGS} -g")