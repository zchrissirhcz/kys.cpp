#!/bin/bash

BUILD_DIR=linux-x64

cmake \
    -S .. \
    -B $BUILD_DIR \
    -DCMAKE_TOOLCHAIN_FILE=$HOME/work/vcpkg/scripts/buildsystems/vcpkg.cmake

cmake --build $BUILD_DIR