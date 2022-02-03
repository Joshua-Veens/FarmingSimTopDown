#include "loader.hpp"
#include "base64.hpp"
#include <array>
#include <fstream>
#include <sstream>
#include <iostream>
loader::loader() {}

player *loader::loadPlayerAndMoney(player *P, marketplace *market)
{
    std::ifstream rFile("save.txt");
    std::ostringstream buffer;
    std::string temp;
    rFile >> temp;
    if (rFile.tellg() == 0)
    {
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
    if (decoded.size() <= 0)
    {
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
    double mon = std::stof(money);
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

bool str_contains(std::string str, char cmp)
{
    for (auto n : str)
    {
        if (n == cmp)
        {
            return true;
        }
    }
    return false;
}
std::vector<std::vector<dirt *>> loader::loadFarms(std::vector<std::vector<dirt *>> farms)
{
    std::ifstream rFile("save.txt");
    std::ostringstream buffer;
    std::string temp;
    rFile >> temp;
    if (rFile.tellg() == 0)
    {
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
    if (decoded.size() <= 0)
    {
        return farms;
    }
    std::string farm_strs = decoded.substr(decoded.find_first_of('!'), decoded.size());
    std::ofstream log("log.txt");
    std::string next_term = farm_strs.substr(0, 39);
    // log << next_term;
    std::vector<std::string> strings;
    strings.push_back(next_term);
    //farm_strs.erase(0, 38);
    while (!str_contains(next_term, '#'))
    {
        farm_strs.erase(farm_strs.find('!'), farm_strs.find('!')+1);
        // std::cout << next_term << std::endl;
        next_term = farm_strs.substr(farm_strs.find('!'), farm_strs.find('!') + 1);
        strings.push_back(next_term);
    }
    int i = 0;
    if (strings[0].size() < 5)
    {
    }
    // strings.erase(strings.begin()+1);
    std::vector<std::vector<int>> parsed = {};
    for (auto str : strings)
    {
        log << str << std::endl;
        std::vector<int> one_dirt = {};
        std::string temp;
        str.erase(0, 6);
        str.erase(0, str.find_first_not_of('0'));
        std::string x_str = str.substr(0, str.find_first_of(','));
        int x = std::atoi(x_str.c_str());
        // if(x == 0){
        //     std::cout << x_str << " ";
        //     std::cout << "Zero@" << i << std::endl;
        // }
        one_dirt.push_back(x);
        str.erase(0, str.find_first_of(',') + 1);
        str.erase(0, str.find_first_not_of('0'));
        std::string y_str = str.substr(0, str.find_first_of(' '));
        int y = std::atoi(y_str.c_str());
        one_dirt.push_back(y);
        str.erase(0, str.find_first_of('=') + 1);
        int state = atoi(str.substr(0, str.find_first_of(' ')).c_str());
        one_dirt.push_back(state);
        str.erase(0, str.find_first_of('=') + 1);
        int crop = atoi(str.substr(0, str.find_first_of('c')).c_str());
        one_dirt.push_back(crop);
        str.erase(0, str.find_first_of('=') + 1);
        int owned = atoi(str.substr(0, str.find_first_of('!')).c_str());
        one_dirt.push_back(owned);
        str.erase(0, str.find_first_of('!') + 1);
        i++;
        parsed.push_back(one_dirt);
    }

    int j = 0;
    for (auto x : farms)
    {
        int field = 1;
        if (x.size() <= 0)
        {
            continue;
        }
        for (auto y : x)
        {
            y->setPosition(sf::Vector2f(parsed[j][0], parsed[j][1]));
            if (parsed[j][3] == 1)
            {
                // std::cout << "corn" << std::endl;
                y->changeToCorn();
            }
            else if (parsed[j][3] == 0)
            {
                // std::cout << "wheat" << std::endl;
                y->changeToWheat();
            }
            else if (parsed[j][3] == 2)
            {
                // std::cout << "weed" << std::endl;
                y->changeToWeed();
            }
            y->setState((dirt::state_t)parsed[j][2]);

            if (parsed[j][4] == 1)
            {
                y->setToOwned();
            }
            // std::cout << parsed[j][4];
            j++;
        }
        field++;
    }
    return farms;
}


inventory *loader::loadSilo(inventory *silo)
{
    std::ifstream rFile("save.txt");
    std::ostringstream buffer;
    std::string temp;
    rFile >> temp;
    if (rFile.tellg() == 0)
    {
        rFile.close();
        return silo;
    }
    // char ch;
    // while(rFile.get(ch)){
    //     buffer << ch;
    //     std::cout << "load";
    // }
    // std::string to_decode = buffer.str();
    std::string decoded = base64_decode(temp);
    if (decoded.size() <= 0)
    {
        return silo;
    }
    std::string inv_str = decoded.substr(decoded.find('#'), decoded.size());
    std::string wheat_str = inv_str.substr(inv_str.find_first_of(' '), inv_str.find_first_of(' '));
    int wheatc = atoi(wheat_str.c_str());
    inv_str.erase(0, inv_str.find_first_of(' '));
    inv_str.erase(0, inv_str.find_first_of(' '));
    inv_str.erase(0, inv_str.find_first_of('C'));
    inv_str.erase(0, inv_str.find_first_of(' '));
    int cornc = atoi(inv_str.c_str());
    silo->setWheat(wheatc);
    silo->setCorn(cornc);
    return silo;
}

