//Decorator

#include <iostream>
#include <memory>
#include <string>
#include <ctime>
#include <algorithm>

struct ILogger
{
    virtual ~ILogger() = default;
    virtual void log(std::string_view msg) = 0;
};

struct ConsoleLogger : ILogger
{
    void log(std::string_view msg) override
    {
        std::cout << msg << "\n";
    }
};

// base decorator
struct LoggerDecorator : ILogger
{
    explicit LoggerDecorator(std::unique_ptr<ILogger> inner)
        : inner_(std::move(inner))
    {}
protected:
    std::unique_ptr<ILogger> inner_;
};

// concrete decorators
struct TimestampLogger : LoggerDecorator
{
    using LoggerDecorator::LoggerDecorator;
    void log(std::string_view msg) override
    {
        std::time_t now = std::time(nullptr);
        std::cout << "[" << std::ctime(&now) << "] ";
        inner_->log(msg);
    }
};

struct UppercaseLogger : LoggerDecorator
{
    using LoggerDecorator::LoggerDecorator;
    void log(std::string_view msg) override
    {
        std::string upper(msg);
        std::transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
        inner_->log(upper);
    }
};

// Test
int main()
{
    std::unique_ptr<ILogger> logger =
        std::make_unique<TimestampLogger>(
            std::make_unique<UppercaseLogger>(
                std::make_unique<ConsoleLogger>()));

    logger->log("decorator pattern in c++");
}