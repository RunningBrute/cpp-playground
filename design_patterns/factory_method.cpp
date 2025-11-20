// Factory Method

#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <functional>

// Product
struct Shape
{
    virtual ~Shape() = default;
    virtual void draw() const = 0;
};

// concrete product
struct Circle : Shape
{
    void draw() const override { std::cout << "Drawing Circle\n"; }
};

struct Square : Shape
{
    void draw() const override { std::cout << "Drawing Square\n"; }
};

// Factory
class ShapeFactory
{
public:
    ShapeFactory()
    {
        registerType("circle", [] { return std::make_unique<Circle>(); });
        registerType("square", [] { return std::make_unique<Square>(); });
    }

    std::unique_ptr<Shape> create(const std::string& name) const
    {
        if (auto it = creators_.find(name); it != creators_.end())
            return it->second();
        throw std::invalid_argument("Unknown shape: " + name);
    }

private:
    void registerType(const std::string& name, std::function<std::unique_ptr<Shape>()> fn)
    {
        creators_[name] = std::move(fn);
    }

    std::unordered_map<std::string, std::function<std::unique_ptr<Shape>()>> creators_;
};

int main()
{
    ShapeFactory factory;

    auto c = factory.create("circle");
    c->draw();

    auto s = factory.create("square");
    s->draw();
}