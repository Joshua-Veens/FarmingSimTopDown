#include "picture.hpp"
#include <iostream>

picture::picture( std::string filename, sf::Vector2f position):
    filename(filename),
    position(position)
{}

picture::picture() {}

void picture::draw(sf::RenderWindow &window) {
    image.loadFromFile(filename);
    sprite.setTexture(image);
    sprite.setPosition(position);
    sprite.setOrigin(sf::Vector2f(64,64));
    window.draw(sprite);
}

void picture::move(sf::Vector2f delta) {
    position += delta;
}

void picture::setRotation( int rotation ) {
    sprite.setRotation(rotation);
}