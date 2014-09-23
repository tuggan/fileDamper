#!/bin/bash
#Just a simple script to keep all unesessary files in a diffrent dir
mkdir -p build
cd build

case $1 in
    "debug")
        echo "Building with debug symbols."
        cmake -DCMAKE_BUILD_TYPE=Debug ..
        make
        ;;
    *)
        echo "Building release."
        cmake -DCMAKE_BUILD_TYPE=Release ..
        make
        echo "Stripping binairy"
        strip fileDamper
        ;;
esac

mv fileDamper ../
cd ..
