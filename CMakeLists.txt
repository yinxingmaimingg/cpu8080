cmake_minimum_required(VERSION 2.8.4)
project(cpu8080)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/InvadersIO.cpp src/Intel8080.cpp src/main.cpp )
add_executable(cpu8080 ${SOURCE_FILES})

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(cpu8080 ${SDL2_LIBRARIES})