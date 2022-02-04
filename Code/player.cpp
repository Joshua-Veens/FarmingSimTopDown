#include "player.hpp"

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


void player::setVehicle(active_t nActive) {
    this->active = nActive;
}

vehicle *player::getInactive(){
    return vehicles[(active == trekker) ? combine : trekker ];
}


std::array<vehicle *, 2> & player::getVehicles(){
    return vehicles;
}
