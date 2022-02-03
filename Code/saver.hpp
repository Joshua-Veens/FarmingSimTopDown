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
    saver(player & Player, std::vector<std::vector<dirt *>> & farmlands, inventory * inv, marketplace * Market, harvester * combine, tractor * trekker,  vehicle_shop * VS);

    void save(std::string file);

};
#endif
