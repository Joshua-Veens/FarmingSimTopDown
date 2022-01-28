#include "saver.hpp"
#include <fstream>

saver::saver(player &Player, std::vector<dirt*> & farmland):Player(Player), farmland(farmland){}

void saver::save(std::string file){
    std::ofstream save_file(file);
    save_file << Player;
    for(auto Dirt : farmland){
        auto _dirt  = *Dirt;
        save_file << _dirt;
    }
    save_file.close();
}