#!/bin/bash

#Clean step
echo
echo
echo "<<<< Cleaning - Removing ./build >>>>"
rm -rf build
mkdir build

#Build
echo
echo
echo "<<<< Building >>>>"
cmake -S . -B build/
make -C ./build

#Run
echo
echo
echo "<<<< Running executable >>>>"
./build/bailando-cmake-base