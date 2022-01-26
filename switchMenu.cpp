#include "switchMenu.hpp"

switchMenu::switchMenu(sf::RenderWindow &window, tractor *trekker) : menu(window), trekker(trekker){
}

void switchMenu::create() {
    options.push_back(option(
            "Tractor", (sf::Vector2f)window_middle - sf::Vector2f(0, 80), [&]
            { trekker->changeToTractor();this->active = false;},
            font_file));
    options.push_back(option(
            "Seeder", (sf::Vector2f)window_middle - sf::Vector2f(0, 0), [&]
            { trekker->changeToSeeder(); this->active = false;},
            font_file));
    options.push_back(option(
            "Harvester", (sf::Vector2f)window_middle + sf::Vector2f(0, 80), [&]
            { this->active = false;},
            font_file));

}
