# Repository with demo programs written in c++

## How to run

### Strong Type example

```cpp
cd .\strong_types
cl /EHsc /std:c++20 strong_type_example.cpp // build example
strong_type_example.exe // run it
```

### TDD example

```cpp
cd .\tdd
cmake -S . -B build
cmake --build build
.\build\Debug\test_calculator_catch2.exe // for catch2 unit tests
.\build\Debug\test_calculator_gtest.exe // for gtest unit tests
```
### LeetsCode solutions
```
cd leetscode
conan install . --output-folder=build --build=missing -s build_type=Debug -s compiler.cppstd=20`
mkdir build
cd build
cmake . -DCMAKE_TOOLCHAIN_FILE="conan_toolchain.cmake"
cmake --build .
ctest
```

### OpenCV
```
cd opencv
cmake -S . -B build
cmake --build build
cd build/Debug
./helloWorld
```
### Exercism
```
cd exercism
cmake -S . -B build
cmake --build build
cd build && ctest
```
