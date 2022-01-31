#include "inventory.hpp"

inventory::inventory(sf::Vector2f position):
    position(position)
{
    image.loadFromFile("images\\silo.png");
}

void inventory::draw(sf::RenderWindow &window) {
    sprite.setTexture(image);
    sprite.setPosition(position);
    window.draw(sprite);
}

unsigned int inventory::getWheat() {
    return wheatCount;
}

unsigned int inventory::getCorn() {
    return cornCount;
}

void inventory::removeCrops() {
    wheatCount = 0;
    cornCount = 0;
}
