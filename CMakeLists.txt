cmake_minimum_required(VERSION 2.8)

project(pdf)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -pthread")

if(CMAKE_C_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_D MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

find_package(Boost REQUIRED)
include_directories(include $(Boost_INCLUDE_DIR))


add_subdirectory(include)
add_subdirectory(example)
