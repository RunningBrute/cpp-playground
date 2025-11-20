//Observer

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

struct IObserver
{
    virtual ~IObserver() = default;
    virtual void onTemperatureChange(double temp) = 0;
};

class TemperatureSensor
{
public:
    void attach(IObserver* obs)
    {
        observers_.push_back(obs);
    }

    void setTemperature(double t)
    {
        temperature_ = t;
        notifyAll();
    }

private:
    void notifyAll()
    {
        for (auto* o : observers_)
            o->onTemperatureChange(temperature_);
    }

    std::vector<IObserver*> observers_;
    double temperature_{};
};

class Display : public IObserver
{
public:
    void onTemperatureChange(double t) override
    {
        std::cout << "Display: new temperature = " << t << "°C\n";
    }
};

class Logger : public IObserver
{
public:
    void onTemperatureChange(double t) override
    {
        std::cout << "[Log] Temperature changed to " << t << "\n";
    }
};

int main()
{
    TemperatureSensor sensor;
    Display display;
    Logger logger;

    sensor.attach(&display);
    sensor.attach(&logger);

    sensor.setTemperature(22.5);
    sensor.setTemperature(25.0);
}