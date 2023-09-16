cmake_minimum_required(VERSION 3.27)

project(kys.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_DEBUG_POSTFIX "_d")

option(KYS_USE_ASAN "Use Address Sanitizer?" OFF)
option(KYS_USE_TSAN "Use Address Sanitizer?" OFF)

include(cmake/output_dir.cmake)
include(cmake/windows_encoding.cmake)

if(KYS_USE_ASAN)
  include(cmake/asan.cmake)
endif()

if(KYS_USE_TSAN)
  include(cmake/tsan.cmake)
endif()

find_package(fmt CONFIG REQUIRED)

add_library(mlcc INTERFACE
  ${CMAKE_SOURCE_DIR}/deps/mlcc/
)
target_include_directories(mlcc INTERFACE ${CMAKE_SOURCE_DIR}/deps/mlcc)

add_subdirectory(src/kys)

include(cmake/summary.cmake)