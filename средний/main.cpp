#include <iostream>
#include <locale>
#include "team.h"

int main() {
    setlocale(LC_ALL, "ru");

    std::cout << "Всего игроков сейчас: " << Player::getPlayerCount() << "\n\n";

    Player p1("Иванов", 7, "нападающий");
    Player p2("Петров", 1, "вратарь");
    Player p3("Сидоров", 10, "полузащитник");

    std::cout << "\nВсего игроков сейчас: " << Player::getPlayerCount() << "\n\n";

    {
        Team team("Динамо");
        team.addPlayer(&p1);
        team.addPlayer(&p2);
        team.print();

        std::cout << "\nВыход из блока: команда уничтожается\n";
    } // здесь team уничтожается, но игроки остаются

    std::cout << "\nИгроки всё ещё существуют после удаления команды:\n";
    p1.print();
    p2.print();
    p3.print();

    std::cout << "\nВсего игроков сейчас: " << Player::getPlayerCount() << "\n";

    return 0;
}