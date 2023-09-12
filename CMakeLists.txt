cmake_minimum_required(VERSION 3.27)

project(kys.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_DEBUG_POSTFIX "_d")

add_executable(kys
  kys.cpp
)
