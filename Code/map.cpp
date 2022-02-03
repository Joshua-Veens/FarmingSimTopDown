//
// Created by joshu on 3-2-2022.
//

#include "map.hpp"

map::map(sf::RenderWindow &window, saver &Save) : menu(window,Save)
{}

void map::create()
{
    options.push_back(option(
            "Close", (sf::Vector2f)window_middle + sf::Vector2f(700, 340), [this]
            { active = false; },
            font_file));
}