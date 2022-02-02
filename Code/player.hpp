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
    vehicle *getInactive();
    active_t getVehicle_type();
    void setMoney(uint64_t newMoney);
    uint64_t getMoney();
    void addMoney(uint64_t delta);
    std::array<vehicle *, 2> & getVehicles();
    friend std::ostream &operator<<(std::ostream &lhs, player &Player)
    {
        return lhs << " ActiveVehicle: " << ((Player.getVehicle_type() == trekker) ? "trekker" : "combine") << "@" << Player.getVehicle()->getPosition().x << "," << Player.getVehicle()->getPosition().y <<  '(' << Player.getVehicle()->getRotation() << ")" << " otherVehicle: " 
        << (Player.getVehicle_type() == trekker ? "combine" : "trekker") << "@" 
        << Player.getInactive()->getPosition().x << ',' 
        << Player.getInactive()->getPosition().y << '(' << Player.getInactive()->getRotation() << ")";
    }

    void setVehicle(active_t nActive);
};

#endif