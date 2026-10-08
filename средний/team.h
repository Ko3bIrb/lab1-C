#pragma once
#include <string>
#include <vector>

class Player {
private:
    std::string name;   // имя игрока
    int number;         // номер
    std::string role;   // амплуа

    static int playerCount; // счётчик всех созданных игроков

public:
    Player(const std::string& name, int number, const std::string& role);
    ~Player();

    std::string getName() const;
    void print() const;

    static int getPlayerCount();
};

class Team {
private:
    std::string name;
    std::vector<Player*> players; // агрегация: игроки существуют отдельно

public:
    explicit Team(const std::string& name);
    ~Team();

    void addPlayer(Player* player);
    void print() const;
};