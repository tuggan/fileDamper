#Just a simple script to keep all unesessary files in a diffrent dir
mkdir -p build
cd build
cmake ..
make
mv fileDamper ../
cd ..
