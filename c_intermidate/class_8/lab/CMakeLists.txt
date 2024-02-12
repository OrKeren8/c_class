cmake_minimum_required(VERSION 3.11-3.18)

project(lab)

add_library(lab src/lab.c)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_compile_features(lab PUBLIC cxx_std_20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ADDITIONAL_CFLAGS} -g")