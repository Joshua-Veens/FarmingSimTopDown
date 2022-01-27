#include "player.hpp"
#include <iostream>
player::player(std::array<vehicle *, 2> &vehicles) : vehicles(vehicles) {}

vehicle *player::getVehicle()
{
    return vehicles[active];
}

void player::swapVehicle() // tractorOrHarvester
{
    if(active == trekker){
        active = combine;
    }else{
        active = trekker;
    }
}