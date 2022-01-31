//
// Created by joshu on 28-1-2022.
//

#include "marketplace.hpp"
#include "iostream"

marketplace::marketplace(sf::RenderWindow & window, saver save, class inventory * inv):
    menu(window, save),
    inv(inv)
{}


void marketplace::sellAll() {
    money += inv->getWheat() /100 * 27;
    money += inv->getCorn() / 100 * 40;
    inv->removeCrops();
    std::cout << money << "\n";
}

void marketplace::create() {
    options.clear();
    options.push_back(option(
            std::to_string(inv->getWheat()), (sf::Vector2f)window_middle - sf::Vector2f(840, 220), [&]
            { },
            font_file));
    options.push_back(option(
            std::to_string(inv->getCorn()), (sf::Vector2f)window_middle - sf::Vector2f(840, 150), [&]
            { },
            font_file));
    options.push_back(option(
            "$ " + std::to_string(money), (sf::Vector2f)window_middle - sf::Vector2f(580, 220), [&]
            { },
            font_file));
    options.push_back(option(
            "Sell all crops", (sf::Vector2f)window_middle - sf::Vector2f(580, 150), [&]
            { sellAll();},
            font_file));
    options.push_back(option(
            "Close", (sf::Vector2f)window_middle - sf::Vector2f(580, 80), [&]
            { this->active = false;},
            font_file));
}
