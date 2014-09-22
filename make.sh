#!/bin/bash
#Just a simple script to keep all unesessary files in a diffrent dir
mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make
mv fileDamper ../
cd ..
