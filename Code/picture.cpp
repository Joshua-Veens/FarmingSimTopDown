#include "picture.hpp"
#include <iostream>

picture::picture( std::string filename, sf::Vector2f position, std::string type):
    filename(filename),
    position(position),
    type(type)
{image.loadFromFile(filename);}

void picture::draw(sf::RenderWindow &window) {
    sprite.setTexture(image);
    sprite.setPosition(position);
    window.draw(sprite);
}
