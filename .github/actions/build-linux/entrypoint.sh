#!/bin/sh -l

apt-get install -y ${INPUT_COMPILER_PKG}

export CC=${INPUT_CC}
export CXX=${INPUT_CXX}

rm -rf build
mkdir build
cd build

cmake .. -DCMAKE_BUILD_TYPE=$BUILD_TYPE

cmake --build . --config $BUILD_TYPE

ctest -C $BUILD_TYPE
