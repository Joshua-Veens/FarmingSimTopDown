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
class loader{
private: 
public:
    loader();
    static player * loadPlayerAndMoney(player * P, marketplace * market);
    static std::vector<std::vector<dirt *>>   loadFarms(std::vector<std::vector<dirt *>> );
    inventory * loadSiloAndVehicles(inventory * silo, tractor * Trekker, harvester * Combine, vehicle_shop * VS);

};

#endif
