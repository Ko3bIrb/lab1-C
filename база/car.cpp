#include "car.h"
#include <iostream>

Engine::Engine(const std::string& name, int power, double volume)
    : name(name), power(power), volume(volume) {
    std::cout << "Создан двигатель \"" << name
        << "\" (" << power << " л.с., " << volume << " л)\n";
}

Engine::~Engine() {
    std::cout << "Удалён двигатель \"" << name << "\"\n";
}

void Engine::print() const {
    std::cout << "  - " << name
        << ": " << power << " л.с., "
        << volume << " л\n";
}

Car::Car(const std::string& model)
    : model(model) {
    std::cout << "Создан автомобиль \"" << model << "\"\n";
}

Car::~Car() {
    std::cout << "Удалён автомобиль \"" << model << "\"\n";
    // vector<Engine> сам уничтожит все двигатели
}

void Car::addEngine(const std::string& name, int power, double volume) {
    engines.emplace_back(name, power, volume);
    std::cout << "Двигатель \"" << name
        << "\" добавлен в автомобиль \"" << model << "\"\n";
}

void Car::print() const {
    std::cout << "Автомобиль \"" << model << "\":\n";
    if (engines.empty()) {
        std::cout << "  (нет двигателей)\n";
        return;
    }
    for (const auto& engine : engines) {
        engine.print();
    }
}