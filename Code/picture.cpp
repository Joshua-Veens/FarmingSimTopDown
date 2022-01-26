#include "picture.hpp"
#include <iostream>

picture::picture( std::string filename, sf::Vector2f position, std::string type):
    filename(filename),
    position(position),
    type(type)
{}

picture::picture() {}

void picture::draw(sf::RenderWindow &window) {
    image.loadFromFile(filename);
    sprite.setTexture(image);
    sprite.setPosition(position);
    window.draw(sprite);
}
