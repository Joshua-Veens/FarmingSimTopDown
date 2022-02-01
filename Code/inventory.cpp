#include "inventory.hpp"

inventory::inventory(sf::Vector2f position):
    position(position),
    collider(position.x+172, position.y+208, 48, 43),
    blokje(sf::Vector2f(position.x+172, position.y+208), sf::Vector2f(48, 43))
{
    image.loadFromFile("images\\silo.png");
    sprite.setTexture(image);
    sprite.setPosition(position);
}

void inventory::draw(sf::RenderWindow &window) {
    window.draw(sprite);
    blokje.draw(window);
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
