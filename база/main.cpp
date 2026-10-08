#include <iostream>
#include <locale>
#include "car.h"

int main() {
    setlocale(LC_ALL, "ru");

    {
        Car car("Toyota Camry");

        car.addEngine("2.5L", 200, 2.5);
        car.addEngine("3.5L V6", 300, 3.5);

        car.print();

        std::cout << "Выход из внутреннего блока\n";
    } // здесь car уничтожается, а вместе с ним — все Engine

    return 0;
}