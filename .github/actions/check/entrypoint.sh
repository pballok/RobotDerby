#!/bin/sh -l

apt-get install -y ${INPUT_PKG_NAME}

export CC=clang-10
export CXX=clang++-10

rm -rf build
mkdir build
cd build

cmake ..

make ${INPUT_CHECK_TARGET}
