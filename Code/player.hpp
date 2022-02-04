#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "vehicle.hpp"
#include "tractor.hpp"
#include "harvester.hpp"
#include <array>
#include <iostream>
///@file
///@brief active_t enum to track if player is tractor or harvester
enum active_t
{
    trekker = 0,
    combine = 1
};
///@brief player class to track which vehicle is being used and used by gamecontrol to move the active vehicle only
class player
{
private:
    std::array<vehicle *, 2> &vehicles;
    active_t active = trekker;

public:
    player(std::array<vehicle *, 2> &vehicles);
    ///@brief swaps vehicle
    void swapVehicle(sf::Clock &clock); // tractorOrHarvester
    ///@brief returns the pointer to active vehicle
    vehicle *getVehicle();
    ///@brief returns the pointer to inactive vehicle
    vehicle *getInactive();
    ///@brief returns the active vehicle enum
    active_t getVehicle_type();
    ///@brief returns a reference to the vehicle array
    std::array<vehicle *, 2> & getVehicles();
    ///@brief ostream operator for player prints data about player, also useful for saving
    friend std::ostream &operator<<(std::ostream &lhs, player &Player)
    {

        return lhs << " ActiveVehicle: " << ((Player.getVehicle_type() == trekker) ? "trekker" : "combine") << "@" << Player.getVehicle()->getPosition().x << "," << Player.getVehicle()->getPosition().y <<  '(' << Player.getVehicle()->getRotation() << ")" << " otherVehicle: "  
        << (Player.getVehicle_type() == trekker ? "combine" : "trekker") << "@" 
        << Player.getInactive()->getPosition().x << ',' 
        << Player.getInactive()->getPosition().y ;
    }
    ///@brief sets the active vehicle
    void setVehicle(active_t nActive);
};

#endif
