#ifndef SAVER_HPP
#define SAVER_HPP
#include <array>
#include "player.hpp"
#include "dirt.hpp"
#include "inventory.hpp"
#include "tractor.hpp"
#include "marketplace.hpp"
#include "vehicle_shop.hpp"
#include <string>

///@file this file contains the class that causes the entire game to be saved
///@details saver class saves all the things that need saving
class saver {
private: 
    player & Player;
    std::vector<std::vector<dirt *>> & farmlands;
    inventory * inv;
    marketplace * Market;
    harvester * combine;
    tractor * trekker;
    vehicle_shop * VS;
public:
    ///@brief saver class constructor
    ///@param Player reference to player class
    ///@param Farmlands reference to vector farmlands, which is vecotor<vector<int>>
    ///@param inv pointer to inventory
    ///@param Market pointer to marketplace
    ///@param combine  pointer to harvester
    ///@param trekker pointer to tractor
    ///@param VS pointer to vehicleShop
    saver(player & Player, std::vector<std::vector<dirt *>> & farmlands, inventory * inv, marketplace * Market, harvester * combine, tractor * trekker,  vehicle_shop * VS);

    ///@brief saves the game
    ///@param file desired save file name
    void save(std::string file);

};
#endif
