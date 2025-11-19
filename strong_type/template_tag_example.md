For following code in C++:

```cpp
template<typename T, typename Tag>
class StrongType {
public:
    explicit StrongType(const T& value) : value_(value) {}
    const T& get() const { return value_; }
private:
    T value_;
};

struct MeterTag {};
struct SecondTag {};

using Meter = StrongType<double, MeterTag>;
using Second = StrongType<double, SecondTag>;
```

this is what compiler "see" for `StrongType<double, MeterTag>`:

```cpp
class StrongType_double_MeterTag {
public:
    explicit StrongType_double_MeterTag(const double& value) : value_(value) {}
    const double& get() const { return value_; }
private:
    double value_;
};
```

and what compiler see for `StrongType<double, SecondTag>`:

```cpp
class StrongType_double_SecondTag {
public:
    explicit StrongType_double_SecondTag(const double& value) : value_(value) {}
    const double& get() const { return value_; }
private:
    double value_;
};
```

In general this is the same rule like in lambda function:

```cpp
auto lam = [](int x) { return x * 2; };
```

when compiler see above lambda function he make something like this:

```cpp
struct __lambda_1234 {
    int operator()(int x) const { return x * 2; }
};
```