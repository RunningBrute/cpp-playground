#include <gmock/gmock.h>  // Brings in gMock.
#include "calculator.hpp"

class MockCalculator : public ICalculator {
 public:
  MOCK_METHOD(int, add, (int a, int b), (override));
  MOCK_METHOD(int, subtract, (int a, int b), (override));
  MOCK_METHOD(int, multiply, (int a, int b), (override));
  MOCK_METHOD(double, divide, (double a, double b), (override));
  MOCK_METHOD(double, power, (double base, double exponent), (override));
  MOCK_METHOD(double, average, (const std::vector<int>& numbers), (override));
};