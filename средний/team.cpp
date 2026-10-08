#include "team.h"
#include <iostream>

int Player::playerCount = 0; // определение статического поля

Player::Player(const std::string& name, int number, const std::string& role)
    : name(name), number(number), role(role) {
    ++playerCount;
    std::cout << "Создан игрок \"" << name
        << "\" (номер " << number << ", " << role << ")\n";
}

Player::~Player() {
    --playerCount;
    std::cout << "Удалён игрок \"" << name << "\"\n";
}

std::string Player::getName() const {
    return name;
}

void Player::print() const {
    std::cout << "  - " << name
        << ", номер " << number
        << ", амплуа: " << role << "\n";
}

int Player::getPlayerCount() {
    return playerCount;
}

Team::Team(const std::string& name)
    : name(name) {
    std::cout << "Создана команда \"" << name << "\"\n";
}

Team::~Team() {
    std::cout << "Удалена команда \"" << name << "\"\n";
    // игроки НЕ удаляются — это агрегация
}

void Team::addPlayer(Player* player) {
    if (player == nullptr) {
        std::cout << "Нельзя добавить nullptr в команду\n";
        return;
    }
    players.push_back(player);
    std::cout << "Игрок \"" << player->getName()
        << "\" добавлен в команду \"" << name << "\"\n";
}

void Team::print() const {
    std::cout << "Команда \"" << name << "\":\n";
    if (players.empty()) {
        std::cout << "(нет игроков)\n";
        return;
    }
    for (const auto* player : players) {
        if (player != nullptr) {
            player->print();
        }
    }
}