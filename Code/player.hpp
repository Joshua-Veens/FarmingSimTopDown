#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "vehicle.hpp"
#include "tractor.hpp"
#include "harvester.hpp"
#include <array>
class player {
private:
std::array<vehicle *,2> & vehicles;
enum active_t {trekker=0,combine=1};
active_t active = trekker; 
public:
    player(std::array<vehicle *,2> & vehicles);
    void swapVehicle(); //tractorOrHarvester
    vehicle * getVehicle();
};

#endif