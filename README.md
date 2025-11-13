# Repository with demo programs written in c++

## How to run

### TDD example

```cpp
cd .\tdd
cmake -S . -B build
cmake --build build
.\build\Debug\test_calculator_catch2.exe // for catch2 unit tests
.\build\Debug\test_calculator_gtest.exe // for gtest unit tests
```