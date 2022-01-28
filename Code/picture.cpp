#include "picture.hpp"
#include <iostream>

picture::picture( std::string filename, sf::Vector2f position):
    filename(filename),
    position(position)
{
    image.loadFromFile(filename);
}

void picture::draw(sf::RenderWindow &window) {
    sprite.setTexture(image);
    sprite.setPosition(position);
    window.draw(sprite);
}
