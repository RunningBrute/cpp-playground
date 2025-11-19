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