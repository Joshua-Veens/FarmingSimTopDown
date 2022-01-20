#include "dirt.hpp"
#include <iostream>

void dirt::seed()
{
    if (state == unseeded)
    {

        state = seeded;
        img_file = "seeded.png";
    }
}
void dirt::update()
{
    if (ticks == wait_time && state == seeded)
    {
        ticks = 0;
        state = growing;
        img_file = "growing.png";
    }
    else if (ticks == wait_time && state == growing)
    {
        std::cout << "state: " << state << " ticks: " << ticks << std::endl;
        ticks = 0;
        state = grown;
        img_file = "grown.png";
    }
    else if (state == seeded || state == growing)
    {
        ticks += 1;
    }
}

bool dirt::harvest()
{
    if (state == grown)
    {
        state = unseeded;
        img_file = "unseeded.png";
        return true;
    }
    return false;
}

void dirt::draw(sf::RenderWindow &window)
{
    image.loadFromFile(img_file);
    texture.loadFromImage(image);
    sprite.setTexture(texture, true);
    sprite.setPosition(position);
    window.draw(sprite);
    bounds = sprite.getGlobalBounds();
}
