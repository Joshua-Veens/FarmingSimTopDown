#include "saver.hpp"
#include <fstream>
#include <sstream>

saver::saver(player &Player, std::vector<std::vector<dirt *>> &farmlands, inventory *inv, marketplace *Market) : Player(Player), farmlands(farmlands), inv(inv), Market(Market) {}

void saver::save(std::string file)
{
    std::ofstream save_file(file);
    std::stringstream buffer;
    buffer << *Market;
    buffer << Player;
    buffer << "!";
    for (auto farmland : farmlands)
    {
        for (auto Dirt : farmland)
        {
            buffer << *Dirt;
            buffer << "!";
        }
    }
    buffer << "#";
    buffer << *inv;
    std::string temp = buffer.str();
    std::string encoded = base64_encode((unsigned char *const)temp.c_str(), temp.size());
    save_file << encoded;
    save_file.close();
}
