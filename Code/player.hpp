#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "vehicle.hpp"
#include "tractor.hpp"
#include "harvester.hpp"
#include <array>
#include <iostream>

enum active_t
{
    trekker = 0,
    combine = 1
};
class player
{
private:
    std::array<vehicle *, 2> &vehicles;
    active_t active = trekker;
    uint64_t money = 30000;

public:
    player(std::array<vehicle *, 2> &vehicles);
    void swapVehicle(sf::Clock &clock); // tractorOrHarvester
    vehicle *getVehicle();
    active_t getVehicle_type();
    void setMoney(uint64_t newMoney);
    uint64_t getMoney();
    void addMoney(uint64_t delta);
    friend std::ostream &operator<<(std::ostream &lhs, player &Player)
    {
        return lhs << "Money: " << Player.getMoney() << " ActiveVehicle: " << ((Player.getVehicle_type() == trekker) ? "trekker" : "combine") << " position: " << Player.getVehicle()->getPosition().x << "," << Player.getVehicle()->getPosition().y;
    }
};

#endif