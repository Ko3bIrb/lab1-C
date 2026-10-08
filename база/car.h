#pragma once
#include <string>
#include <vector>

class Engine {
private:
    std::string name;   // название двигателя
    int power;          // мощность, л.с.
    double volume;      // объём, л

public:
    Engine(const std::string& name, int power, double volume);
    ~Engine();

    void print() const;
};

class Car {
private:
    std::string model;
    std::vector<Engine> engines; // композиция

public:
    explicit Car(const std::string& model);
    ~Car();

    void addEngine(const std::string& name, int power, double volume);
    void print() const;
};