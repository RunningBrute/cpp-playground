#include <iostream>
#include <utility>
#include <type_traits>

template <typename T, typename Tag>
class StrongType {
public:
    // no default constructor
    StrongType() = delete;

    // explicit copy constructor
    explicit StrongType(const T& value) : value_(value) {}

    // explicit move constructor
    explicit StrongType(T&& value) noexcept(std::is_nothrow_move_constructible_v<T>)
        : value_(std::move(value)) {}

    // default copy
    StrongType(const StrongType&) = default;
    StrongType& operator=(const StrongType&) = default;

    // default move operations - noexcept here for stl cointeiners
    StrongType(StrongType&&) noexcept = default;
    StrongType& operator=(StrongType&&) noexcept = default;

    // simple access to value
    T get() const { return value_; }

    // some math operations
    StrongType operator+(const StrongType& other) const {
        return StrongType(value_ + other.value_);
    }

    StrongType operator-(const StrongType& other) const {
        return StrongType(value_ - other.value_);
    }

    // equal operators
    bool operator==(const StrongType& other) const {
        return value_ == other.value_;
    }

    bool operator!=(const StrongType& other) const {
        return !(*this == other);
    }

    // additional operators
    StrongType operator*(double scalar) const {
        return StrongType(value_ * scalar);
    }

    StrongType operator/(double scalar) const {
        return StrongType(value_ / scalar);
    }

    // operator << for esy printing
    friend std::ostream& operator<<(std::ostream& os, const StrongType& obj) {
        return os << obj.value_;
    }

private:
    T value_;
};

// names aliases
struct MetersTag {};
struct SecondsTag {};

using Meters = StrongType<double, MetersTag>;
using Seconds = StrongType<double, SecondsTag>;

struct MetersPerSecondTag {};
using MetersPerSecond = StrongType<double, MetersPerSecondTag>;

inline MetersPerSecond operator/(const Meters& dist, const Seconds& time) {
    return MetersPerSecond(dist.get() / time.get());
}


int main() {
    Meters d1(100.0);
    Meters d2(50.0);

    Seconds t1(10.0);

    // simple usage
    auto total = d1 + d2;
    std::cout << "Total distance: " << total << " meters\n";

    Meters d3 = d1;  // copy works
    d3 = d2;         // move works
    std::cout << "Copied distance: " << d3 << " meters\n";

    // multiply by double example
    auto scaled = d1 * 2.0;
    std::cout << "Scaled distance: " << scaled << " meters\n";

    // new type (m/s)
    auto speed = d1 / t1;
    std::cout << "Speed: " << speed << " m/s\n";

    // this should not compile
    // auto error = d1 + t1;

    return 0;
}
