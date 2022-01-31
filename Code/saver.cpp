#include "saver.hpp"
#include <fstream>
#include <sstream>
saver::saver(player &Player, std::vector<dirt*> & farmland):Player(Player), farmland(farmland){}

void saver::save(std::string file){
    std::ofstream save_file(file);
    std::stringstream buffer;
    buffer << Player;
    buffer << "!";
    for(auto Dirt : farmland){
        auto _dirt  = *Dirt;
        buffer << _dirt;
        buffer << "!";
    }
    std::string temp = buffer.str();
    std::string encoded = base64_encode((unsigned char * const)temp.c_str(),temp.size());
    save_file << encoded;
    save_file.close();
}