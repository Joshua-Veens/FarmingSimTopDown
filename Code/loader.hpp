#ifndef LOADER_HPP
#define LOADER_HPP
#include <string>
#include <vector>
#include <algorithm>
#include "player.hpp"
#include "drawable.hpp"
#include "marketplace.hpp"
#include "tractor.hpp"
#include "vehicle_shop.hpp"
///@file contains the loader class
///@details loads the entire game  from a save file
class loader{
private: 
public:
    ///@brief loader constructor, doesn't take any parameters
    loader();
    ///@brief loads player and money into player and market
    ///@param P pointer to player
    ///@param market pointer to market
    static player * loadPlayerAndMoney(player * P, marketplace * market);
    ///@brief loads all the farmlands
    ///@param farms vector of vectors containing dirt
    static std::vector<std::vector<dirt *>>   loadFarms(std::vector<std::vector<dirt *>> farms );
    ///@brief loads the silo and the vehicles
    ///@param silo pointer to inventory
    ///@param Trekker pointer to tractor
    ///@param Combine pointer to harvester
    ///@param VS pointer to vehicleShop
    inventory * loadSiloAndVehicles(inventory * silo, tractor * Trekker, harvester * Combine, vehicle_shop * VS);

};

#endif
