# LeetsCode solutions

## Install all needed dependiences

`conan install . --output-folder=build --build=missing -s build_type=Debug -s compiler.cppstd=20`

## Build project

```
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE="conan_toolchain.cmake"
cmake --build .
ctest
```
