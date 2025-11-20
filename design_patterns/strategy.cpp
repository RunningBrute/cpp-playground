//Strategy Pattern

#include <iostream>
#include <memory>
#include <string>
#include <algorithm>

// strategy interface
struct IFormatStrategy
{
    virtual ~IFormatStrategy() = default;
    virtual std::string format(std::string input) const = 0;
};

// upper case strategy
struct UpperCaseStrategy : IFormatStrategy
{
    std::string format(std::string input) const override
    {
        std::transform(input.begin(), input.end(), input.begin(), ::toupper);
        return input;
    }
};

// other strategy the same interface
struct LowerCaseStrategy : IFormatStrategy
{
    std::string format(std::string input) const override
    {
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);
        return input;
    }
};

// contex where we cas use upper and lower case strategies
class TextFormatter
{
public:
    explicit TextFormatter(std::unique_ptr<IFormatStrategy> strategy)
        : strategy_(std::move(strategy)) 
    {}

    void setStrategy(std::unique_ptr<IFormatStrategy> strategy)
    {
        strategy_ = std::move(strategy);
    }

    std::string apply(const std::string& text) const
    {
        return strategy_->format(text);
    }

private:
    std::unique_ptr<IFormatStrategy> strategy_;
};

int main()
{
    TextFormatter fmt(std::make_unique<UpperCaseStrategy>());
    std::cout << fmt.apply("C++ Strategy Pattern\n");

    fmt.setStrategy(std::make_unique<LowerCaseStrategy>());
    std::cout << fmt.apply("C++ STRATEGY PATTERN\n");
}