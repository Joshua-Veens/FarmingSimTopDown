#include "saver.hpp"
#include <fstream>
#include <sstream>
saver::saver(player &Player, std::vector<std::vector<dirt*>> & farmlands, inventory * inv):Player(Player), farmlands(farmlands), inv(inv){}

void saver::save(std::string file){
    std::ofstream save_file(file);
    std::stringstream buffer;
    buffer << Player;
    buffer << "!";
    for(auto farmland : farmlands){
        for(auto Dirt : farmland) {
            buffer << *Dirt;
            buffer << "!";
        }
    }
    buffer << * inv;
    std::string temp = buffer.str();
    std::string encoded = base64_encode((unsigned char * const)temp.c_str(),temp.size());
    save_file << encoded;
    save_file.close();
}