#include "player.hpp"
#include <iostream>
player::player(std::array<vehicle *, 2> &vehicles) : vehicles(vehicles) {}

vehicle *player::getVehicle()
{
    return vehicles[active];
}

active_t player::getVehicle_type(){
    return active;
}

void player::swapVehicle(sf::Clock &clock) // tractorOrHarvester
{
    sf::Time time = clock.getElapsedTime();
    clock.restart();
    if (time.asMilliseconds() > 500)
    {
        if (active == trekker)
        {
            active = combine;
        }
        else
        {
            active = trekker;
        }
    }
}

void player::setMoney(uint64_t newMoney){
    money = newMoney;
}

uint64_t player::getMoney(){
    return money;
}

void player::addMoney(uint64_t delta){
    money += delta;
}

