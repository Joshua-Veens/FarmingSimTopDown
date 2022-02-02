#include "loader.hpp"
#include "base64.hpp"
#include <array>
#include <fstream>
#include <sstream>
#include <iostream>
loader::loader() {}

player *loader::loadPlayer(player *P)
{
    std::ifstream rFile("save.txt");
    std::ostringstream buffer;
    std::string temp;
    rFile >> temp;
    // if(temp == "         "){
    //     return objects;
    // }
    // char ch;
    // while(rFile.get(ch)){
    //     buffer << ch;
    //     std::cout << "load";
    // }
    // std::string to_decode = buffer.str();
    std::string decoded = base64_decode(temp);
    std::string player_str = decoded.substr(0, decoded.find("!"));
    // std::cout << player_str;
    std::string activeVehicle = player_str.substr(player_str.find("e: ") + 3, player_str.find(" oth") - 27);
    // std::cout << activeVehicle;
    std::string name = activeVehicle.substr(0, activeVehicle.find("@"));
    // std::cout << name;
    active_t active;
    if (name == "trekker")
    {
        active = trekker;
    }
    else
    {
        active = combine;
    }
    // std::cout << active;
    std::string money = player_str.substr(player_str.find(": ") + 2, player_str.find(" Act") - 7);
    int mon = std::stoi(money);
    int mon1 = mon;
    mon = mon1;
    std::string active_pos = activeVehicle.substr(activeVehicle.find("@") + 1, activeVehicle.size());
    std::string x_str = active_pos.substr(0, active_pos.find(","));
    std::string y_str = active_pos.substr(active_pos.find(",") + 1, active_pos.size());
    sf::Vector2f location_active(sf::Vector2f(stoi(x_str), stoi(y_str)));
    if (active == trekker)
    {
        P->getVehicles()[trekker]->setPosition(location_active);
    }
    else
    {
        P->getVehicles()[combine]->setPosition(location_active);
    }
    // std::cout << player_str;
    std::string otherVehicle = player_str.substr(player_str.find("otherVehicle: ") + 14, player_str.size());
    // std::cout << otherVehicle;
    std::string inactive_pos = otherVehicle.substr(otherVehicle.find("@") + 1, otherVehicle.size());
    std::string x_str_off = inactive_pos.substr(0, inactive_pos.find(","));
    std::string y_str_off = inactive_pos.substr(inactive_pos.find(",") + 1, inactive_pos.size());
    sf::Vector2f location_inactive(sf::Vector2f(stoi(x_str_off), stoi(y_str_off)));
    if (active == trekker)
    {
        P->getVehicles()[combine]->setPosition(location_inactive);
    }
    else
    {
        P->getVehicles()[trekker]->setPosition(location_inactive);
    }
    P->setMoney(mon);
    P->setVehicle(active);
    return P;
}