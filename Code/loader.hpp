#ifndef LOADER_HPP
#define LOADER_HPP
#include <string>
#include <vector>
#include <algorithm>
#include "player.hpp"
#include "drawable.hpp"
class loader{
private: 
public:
    loader();
    static player * loadPlayer(player * P);
    static std::vector<std::vector<dirt >>   loadFarms(std::vector<std::vector<dirt *>> );
    
};

#endif