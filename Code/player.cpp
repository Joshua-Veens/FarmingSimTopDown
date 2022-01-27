#include "player.hpp"
#include <iostream>
player::player(std::array<vehicle *, 2> &vehicles) : vehicles(vehicles) {}

vehicle *player::getVehicle()
{
    return vehicles[active];
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