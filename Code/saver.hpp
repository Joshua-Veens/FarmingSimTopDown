#ifndef SAVER_HPP
#define SAVER_HPP
#include <array>
#include "player.hpp"
#include "dirt.hpp"
#include "inventory.hpp"
#include <string>
class saver {
private: 
    player & Player;
    std::vector<dirt *> & farmland;
public:
    saver(player & Player, std::vector<dirt*> & farmland);
    void save(std::string file);

};
#endif