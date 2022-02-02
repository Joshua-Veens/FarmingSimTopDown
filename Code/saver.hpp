#ifndef SAVER_HPP
#define SAVER_HPP
#include <array>
#include "player.hpp"
#include "dirt.hpp"
#include "inventory.hpp"
#include "marketplace.hpp"
#include <string>
class saver {
private: 
    player & Player;
    std::vector<std::vector<dirt *>> & farmlands;
    inventory * inv;
    marketplace * Market;
public:
    saver(player & Player, std::vector<std::vector<dirt *>> & farmlands, inventory * inv, marketplace * Market);

    void save(std::string file);

};
#endif