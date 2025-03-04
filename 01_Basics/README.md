# 🚗 Object-Oriented Programming Basics

## 📝 Basic Car Class

Example code in codespaces [`01_Basics/basics.cpp`](01_Basics/basics.cpp).

### 📜 Code:
```cpp
#include <iostream>

class Car {
public:
    std::string brand;
    int year;

    Car(std::string b, int y) : brand(b), year(y) {}

    void display() {
        std::cout << "Car: " << brand << ", Year: " << year << std::endl;
    }
};

int main() {
    Car myCar("Toyota", 2020);
    myCar.display();
    return 0;
}
```

## ▶️ Run in GitHub Codespaces  

[![Open in GitHub Codespaces](https://github.com/codespaces/badge.svg)](https://codespaces.new/RunningBrute/cpp-playground)