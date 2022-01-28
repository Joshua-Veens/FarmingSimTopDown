#include "switchMenu.hpp"
#include <iostream>
switchMenu::switchMenu(sf::RenderWindow &window, player &Player) : menu(window), Player(Player){
}

void switchMenu::create() {
    options.push_back(option(
            "Tractor", (sf::Vector2f)window_middle - sf::Vector2f(650, 80), [&]
            {Player.setVehicle(trekker);Player.zegActive() ;this->active = false;},
            font_file));
    options.push_back(option(
            "Harvester", (sf::Vector2f)window_middle - sf::Vector2f(650, 10), [&]
            {Player.setVehicle(combine);Player.zegActive() ;this->active = false;},
            font_file));
}
