#include "loader.hpp"
#include "base64.hpp"
#include <array>
#include <fstream>
#include <sstream>
#include <iostream>
loader::loader() {}

player *loader::loadPlayerAndMoney(player *P, marketplace * market)
{
    std::ifstream rFile("save.txt");
    std::ostringstream buffer;
    std::string temp;
    rFile >> temp;
    if(rFile.tellg()==0){
        rFile.close();
        return P;
    }
    // char ch;
    // while(rFile.get(ch)){
    //     buffer << ch;
    //     std::cout << "load";
    // }
    // std::string to_decode = buffer.str();
    std::string decoded = base64_decode(temp);
    if(decoded.size() <= 0){
        return P;
    }
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
    std::string money = player_str.substr(player_str.find("Money: ") + 7, player_str.find(" Act") - 5);
    // std::cout << player_str << std::endl;
    // std::cout << money;
    //
    int mon = std::stoi(money);
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
    market->setMoney(mon);
    P->setVehicle(active);
    rFile.close();
    return P;
}


bool str_contains(std::string str, char cmp){
    for(auto n: str){
        if(n == cmp){
            return true;
        }
    }
    return false;
}
std::vector<std::vector<dirt *>>   loader::loadFarms(std::vector<std::vector<dirt *>> farms ){
        std::ifstream rFile("save.txt");
    std::ostringstream buffer;
    std::string temp;
    rFile >> temp;
    if(rFile.tellg()==0){
        rFile.close();
        return farms;
    }
    // char ch;
    // while(rFile.get(ch)){
    //     buffer << ch;
    //     std::cout << "load";
    // }
    // std::string to_decode = buffer.str();
    std::string decoded = base64_decode(temp);
    if(decoded.size() <= 0){
        return farms;
    }
    std::string farm_strs = decoded.substr(decoded.find('!')-1, decoded.size());
    // std::cout << farm_strs;
    std::string next_term = "";
    while(!str_contains(next_term,'#')){
        std::cout << next_term << std::endl;
        farm_strs.erase(farm_strs.find('!'),farm_strs.find('!'));
        next_term = farm_strs.substr(farm_strs.find('!'),farm_strs.find('!')+1);
        
    }
    return farms;
} 