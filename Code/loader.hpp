#ifndef LOADER_HPP
#define LOADER_HPP
#include <string>
#include <vector>
#include <algorithm>
#include "player.hpp"
#include "drawable.hpp"
#include "marketplace.hpp"
class loader{
private: 
public:
    loader();
    static player * loadPlayerAndMoney(player * P, marketplace * market);
    static std::vector<std::vector<dirt *>>   loadFarms(std::vector<std::vector<dirt *>> );
    inventory * loadSilo(inventory * silo);

};

#endif
