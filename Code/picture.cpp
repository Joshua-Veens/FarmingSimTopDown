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
    if(type == "trekker"){
        sprite.setOrigin(sf::Vector2f(64,64));
    }
    window.draw(sprite);
}

void picture::move(sf::Vector2f delta) {
    position += delta;
}

void picture::setRotation( int rotation ) {
    sprite.setRotation(rotation);
    savedRotation = rotation;
}

int picture::getRotation() {
    return savedRotation;
}

sf::Vector2f picture::getPosition(){
    return position;
}